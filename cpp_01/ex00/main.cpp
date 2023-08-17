#include "Zombie.hpp"

int main()
{
	Zombie *tom = newZombie("tom");
	tom->announce();
	delete tom;

	randomChump("bob");
}