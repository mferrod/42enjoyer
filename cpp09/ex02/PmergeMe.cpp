#include "PmergeMe.hpp"

std::vector<size_t> jacobsthalIndices(size_t n)
{
    std::vector<size_t> indices;
    if (n == 0)
        return indices;
    indices.push_back(0);
    size_t j1 = 1, j2 = 1;
    while (j2 < n)
    {
        indices.push_back(j2);
        size_t next = j2 + 2 * j1;
        j1 = j2;
        j2 = next;
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    }
    return indices;
}

std::vector<int> parseInput(int argc, char** argv)
{
    std::vector<int> result;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        int num;
        std::istringstream iss(arg);
        if (!(iss >> num) || !iss.eof() || num < 0)
        {
            throw std::invalid_argument("Error: invalid input: " + arg);
        }
        result.push_back(num);
    }
    return result;
}