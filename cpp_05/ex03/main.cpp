#include "Bureaucrat.hpp"
#include "Intern.hpp"


int	main()
{
	Intern intern;
	Bureaucrat guy("guy", 1);

	cout << endl << "------------ ROBOT ------------" << endl;
	AForm *robot = intern.makeForm("ROBOTOMY request", "robot");
	cout << "target is: " << robot->getTarget() << endl;
	guy.signForm(*robot);
	guy.executeForm(*robot);

	cout << endl << "------------ SHRUB ------------" << endl;
	AForm *shrub = intern.makeForm("SHRUBBERY creation", "shrub");
	cout << "target is: " << shrub->getTarget() << endl;
	guy.signForm(*shrub);
	guy.executeForm(*shrub);

	cout << endl << "------------ PRESIDENT ------------" << endl;
	AForm *president = intern.makeForm("PRESIDENTIAL pardon", "president");
	cout << "target is: " << president->getTarget() << endl;
	guy.signForm(*president);
	guy.executeForm(*president);

	cout << endl << "------------ FAIL ------------" << endl;
	try
	{
		AForm *fail = intern.makeForm("fail", "fail");
		cout << "what??: " << fail->getname() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	
	cout << endl << "----------------------------" << endl;
}