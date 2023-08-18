#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	cout << "FragTrap constructor called" << endl;
}


FragTrap::FragTrap(string name) : ClapTrap::ClapTrap(name)
{
	cout << "FragTrap constructor called with name " << name << endl;
	this->name = name;
	this->hp = 100;
	this->energy = 100;
	this->strength = 100;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap destructor called" << endl;
}

FragTrap::FragTrap(FragTrap &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

FragTrap &FragTrap::operator = (const FragTrap &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	cout << "FragTrap " << this->name << " has high fived someone. Its morale is now boosted :D!" << endl;
}