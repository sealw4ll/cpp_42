# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(string name);
		~FragTrap();
		FragTrap(FragTrap &copy);
		FragTrap &operator = (const FragTrap &copy);
		void highFivesGuys();
};

#endif