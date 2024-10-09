#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	cout << "PresidentialPardonForm constructor called" << endl;
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", 25, 5)
{
	cout << "PresidentialPardonForm target constructor called" << endl;
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructor called" << endl;
}

string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::run() const
{
	cout << this->target << " has been pardoned by Zaphod Beeblebrox" << endl;
}