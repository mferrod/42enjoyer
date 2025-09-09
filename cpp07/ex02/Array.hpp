#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>     // size_t
#include <exception>   // std::exception

template <typename T>
class Array {
private:
    T*     _data;
    size_t _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);

    size_t size() const;
    T &operator[](int index);
    const T &operator[](int index) const;

    class IndexOutOfBounds : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"

#endif // ARRAY_HPP
