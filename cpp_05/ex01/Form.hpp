# ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>

using std::string;
using std::cout;
using std::endl;

class Form
{
	public:
		Form();
		Form(string name, int reqsign, int reqexec);
		Form(const Form &Form);
		Form & operator = (const Form &Form);
		~Form();
		string getname();
		int getreqsign();
		int getreqexec();
		int getifsign();
		void besigned(int grade);
		void signform();
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
};

std::ostream & operator << (std::ostream &out, const Form &obj)

#endif