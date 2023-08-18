# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap &copy);
		DiamondTrap &operator = (const DiamondTrap &copy);
		void whoAmI();
		void print();
	private:
		string name;
};

#endif