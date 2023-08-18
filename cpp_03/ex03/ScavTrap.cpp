#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	cout << "ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap::ClapTrap(name)
{
	cout << "ScavTrap constructor called with name " << name << endl;
	this->name = name;
	this->hp = 50;
	this->energy = 50;
	this->energy2 = 50;
	this->strength = 50;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap destructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void ScavTrap::attack(const string &target)
{
	if (this->hp == 0)
		cout << "ScavTrap " << this->name << " is sleeping for an indefinite period of time" << endl;
	else if (this->energy == 0)
		cout << "ScavTrap " << this->name << " is tired and needs a nap" << endl;
	else
	{
		--this->energy;
		cout << "ScavTrap " << this->name << " slaps " << target << ", causing " << this->strength << " points of damage!" << endl;
	}
}

void ScavTrap::guardGate()
{
	cout << "ScavTrap " << this->name << " has entered guard mode." << endl;
}