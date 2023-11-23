#include "Form.hpp"
#include "Bureaucrat.hpp"
int main()
{
	// working test case
	// cout << "test case pass:" << endl;
	//inititialization
	try
	{
	Form form1("Form1", 60, 60);
	Form form2("Form1", 60, 60);
	Bureaucrat smortman("smortman", 1);
	Bureaucrat snortman("snortman", 150);

	smortman.signform(form1);
	snortman.signform(form2);
	// Form form2("Form2", -1, 60);
	// Form form3("Form3", 60, -1);
	// Form form4("Form4", 1000, 59);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	// system("leaks bureaucrat");
}