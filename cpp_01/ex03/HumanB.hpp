#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

using std::string;

class HumanB
{
	public:
		HumanB(string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack(void);
	private:
		Weapon *weapon;
		string name;
};

#endif