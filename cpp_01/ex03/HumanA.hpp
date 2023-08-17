#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

using std::string;

class HumanA
{
	public:
		HumanA(string name, Weapon &type);
		~HumanA();
		void attack(void);
	private:
		Weapon *weapon;
		string name;
};

#endif