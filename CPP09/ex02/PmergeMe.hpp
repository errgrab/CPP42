#pragma once

#include <vector>
#include <list>
#include <string>

class PmergeMe {
private:
	template <typename Container>
	void PmergeMeSort(Container &c) {
		// nn tem sort
		if (c.size() <= 1) return;
		// criar pares
		typedef typename Container::iterator It;
		std::vector< std::pair<int, int> > pairs;
		It it = c.begin();
		while (it != c.end()) {
			int first = *it++;
			if (it != c.end()) {
				int second = *it++;
				if (first > second)
					std::swap(first, second);
				pairs.push_back(std::make_pair(first, second));
			} else {
				pairs.push_back(std::make_pair(first, -1));
			}
		}
		// maiores e menores
		Container bigger, smaller;
		for (size_t i = 0; i < pairs.size(); i++) {
			bigger.push_back(pairs[i].second != -1 ? pairs[i].second : pairs[i].first);
			if (pairs[i].second != -1) smaller.push_back(pairs[i].first);
		}
		// ordenar maiores
		PmergeMeSort(bigger);
		// inserir os menores
		for (It sit = smaller.begin(); sit != smaller.end(); ++sit) {
			typename Container::iterator pos = bigger.begin();
			while (pos != bigger.end() && *pos < *sit)
				++pos;
			bigger.insert(pos, *sit);
		}
		c = bigger;
	}
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	void sortAndPrint(std::vector<int> &vec, std::list<int> &lst);
};