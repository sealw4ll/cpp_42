#include "Zombie.hpp"

int main()
{
	int numZomb = 6;
	Zombie *horde = zombieHorde(numZomb, "bob");
	delete []horde;
}