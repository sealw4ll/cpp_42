#include "Intern.hpp"

Intern::Intern()
{
	cout << "intern constructor" << endl;
}

Intern::Intern(Intern &copy)
{
	cout << "Intern copy contstructor called" << endl;
	*this = copy;
}

Intern & Intern::operator = (Intern const &copy)
{
	cout << "Form copy assignment called" << endl;
	(void)copy;
	return *this;
}

Intern::~Intern()
{
	cout << "Intern destructor called" << endl;
}

AForm *Robot(string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Shrub(string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *President(string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(string type, string target)
{
	AForm *(*functions[])(string) = {&Robot, &Shrub, &President};
	string array[] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	string lowerType;
	for (int i = 0; i < (int)type.length(); i++)
		lowerType += std::tolower(type[i]);

	int i = 0;
	while (i < 3 && array[i].compare(lowerType))
		++i;
	if (i == 3)
		throw InvalidForm();
	
	AForm *form = functions[i](target);
	cout << "Intern creates " << form->getname() << endl;
	return (form);
}