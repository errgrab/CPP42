#pragma once
#include <stack>
#include <string>

class RPN {
private:
	std::stack<float> _stack;

	bool isOperator(const std::string &token) const;
	float applyOperation(const std::string &op, const float a, const float b) const;

public:
	RPN();
	RPN(std::stack<float> stk);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	float eval(const std::string &expr);
};
