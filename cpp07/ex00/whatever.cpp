#include "whatever.hpp"

Whatever::Whatever() {

}

Whatever::~Whatever() {

}

Whatever &Whatever::operator=(const Whatever &other) {
    (void)other;
    return (*this);
}



template <typename T> t const &max(t const &a, t const &b) {
  return (a > b ? a : b);
}

template <typename T> t const &min(t const &a, t const &b) {
  return (a < b ? a : b);
}

template <typename T> void swap(t &a, t &b) {
  t tmp = a;
  a = b;
  b = tmp;
}