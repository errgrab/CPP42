#pragma once
#include <stack>
#include <string>

class RPN {
private:
	std::stack<int> _stack;

	bool isOperator(const std::string &token) const;
	int applyOperation(const std::string &op, const int a, const int b) const;

public:
	RPN();
	RPN(std::stack<int> stk);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int eval(const std::string &expr);
};
