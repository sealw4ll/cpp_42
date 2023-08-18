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
		ClapTrap &operator = (const ClapTrap &copy);
		~ClapTrap();
		void attack(const string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		unsigned int hp;
		unsigned int energy;
		unsigned int strength;
		string name;
};

#endif