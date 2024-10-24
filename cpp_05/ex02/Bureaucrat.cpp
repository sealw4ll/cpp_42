#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	cout << "Default constructor called" << endl;
	this->grade = 150;
	this->name = "default";
}

Bureaucrat::Bureaucrat(string name, int grade) : name(name)
{
	cout << "Bureaucrat constructor called" << endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	cout << "Bureaucrat copy constructor called" << endl;
	*this = bureaucrat;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &bureaucrat)
{
	cout << "Bureaucrat copy assignment called" << endl;
	this->name = bureaucrat.getName();
	this->grade = bureaucrat.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor called" << endl;
}

void Bureaucrat::increment()
{
	--this->grade;
	if (grade < 1)
	{
		delete this;
		throw (Bureaucrat::GradeTooHighException());
	}
}

void Bureaucrat::decrement()
{
	++this->grade;
	if (grade > 150)
	{
		delete this;
		throw (Bureaucrat::GradeTooLowException());
	}
}

string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
  return out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.besigned(*this);
		cout << name << " successfully signed " << form.getname() << endl;
	}
	catch (std::exception &e)
	{
		cout << this->name << " couldn't sign " << form.getname() << " because " << e.what() << endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		cout << name << " executed " << form.getname() << endl;
	}
	catch (std::exception &e)
	{
		cout << this->name << " couldn't execute " << form.getname() << " because " << e.what() << endl;
	}
}