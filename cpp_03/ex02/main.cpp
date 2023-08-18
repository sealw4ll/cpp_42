#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap fragger("fragger");

	fragger.highFivesGuys();
	fragger.attack("the air");
	fragger.takeDamage(1);
	fragger.beRepaired(100);
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.attack("the air");
	fragger.takeDamage(10000);
	fragger.attack("something");
}