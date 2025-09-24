#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <stdexcept>

class Span
{
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

#endif