#include "HarlFilter.hpp"

int main(int ac, char **av)
{
	Harl Harl;

	if (ac != 2)
	{
		cout << "invalid number of args" << endl;
		return 1;
	}
	string level(av[1]);
	Harl.complain(level);
}