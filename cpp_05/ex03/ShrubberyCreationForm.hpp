# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string target);
		~ShrubberyCreationForm();
		string getTarget() const;
		void run() const;
	private:
		string target;
};

#endif