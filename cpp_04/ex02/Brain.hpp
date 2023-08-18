# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain &copy);
		Brain &operator = (const Brain &copy);
		string ideas[100];
};

#endif