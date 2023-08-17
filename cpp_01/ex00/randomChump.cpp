#include "Zombie.hpp"

void randomChump(string name)
{
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}