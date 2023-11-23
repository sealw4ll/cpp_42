#include "Bureaucrat.hpp"

int main()
{
	// working test case
	cout << "test case pass:" << endl;
	try
	{
		Bureaucrat *working = new Bureaucrat("working", 100);
		cout << "succesful initialization" << endl;
		working->increment();
		cout << *working << endl;
		working->decrement();
		cout << *working << endl;
		delete working;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}



	// too high exceptions
	cout << endl << "test case incremented too high:" << endl;
	try
	{
		Bureaucrat *highguy = new Bureaucrat("highguy", 1);
		cout << "succesful initialization" << endl;
		highguy->increment();
		cout << highguy << endl;
		delete highguy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	cout << endl << "test case initialized too high:" << endl;
	try
	{
		Bureaucrat *highguy = new Bureaucrat("highguy", 0);
		cout << "succesful initialization" << endl;
		highguy->increment();
		cout << highguy << endl;
		delete highguy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}



	// too low exceptions
	cout << endl << "test case incremented too low:" << endl;
	try
	{
		Bureaucrat *lowguy = new Bureaucrat("lowguy", 150);
		cout << "succesful initialization" << endl;
		lowguy->decrement();
		cout << lowguy << endl;
		delete lowguy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}


	cout << endl << "test case initialized too low:" << endl;
	try
	{
		Bureaucrat *lowguy = new Bureaucrat("lowguy", 151);
		cout << "succesful initialization" << endl;
		lowguy->decrement();
		cout << lowguy << endl;
		delete lowguy;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	// system("leaks bureaucrat");
}