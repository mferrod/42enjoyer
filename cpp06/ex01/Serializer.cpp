#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer() {
    std::cout << "Serializer Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other) {
    std::cout << "Serializer Copy Constructor called" << std::endl;
        if (this != &other) {
        *this = other;
    }
}

Serializer::~Serializer() {
    std::cout << "Serializer Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    return (*this);
}
