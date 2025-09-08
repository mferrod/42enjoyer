#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

class Iter {
public:
	Iter();
	Iter(const Iter &other);
	~Iter();
	Iter &operator=(const Iter &other);
};
#endif