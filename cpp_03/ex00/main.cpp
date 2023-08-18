#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapper("clapper");

	clapper.attack("the air");
	clapper.takeDamage(1);
	clapper.beRepaired(100);
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.attack("the air");
	clapper.takeDamage(10000);
	clapper.attack("something");
}