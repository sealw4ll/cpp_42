#include "Identify.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		cout << "class A pointer" << endl;
	else if (dynamic_cast<B*>(p) != NULL)
		cout << "class B pointer" << endl;
	else if (dynamic_cast<C*>(p) != NULL)
		cout << "class C pointer" << endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << "class A reference" << endl;
		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		cout << "class B reference" << endl;
		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		cout << "class C reference" << endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
}