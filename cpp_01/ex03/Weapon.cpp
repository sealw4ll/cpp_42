#include "Weapon.hpp"

void Weapon::setType(string type)
{
	this->type = type;
}

const string Weapon::getType()
{
	return this->type;
}

Weapon::Weapon(string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}
