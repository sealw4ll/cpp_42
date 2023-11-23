#include "Form.hpp"

Form::Form()
{
	cout << "Default constructor called" << endl;
	this->name = "default";
	this->ifsign = false;
	this->reqsign = 75;
	this->reqexec = 75;
}

Form::Form(const Form &form)
{
	cout << "Form copy constructor called" << endl;
	*this = Form;
}

Form & Form::operator = (const Form &form)
{
	cout << "Form copy assignment called" << endl;
	this->name = form.getname();
	this->reqsign = form.getreqsign();
	this->reqexec = form.getreqexec();
	this->ifsign = form.getifsign();
	return *this;
}

Form::~Form()
{
	cout << "Form destructor called" << endl;
}

Form::Form(string name, int reqsign, int reqexec) : name(name) , reqsign(reqsign) , reqexec(reqexec)
{
	cout << "Overloaded constructor called" << endl;
	this->ifsign = false
	if (reqsign > 150 || reqexec > 150)
		throw Form::GradeTooLowException;
	if (reqsign < 1 || reqexec < 1)
		throw Form::GradeTooHighException;
}

string Form::getname()
{
	return this->name;
}

int Form::getreqsign()
{
	return this->reqsign;
}

int Form::getreqexec()
{
	return this->reqexec;
}

bool Form::getifsign()
{
	return this->ifsign;
}

void Form::besigned(Bureaucrat &guy)
{
	if (guy->grade >= this->reqsign)
		throw Form::GradeTooLowException;
	this->ifsign = true;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
  return out << obj.getname() << ", form is signed? " << obj.getifsign() << " Form requirement "<< obj.getreqsign() << ".";
}