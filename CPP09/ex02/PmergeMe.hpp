#pragma once

#include <vector>
#include <list>
#include <string>
#include <algorithm> // lower_bound

class PmergeMe {
private:
	template <class C>
	static typename C::value_type _maxv(typename C::value_type a, typename C::value_type b){ return (b<a)?a:b; }
	template <class C>
	static typename C::value_type _minv(typename C::value_type a, typename C::value_type b){ return (b<a)?b:a; }

	template <class C>
	static size_t _count_lo_total(const C& src){
		size_t cnt = 0;
		typename C::const_iterator it = src.begin();
		while (it != src.end()) {
			++it;
			if (it == src.end()) break;
			++cnt; ++it;
		}
		return cnt;
	}

	template <class C>
	static size_t _count_lo_for_hi(const C& src, const typename C::value_type& H){
		typedef typename C::value_type T;
		size_t cnt=0; typename C::const_iterator it=src.begin();
		while(it!=src.end()){ T a=*it++; if(it!=src.end()){ T b=*it++; if(_maxv<C>(a,b)==H) ++cnt; } }
		return cnt;
	}

	template <class C>
	static size_t _count_occ(const C& cont, const typename C::value_type& V){
		size_t k=0; for(typename C::const_iterator it=cont.begin(); it!=cont.end(); ++it) if(*it==V) ++k; return k;
	}

	template <class C>
	static typename C::value_type _get_lo_for(const C& src, const typename C::value_type& H, size_t occ){
		typedef typename C::value_type T;
		size_t seen=0; typename C::const_iterator it=src.begin();
		while(it!=src.end()){
			T a=*it++; if(it!=src.end()){ T b=*it++; T hi=_maxv<C>(a,b), lo=_minv<C>(a,b);
				if(hi==H){ if(seen==occ) return lo; ++seen; }
			}
		}
		return H; // safe default
	}

	template <class C>
	static typename C::iterator _nth_hi(C& cont, const typename C::value_type& H, size_t nth){
		size_t k=0; for(typename C::iterator it=cont.begin(); it!=cont.end(); ++it) if(*it==H){ if(k==nth) return it; ++k; }
		return cont.end();
	}

	template <class C>
	static typename C::value_type _pend_hi_at(const C& mainHighs, const C& src, size_t idx){
		typedef typename C::value_type T;
		C usedPrefix; size_t produced=0;
		for(typename C::const_iterator it=mainHighs.begin(); it!=mainHighs.end(); ++it){
			const T& h=*it;
			size_t avail=_count_lo_for_hi(src,h), used=_count_occ(usedPrefix,h);
			if(used<avail){
				if(produced==idx) return h;
				usedPrefix.push_back(h); ++produced;
			}
		}
		return *mainHighs.begin(); // safe default
	}

	template <class C>
	void PmergeMeSort(C& c){
		typedef typename C::value_type T;
		if(c.size()<2) return;

		C src=c;

		// 1) construir cadeia principal com os 'hi' dos pares
		C mainc;
		{
			typename C::iterator it=src.begin();
			while(it!=src.end()){
				T a=*it++; 
				if (it!=src.end()) { 
					T b=*it++; 
					mainc.push_back(_maxv<C>(a,b));
				}
				else
					mainc.push_back(a);
			}
		}

		// 2) ordenar recursivamente só os 'hi' (sem sort)
		PmergeMeSort(mainc);

		// 3) manter uma cópia dos highs (fixa) para indexar pendências
		C mainHighs = mainc;

		// 4) inserir 'lo' em ordem Jacobsthal, cada um até seu parceiro 'hi'
		size_t m = _count_lo_total(src);
		if(m){
			C usedHis; // histórico dos 'hi' já processados (para lidar com duplicatas)
			// primeiro índice 0
			{
				T h = _pend_hi_at(mainHighs, src, 0);
				size_t occ = _count_occ(usedHis,h);
				T lo = _get_lo_for(src, h, occ);
				typename C::iterator partner = _nth_hi(mainc, h, occ);
				typename C::iterator pos = std::lower_bound(mainc.begin(), partner, lo);
				mainc.insert(pos, lo);
				usedHis.push_back(h);
			}
			// blocos Jacobsthal: (J_{k-1}, J_k] em ordem reversa
			size_t inserted=1, j0=0, j1=1;
			while(inserted<m){
				size_t j2 = j1 + 2*j0;
				size_t start=j1, stop=(j2<m?j2:m);
				for(size_t i=stop; i>start; --i){
					size_t idx=i-1;
					T h = _pend_hi_at(mainHighs, src, idx);
					size_t occ = _count_occ(usedHis,h);
					T lo = _get_lo_for(src, h, occ);
					typename C::iterator partner = _nth_hi(mainc, h, occ);
					typename C::iterator pos = std::lower_bound(mainc.begin(), partner, lo);
					mainc.insert(pos, lo);
					usedHis.push_back(h);
					++inserted; if(inserted>=m) break;
				}
				j0=j1; j1=j2;
			}
		}

		c = mainc;
	}
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	void sortAndPrint(std::vector<int> &vec, std::list<int> &lst);
};