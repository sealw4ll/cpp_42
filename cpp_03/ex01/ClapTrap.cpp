#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(string name)
{
	cout << "ClapTrap constructor called with name " << name << endl;
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->strength = 20;
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

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap default destructor called" << endl;
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