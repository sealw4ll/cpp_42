#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavver("scavver");

	scavver.guardGate();
	scavver.attack("the air");
	scavver.takeDamage(1);
	scavver.beRepaired(100);
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.attack("the air");
	scavver.takeDamage(10000);
	scavver.attack("something");
}