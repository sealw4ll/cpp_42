#include "Zombie.hpp"

using std::cout;
using std::endl;

Zombie::Zombie()
{
	cout << "constructing default zombie" << endl;
	this->name = "zombie";
}

Zombie::~Zombie()
{
	cout << "destructing: " << this->name << endl;
	
}

Zombie::Zombie(string name)
{
	cout << "constructing zombie " << name << endl;
	this->name = name;
}

void Zombie::setName(string name)
{
	this->name = name;
}

void Zombie::announce()
{
	cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}