#include "PmergeMe.hpp"

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }

    try
    {
        std::vector<int> input = parseInput(argc, argv);

        std::cout << "Before: ";
        for (size_t i = 0; i < input.size(); ++i)
        {
            std::cout << input[i];
            if (i + 1 < input.size())
                std::cout << " ";
        }
        std::cout << std::endl;

        std::vector<int> vec(input.begin(), input.end());
        std::list<int> lst(input.begin(), input.end());

        std::clock_t start_vec = std::clock();
        fordJohnsonSort<std::vector<int> >(vec);
        std::clock_t end_vec = std::clock();

        std::clock_t start_lst = std::clock();
        fordJohnsonSort<std::list<int> >(lst);
        std::clock_t end_lst = std::clock();

        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i];
            if (i + 1 < vec.size())
                std::cout << " ";
        }
        std::cout << std::endl;

        double time_vec = double(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
        double time_lst = double(end_lst - start_lst) / CLOCKS_PER_SEC * 1e6;

        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
        std::cout << "Time to process a range of " << input.size() << " elements with std::list   : " << time_lst << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
