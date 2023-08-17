#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

#include <iostream>

using std::endl;
using std::cout;
using std::string;

class Harl
{
	public:
		void complain(string level);
		Harl();
		~Harl();
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif