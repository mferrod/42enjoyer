#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n) {
    if (n == 0) {
        _data = NULL;
    } else {
        _data = new T[n]();
    }
}

template <typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size) {
    if (_size) {
        _data = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete [] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        T* newData = NULL;
        if (other._size) {
            newData = new T[other._size];
            for (size_t i = 0; i < other._size; ++i)
                newData[i] = other._data[i];
        }
        delete [] _data;
        _data = newData;
        _size = other._size;
    }
    return *this;
}

template <typename T>
size_t Array<T>::size() const { return _size; }

template <typename T>
T &Array<T>::operator[](int index) {
    if (index < 0 || static_cast<size_t>(index) >= _size)
        throw typename Array<T>::IndexOutOfBounds();
    return _data[index];
}

template <typename T>
const T &Array<T>::operator[](int index) const {
    if (index < 0 || static_cast<size_t>(index) >= _size)
        throw typename Array<T>::IndexOutOfBounds();
    return _data[index];
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() { return "Index out of bounds"; }

#endif
