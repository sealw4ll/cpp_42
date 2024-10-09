# ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string target);
		~PresidentialPardonForm();
		string getTarget() const;
		void run() const;
	private:
		string target;
};

#endif