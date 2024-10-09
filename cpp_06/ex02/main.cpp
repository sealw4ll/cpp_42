#include "Identify.hpp"

int main()
{
	Base* instance = generate();
	identify(instance);
	identify(*instance);
	delete instance;
	
	return 0;
}