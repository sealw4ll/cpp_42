#include "AForm.hpp"

AForm::AForm() : name("default") , reqsign(75) , reqexec(75)
{
	cout << "Default constructor called" << endl;
	this->ifsign = false;
}

AForm::AForm(const AForm &form) : name(form.name) , reqsign(form.reqsign) , reqexec(form.reqexec)
{
	cout << "Form copy constructor called" << endl;
	*this = form;
}

AForm & AForm::operator = (AForm const &form)
{
	cout << "Form copy assignment called" << endl;
	(void)form;
	return *this;
}

AForm::~AForm()
{
	cout << "AForm destructor called" << endl;
}

AForm::AForm(string name, int reqsign, int reqexec) : name(name) , reqsign(reqsign) , reqexec(reqexec)
{
	cout << "Form overloaded constructor called" << endl;
	this->ifsign = false;
	if (reqsign > 150 || reqexec > 150)
		throw (AForm::GradeTooLowException());
	if (reqsign < 1 || reqexec < 1)
		throw (AForm::GradeTooHighException());
}

string AForm::getname() const
{
	return this->name;
}

int AForm::getreqsign() const
{
	return this->reqsign;
}

int AForm::getreqexec() const
{ 
	return this->reqexec;
}

bool AForm::getifsign() const
{
	return this->ifsign;
}

void AForm::besigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= this->reqsign)
		throw (AForm::GradeTooLowException());
	this->ifsign = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->ifsign == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->reqexec)
		throw AForm::GradeTooLowException();
	cout << "executed by "<< executor.getName() << endl;
	this->run();
}

std::ostream & operator << (std::ostream &out, const AForm &obj)
{
  return out << obj.getname() << ", form is signed? " << obj.getifsign() << " Form requirement "<< obj.getreqsign() << ".";
}