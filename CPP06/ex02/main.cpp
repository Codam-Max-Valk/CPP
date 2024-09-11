#include "Base.hpp"

int main(){
	srand(time(NULL));

	for (int i = 0; i < 10; i++){
		std::cout << "Test " << i + 1 << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << "Test 11" << std::endl;
	Base *base = new Base();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
