#include "iter.hpp"

Iter::Iter() {
  std::cout << "Iter Constructor called" << std::endl;
}

Iter::Iter(const Iter &other) {
  std::cout << "Iter Copy Constructor called" << std::endl;
  if (this != &other) {
    *this = other;
  }
}

Iter::~Iter() {
  std::cout << "Iter Destructor called" << std::endl;
}

Iter &Iter::operator=(const Iter &other) {
  (void)other;
  return (*this);
}
