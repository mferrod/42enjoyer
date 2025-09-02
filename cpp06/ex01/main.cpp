#include "Serializer.hpp"

int main(void) {
	Data data;
	data.value = 42;

	uintptr_t serializer = Serializer::serialize(&data);
	std::cout << "Pointer to number: " << serializer << std::endl;

	Data *ptr = Serializer::deserialize(serializer);
	std::cout << "Number to pointer: " << ptr->value << std::endl;

	return 0;
}