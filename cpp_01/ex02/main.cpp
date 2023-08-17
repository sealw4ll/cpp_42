#include <iostream>

using std::string;
using std::endl;
using std::cout;

int main()
{
	string brain = "HI THIS IS BRAIN";
	string *pointBrain = &brain;
	string &refBrain = brain;

	cout << "address of brain: " << &brain << endl;
	cout << "address of brain pointer: " << &pointBrain << endl;
	cout << "address of brain reference: " << &refBrain << endl;

	cout << "value of brain: " << brain << endl;
	cout << "value of brain pointer: " << *pointBrain << endl;
	cout << "value of brain reference: " << refBrain << endl;
}