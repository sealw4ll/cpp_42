#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain default constructor called" << endl;
}

Brain::~Brain()
{
	cout << "Brain default destructor called" << endl;
}

Brain::Brain(Brain &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Brain &Brain::operator = (const Brain &copy)
{
	cout << "Copy assignment operator called" << endl;
	(void)copy;
	return (*this);
}
