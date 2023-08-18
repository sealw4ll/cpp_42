#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	cout << "Default constructor called" << endl;
}

ClapTrap::ClapTrap(string name)
{
	cout << "Default constructor called with name " << name << endl;
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->strength = 0;
}

ClapTrap::~ClapTrap()
{
	cout << "Destructor called" << endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void ClapTrap::attack(const string &target)
{
	if (this->hp == 0)
		cout << "ClapTrap " << this->name << " is sleeping for an indefinite period of time" << endl;
	else if (this->energy == 0)
		cout << "ClapTrap " << this->name << " is tired and needs a nap" << endl;
	else
	{
		--this->energy;
		cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->strength << " points of damage!" << endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp == 0)
		cout << "ClapTrap " << this->name << " is sleeping for an indefinite period of time" << endl;
	else if (this->energy == 0)
		cout << "ClapTrap " << this->name << " is tired and needs a nap" << endl;
	else
	{
		--this->energy;
		this->hp += amount;
		cout << "ClapTrap " << this->name << " repairs itself for " << amount << " and is now " << this->hp << " hp!" << endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= amount)
	{
		this->hp = 0;
		cout << "ClapTrap " << this->name << " has been dealt " << amount << " damage and has been knocked out!" << endl;
	}
	else
	{
		this->hp -= amount;
		cout << "ClapTrap " << this->name << " has taken " << amount << " damage and is now at " << this->hp << " hp!" << endl;
	}
}