#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("diamond");

	diamond.print();
	diamond.whoAmI();
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.attack("the air");
	diamond.takeDamage(1000000);
}