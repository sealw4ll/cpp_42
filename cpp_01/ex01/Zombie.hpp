#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstring>
#include <iomanip>

using std::string;

class Zombie
{
	public:
		Zombie();
		Zombie(string name);
		~Zombie();
		void setName(string name);
		void announce( void );
	private:
		string name;
};

Zombie *zombieHorde(int N, string name);

#endif