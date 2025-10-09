#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {
	std::cout << "RPN Constructor called" << std::endl;
}
RPN::~RPN() {
	std::cout << "RPN Destructor called" << std::endl;
}
RPN::RPN(const RPN &other) {
	std::cout << "RPN Copy Constructor called" << std::endl;
	(void)other; 
}
RPN &RPN::operator=(const RPN &other) {
	std::cout << "RPN Assignment Operator called" << std::endl;
	(void)other;
	return *this;
}

bool RPN::isOperator(char c) const {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPN::applyOp(double a, double b, char op) const {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') {
		if (b == 0) {
			return 0;
		}
		return a / b;
	}
	return 0;
}

bool RPN::evaluate(const std::string &expr, double &outResult) const {
	std::istringstream iss(expr);
	std::string token;
	std::stack<double> st;

	while (iss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
			if (st.size() < 2) return false;
			double b = st.top();
			st.pop();
			double a = st.top(); 
			st.pop();
			if (token[0] == '/' && b == 0)
				return false;
			double res = applyOp(a, b, token[0]);
			st.push(res);
		} else {
			char *endptr = NULL;
			double val = strtod(token.c_str(), &endptr);
			if (endptr == token.c_str() || *endptr != '\0') return false;
			st.push(val);
		}
	}

	if (st.size() != 1) return false;
	outResult = st.top();
	return true;
}
