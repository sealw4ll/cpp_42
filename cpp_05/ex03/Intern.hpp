# ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdlib.h>
#include <exception>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
// class AForm;
using std::string;
using std::endl;
using std::cout;

class Intern
{
	public:
		Intern();
		Intern(Intern &copy);
		Intern & operator = (const Intern &AForm);
		~Intern();
		AForm *makeForm(string type, string target);

	private:
		class InvalidForm : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Invalid form name");
				}
		};
};

#endif