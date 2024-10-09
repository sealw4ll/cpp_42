# ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string target);
		~RobotomyRequestForm();
		string getTarget() const;
		void run() const;
	private:
		string target;
};

#endif