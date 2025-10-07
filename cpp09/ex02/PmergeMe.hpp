#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <ctime>

std::vector<int> parseInput(int argc, char** argv);

std::vector<size_t> jacobsthalIndices(size_t n);

template <typename Container>
void fordJohnsonSort(Container& data);

template <typename Container>
void insertWithJacobsthal(Container& main, const Container& pendings);

template <typename Iterator, typename T>
Iterator myLowerBound(Iterator first, Iterator last, const T& value);

#include "PmergeMe.tpp"

#endif