# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(string name);
		~ScavTrap();
		ScavTrap(ScavTrap &copy);
		ScavTrap &operator = (const ScavTrap &copy);
		void attack(const string &target);
		void guardGate();
	protected:
		unsigned int energy2;
};

#endif