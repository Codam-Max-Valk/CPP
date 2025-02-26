#include "Serializer.hpp"
#include <sys/types.h>

int main() {
	Data data;
	Data *re_data;
	uintptr_t ptr;

	data.id = 'i';
	data.name = "fake name";
	data.value = "real name";

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Original id: " << data.id << std::endl;
	std::cout << "Original name: " << data.name << std::endl;
	std::cout << "Original value: " << data.value << std::endl;

	ptr = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << ptr << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	re_data = Serializer::deserialize(ptr);
	if (re_data == &data) {
		std::cout << "Deserialized pointer: " << re_data << std::endl;
		std::cout << "Deserialized id: " << re_data->id << std::endl;
		std::cout << "Deserialized name: " << re_data->name << std::endl;
		std::cout << "Deserialized value: " << re_data->value << std::endl;
	}
	else {
		std::cout << "Deserialization failed" << std::endl;
	}
	
	return 0;
}
