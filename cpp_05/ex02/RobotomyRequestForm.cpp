#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	cout << "RobotomyRequestForm constructor called" << endl;
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45)
{
	cout << "RobotomyRequestForm target constructor called" << endl;
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructor called" << endl;
}

string RobotomyRequestForm::getTarget()
{
	return this->target;
}

void RobotomyRequestForm::run() const
{
	srand(time(NULL));
	cout << "bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;
	if (rand() % 2 == 0)
		cout << this->target << " has been robotomized" << endl;
	else
		cout << this->target << " robotomy failed (skill issue)" << endl;
}