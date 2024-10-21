#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "please provide reverse Polish notation" << endl;
		exit (1);
	}
	string input(argv[1]);
	if (input.empty())
	{
		cout << "Error: empty string" << endl;
		exit (1);
	}
	RPN test;
	test.runRPN(input);
}