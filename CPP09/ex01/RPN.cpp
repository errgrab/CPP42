#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(std::stack<int> stk) : _stack(stk) {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperation(const std::string &op, const int a, const int b) const {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/" && b != 0) return a / b;
	else if (op == "/" && b == 0) throw std::runtime_error("Error");
	throw std::runtime_error("Error");
}

int RPN::eval(const std::string &expr) {
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			_stack.push(applyOperation(token, a, b));
		} else {
			if (token.size() != 1 || !isdigit(token[0]))
				throw std::runtime_error("Error");
			_stack.push(token[0] - '0');
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}
