#pragma once
#include <vector>
#include <list>
#include <string>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::list<int> _list;

	void mergeInsertSortVector(std::vector<int> &v);
	void mergeInsertSortList(std::list<int> &l);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void addNumber(const std::string &token);
	void sortAndDisplay();
};
