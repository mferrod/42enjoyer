#include "Span.hpp"
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <iostream>

Span::Span() : _maxSize(0) {
	std::cout << "Default Constructor Span created" << std::endl;
	_numbers.reserve(0);
}

Span::Span(unsigned int n) : _maxSize(n) {
	std::cout << "Parametric Constructor Span created" << std::endl;
	_numbers.reserve(n);
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {
	std::cout << "Copy Constructor Span created" << std::endl;
	_numbers.reserve(_maxSize);
}

Span& Span::operator=(const Span& other) {
	std::cout << "Assignment Operator Span created" << std::endl;
	if (this != &other) {
		_numbers = other._numbers;
		_maxSize = other._maxSize;
		_numbers.reserve(_maxSize);
	}
	return *this;
}

Span::~Span() {
	std::cout << "Destructor Span called" << std::endl;
}

void Span::addNumber(int num) {
	if (_numbers.size() >= _maxSize) {
		throw std::runtime_error("Span is full");
	}
	_numbers.push_back(num);
}

int Span::shortestSpan() {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	int minNum = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
	return maxNum - minNum;
}