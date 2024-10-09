# ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>

using std::string;
using std::cout;
using std::endl;

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(string name, int reqsign, int reqexec);
		AForm(const AForm &AForm);
		AForm & operator = (const AForm &AForm);
		virtual ~AForm();
		string getname() const;
		int getreqsign() const;
		int getreqexec() const;
		bool getifsign() const;
		void besigned(Bureaucrat &bureaucrat);
		// void signform();
		void execute(Bureaucrat const & executor) const;
		virtual void run() const = 0;
	private:
		const string name;
		bool ifsign;
		const int reqsign;
		const int reqexec;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade too low");
				}
		};

		class FormNotSigned : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Form not signed");
				}
		};
};

std::ostream & operator << (std::ostream &out, const AForm &obj);

#endif