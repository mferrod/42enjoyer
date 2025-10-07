#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	bool evaluate(const std::string &expr, double &outResult) const;

private:
	bool isOperator(char c) const;
	double applyOp(double a, double b, char op) const;
};

#endif
