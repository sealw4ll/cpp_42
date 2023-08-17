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
		void announce( void );
	private:
		string name;
};

Zombie *newZombie(string name);
void randomChump(string name);

#endif