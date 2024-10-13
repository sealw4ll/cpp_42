#include "EasyFind.hpp"
#include <vector>
#include <iostream>
using std::vector;

void tryfind(vector<int> container, int tofind)
{
	try
	{
		easyfind(container, tofind);
		std::cout << "Found " << tofind << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> test;

	for (int i = 0; i < 5; i++)
		test.push_back(i);

	for (int i = 0; i < 6; i++)
		tryfind(test, i);
}