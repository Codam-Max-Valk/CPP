#include "Base.hpp"

Base::~Base(){};

Base *generate(void){
	int random = rand() % 3;
	switch (random) {
		case 0:
			if (DEBUG)
				std::cout << "A generated" << std::endl;
			return new A();
		case 1:
			if (DEBUG)
				std::cout << "B generated" << std::endl;
			return new B();
		default:
			if (DEBUG)
				std::cout << "C generated" << std::endl;
			return new C();
	}
}

void identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p){
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}
