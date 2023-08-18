# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(string name);
		ClapTrap(ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator = (const ClapTrap &copy);
		void attack(const string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		unsigned int hp;
		unsigned int energy;
		unsigned int strength;
		string name;
};

#endif