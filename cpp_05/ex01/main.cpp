#include "Form.hpp"
#include "Bureaucrat.hpp"
int main()
{
	// working test case
	// cout << "test case pass:" << endl;
	//inititialization
	Form form1("Form1", 60, 60);
	Form form2("Form2", -1, 60);
	Form form3("Form3", 60, -1);
	Form form4("Form4", 1000, 59);
	// system("leaks bureaucrat");
}