#include "HumanA.hpp"

using std::cout;
using std::endl;

HumanA::HumanA(string name, Weapon &type):weapon(&type)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	cout << this->name << " attacks with their " << this->weapon->getType() << endl;
}