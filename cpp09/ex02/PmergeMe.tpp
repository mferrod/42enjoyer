template <typename Iterator, typename T>
Iterator myLowerBound(Iterator first, Iterator last, const T& value)
{
    while (first != last)
	{
        if (*first >= value)
            return first;
        ++first;
    }
    return last;
}

template <typename Container>
void insertWithJacobsthal(Container& main, const Container& pendings)
{
    std::vector<size_t> order = jacobsthalIndices(pendings.size());
    std::vector<typename Container::value_type> pendVec(pendings.begin(), pendings.end());
    for (size_t i = 0; i < order.size(); ++i)
	{
        size_t idx = order[i];
        if (idx >= pendVec.size())
			continue;
        int val = pendVec[idx];
        typename Container::iterator pos = myLowerBound(main.begin(), main.end(), val);
        main.insert(pos, val);
    }
}

template <typename Container>
void fordJohnsonSort(Container& data)
{
    if (data.size() <= 1)
		return;
    Container main, pendings;
    typename Container::iterator it = data.begin();
    while (it != data.end())
	{
        int first = *it;
        ++it;
        if (it != data.end())
		{
            int second = *it;
            if (first < second)
			{
                main.push_back(second);
                pendings.push_back(first);
            }
			else
			{
                main.push_back(first);
                pendings.push_back(second);
            }
            ++it;
        }
		else
            main.push_back(first);
    }
    fordJohnsonSort(main);
    insertWithJacobsthal(main, pendings);
    data = main;
}