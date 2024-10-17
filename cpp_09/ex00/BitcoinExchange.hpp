# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <iterator>
# include <sstream>
# include <cctype>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::map;

class NotPositive : public std::exception {
	public:
		const char *what() const throw(){
			return ("Error: non positive number");
		}
};

class TooLarge : public std::exception {
	public:
		const char *what() const throw(){
			return ("Error: number too large");
		}
};

class BadInput : public std::exception {
	public:
		const char *what() const throw(){
			return ("Error: bad input");
		}
};

enum Month {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12,
};

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void readCSV();
		void setData(string data, float rate);
		map<string, float> getData() const;
		void readInput(char *filename);
		void parseInput(string line);
		bool isLeapYear(int year);
		void checkDate();
		void checkLimit();
		void run();
	private:
		map<string, float> _data;
		string _currYear;
		float _currValue;
};

#endif