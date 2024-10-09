#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator = (ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

bool ValidNum(string input)
{
	int decimalCount = 0;
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (isdigit(input[i]))
			continue;
		else if (input[i] == '.' && decimalCount == 0)
			++decimalCount;
		else
			return false;
	}
	return true;
}

int FindType(string input)
{
	if (input.length() == 0)
		return ERROR;
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return FLOAT;
	if (!input.compare("-inf") || !input.compare("+inf") ||!input.compare("nan"))
		return DOUBLE;
	if (input.length() == 1 && isalpha(input[0]))
		return CHAR;
	if (ValidNum(input) == false)
		return ERROR;
	if (input[input.length() - 1] == 'f')
		return FLOAT;
	if (std::find(input.begin(), input.end(), '.') != input.end())
		return DOUBLE;
	else
		return INT;
}

void PrintValue(char c, int i, float f, double d)
{
	// char
	if (isprint(i))
		cout << "char: " << c << endl;
	else if (isascii(i))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: impossible" << endl;
	// int
	if (d >= INT_MIN && d <= INT_MAX)
		cout << "int: " << i << endl;
	else
		cout << "int: impossible" << endl;
	// float & double
	if (d == (double)i)
	{
		cout << "float: " << f << ".0f" << endl;
		cout << "double: " << d << ".0" << endl;
	}
	else
	{
		cout << "float: " << f << "f" << endl;
		cout << "double: " << d << endl;
	}

}

void ScalarConverter::convert(string input)
{
	char c;
	int i;
	float f;
	double d;

	switch (FindType(input))
	{
		case CHAR:
			c = input[0];
			PrintValue(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
			return ;
		case INT:
			i = atoi(input.c_str());
			PrintValue(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
			return ;
		case FLOAT:
			f = strtof(input.c_str(), NULL);
			PrintValue(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
			return ;
		case DOUBLE:
			d = strtod(input.c_str(), NULL);
			PrintValue(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
			return ;
	}
	cout << "Input error" << endl;
}