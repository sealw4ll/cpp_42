#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	cout << "DiamondTrap constructor called" << endl;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap::ClapTrap(name) , ScavTrap::ScavTrap(name) , FragTrap::FragTrap(name)
{
	cout << "DiamondTrap constructor called with name " << name << endl;
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hp = FragTrap::hp;
	this->energy = ScavTrap::energy2;
	this->strength = FragTrap::strength;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap destructor called" << endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	cout << "my clap name is " << ClapTrap::name << " my diamond name is " << this->name << endl;
}

void DiamondTrap::print()
{
	cout << "name: " << this->name << endl;
	cout << "hp: " << this->hp << endl;
	cout << "energy: " << this->energy << endl;
	cout << "strength: " << this->strength << endl;
}