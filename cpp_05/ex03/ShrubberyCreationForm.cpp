#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	cout << "ShrubberyCreationForm constructor called" << endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	cout << "ShrubberyForm target constructor called" << endl;
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyForm destructor called" << endl;
}

string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::run() const
{
	std::ofstream out;

	out.open((string(target).append("_shrubbery")).c_str(), std::ios::trunc | std::ios::out);
	out << " _                 \n";
    out << "| |                \n";
    out << "| |_ _ __ ___  ___ \n";
    out << "| __| '__/ _ \\/ _ \\\n";
    out << "| |_| | |  __/  __/\n";
    out << " \\__|_|  \\___|\\___| \n";
	out.close();
}