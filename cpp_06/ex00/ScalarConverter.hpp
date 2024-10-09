# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <climits>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

enum {
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	ERROR = 5,
};

class ScalarConverter
{
	public:
		static void convert(string input);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter & operator = (ScalarConverter &copy);

};

# endif