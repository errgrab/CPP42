#pragma once

#include <vector>
#include <list>
#include <string>
#include <algorithm> // lower_bound

class PmergeMe {
private:
	template <class C>
	static typename C::value_type _maxv(typename C::value_type a, typename C::value_type b) {
		return (b < a) ? a : b;
	}

	template <class C>
	static typename C::value_type _minv(typename C::value_type a, typename C::value_type b) {
		return (b < a) ? b : a;
	}

	template <class C>
	static size_t _count_occ(const C& cont, const typename C::value_type& V) {
		size_t k = 0;
		for (typename C::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			if (*it == V) ++k;
		}
		return k;
	}

	template <class C>
	static typename C::value_type _get_lo_for(const C& src, const typename C::value_type& H, size_t occ) {
		typedef typename C::value_type T;
		size_t seen = 0;
		typename C::const_iterator it = src.begin();
		while (it != src.end()) {
			T a = *it; ++it;
			if (it != src.end()) {
				T b = *it; ++it;
				T hi = _maxv<C>(a, b), lo = _minv<C>(a, b);
				if (hi == H) {
					if (seen == occ) return lo;
					++seen;
				}
			}
		}
		return H;
	}

	template <class C>
	static typename C::iterator _nth_hi(C& cont, const typename C::value_type& H, size_t nth) {
		typename C::iterator first = std::lower_bound(cont.begin(), cont.end(), H);
		if (first == cont.end() || *first != H) return cont.end();
		std::advance(first, nth);
		if (first == cont.end() || *first != H) return cont.end();
		return first;
	}

	template <class C>
	static typename C::iterator _get_nth(C& cont, size_t n) {
		typename C::iterator it = cont.begin();
		std::advance(it, n);
		return it;
	}

	template <class C>
	void PmergeMeSort(C& c){
		if(c.size() < 2) return;
		typedef typename C::value_type T;

		C src = c;
		size_t n = src.size();
		bool has_stray = n % 2;
		T stray_val = has_stray ? *--src.end() : T();

		C mainc;
		typename C::iterator it = src.begin();
		while (it != src.end()) {
			T a = *it; ++it;
			if (it != src.end()) {
				T b = *it; ++it;
				mainc.push_back(_maxv<C>(a, b));
			} else {
				mainc.push_back(a);
			}
		}

		PmergeMeSort(mainc);
		C mainHighs = mainc;

		C pend_partners;
		it = mainHighs.begin();
		while (it != mainHighs.end()) {
			T h = *it;
			typename C::iterator first = it;
			typename C::iterator group_end = first;
			while (group_end != mainHighs.end() && *group_end == h) ++group_end;
			size_t multi = 0;
			typename C::iterator dit = first;
			while (dit != group_end) { ++dit; ++multi; }
			size_t avail = multi - (has_stray && stray_val == h ? 1 : 0);
			for (size_t i = 0; i < avail; ++i) {
				pend_partners.push_back(h);
			}
			it = group_end;
		}

		size_t m = n / 2;
		if (m == 0) {
			c = mainc;
			return;
		}

		C usedHis;
		{
			size_t idx = 0;
			typename C::iterator pit = _get_nth(pend_partners, idx);
			T h = *pit;
			size_t occ = _count_occ(usedHis, h);
			T lo = _get_lo_for(src, h, occ);
			typename C::iterator partner = _nth_hi(mainc, h, occ);
			typename C::iterator pos = std::lower_bound(mainc.begin(), partner, lo);
			mainc.insert(pos, lo);
			usedHis.push_back(h);
		}

		size_t inserted = 1, j0 = 0, j1 = 1;
		while (inserted < m) {
			size_t j2 = j1 + 2 * j0;
			size_t start = j1, stop = (j2 < m ? j2 : m);
			for (size_t i = stop; i > start; --i) {
				size_t idx = i - 1;
				typename C::iterator pit = _get_nth(pend_partners, idx);
				T h = *pit;
				size_t occ = _count_occ(usedHis, h);
				T lo = _get_lo_for(src, h, occ);
				typename C::iterator partner = _nth_hi(mainc, h, occ);
				typename C::iterator pos = std::lower_bound(mainc.begin(), partner, lo);
				mainc.insert(pos, lo);
				usedHis.push_back(h);
				++inserted;
				if (inserted >= m) break;
			}
			j0 = j1; j1 = j2;
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
