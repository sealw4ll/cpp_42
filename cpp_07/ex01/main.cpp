#include "Iter.hpp"

void testFunct(int &test)
{
	cout << test << endl;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	int size = 5;

	// iter<int, void>(tab, size, printstuff);
	// iter(tab, size, multi_two);

	iter<int, void>(tab, size, testFunct);
	return 0;
}