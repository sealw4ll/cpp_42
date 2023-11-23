#include "Form.hpp"

Form::Form() : name("default") , reqsign(75) , reqexec(75)
{
	cout << "Default constructor called" << endl;
	this->ifsign = false;
}

Form::Form(const Form &form) : name(form.name) , reqsign(form.reqsign) , reqexec(form.reqexec)
{
	cout << "Form copy constructor called" << endl;
	*this = form;
}

Form & Form::operator = (Form const &form)
{
	cout << "Form copy assignment called" << endl;
	(void)form;
	return *this;
}

Form::~Form()
{
	cout << "Form destructor called" << endl;
}

Form::Form(string name, int reqsign, int reqexec) : name(name) , reqsign(reqsign) , reqexec(reqexec)
{
	cout << "Form overloaded constructor called" << endl;
	this->ifsign = false;
	if (reqsign > 150 || reqexec > 150)
		throw (Form::GradeTooLowException());
	if (reqsign < 1 || reqexec < 1)
		throw (Form::GradeTooHighException());
}

string Form::getname() const
{
	return this->name;
}

int Form::getreqsign() const
{
	return this->reqsign;
}

int Form::getreqexec() const
{ 
	return this->reqexec;
}

bool Form::getifsign() const
{
	return this->ifsign;
}

void Form::besigned(int grade)
{
	if (grade >= this->reqsign)
		throw (Form::GradeTooLowException());
	this->ifsign = true;
}

std::ostream & operator << (std::ostream &out, const Form &obj)
{
  return out << obj.getname() << ", form is signed? " << obj.getifsign() << " Form requirement "<< obj.getreqsign() << ".";
}