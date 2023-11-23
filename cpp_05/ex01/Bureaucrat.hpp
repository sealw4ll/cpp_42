# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>

using std::string;
using std::cout;
using std::endl;

class GradeTooHigh : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Grade too high");
		}
};

class GradeTooLow : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Grade too low");
		}
};

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat & operator = (const Bureaucrat &bureaucrat);
		~Bureaucrat();
		void increment();
		void decrement();
		string getName() const;
		int getGrade() const;
		void signform(Form &form);

	private:
		string name;
		int grade;
		GradeTooHigh GradeTooHighException;
		GradeTooLow GradeTooLowException;
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj);

#endif