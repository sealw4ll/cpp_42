#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	_data = copy.getData();
	return *this;
}

map<string, float>	BitcoinExchange::getData() const
{
	return _data;
}

void BitcoinExchange::setData(string date, float rate)
{
	_data[date] = rate;
}

void BitcoinExchange::readCSV()
{
	std::fstream csv;
	string date;
	string readRate;
	float rate;

	csv.open("data.csv", std::ios::in);
	getline(csv, date, '\n');
	while (getline(csv, date, ',')){
		getline(csv, readRate, '\n');
		rate = std::stof(readRate);
		this->setData(date, rate);
	}
	csv.close();
}

void BitcoinExchange::parseInput(string line)
{
	string value;
	int	num = 0, dash = 0;

	_currYear = line.substr(0, 10);
	for (int i = 0; i < (int)_currYear.size(); ++i){
		if (std::isdigit(_currYear[i]))
			num++;
		else if (_currYear[i] == '-')
			dash++;
	}
	if (num != 8 || dash != 2)
		throw (BadInput());
	try{
		value = line.substr(13, string::npos);
	}
	catch (const std::out_of_range &oor){
		throw (BadInput());
	}
	_currValue = std::stof(value);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void	BitcoinExchange::checkDate()
{
	try{
		string	strYear = _currYear.substr(0, 4);
		string	strMonth = _currYear.substr(5, 2);
		string strDay = _currYear.substr(8, 2);
		int year = atoi(strYear.c_str());
		int month = atoi(strMonth.c_str());
		int day = atoi(strDay.c_str());
		if (year < 1)
			throw (BadInput());
		if (month > 12 || month < 1)
			throw (BadInput());
		switch (month) {
            case JANUARY: case MARCH: case MAY: case JULY: case AUGUST: case OCTOBER: case DECEMBER:
                if (day > 31 || day < 1)
                    throw BadInput();
                break;
            case FEBRUARY:
                if ((isLeapYear(year) && day > 29) || (!isLeapYear(year) && day > 28) || day < 1)
                    throw BadInput();
                break;
            case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
                if (day > 30 || day < 1)
                    throw BadInput();
                break;
        }
	}
	catch (const std::out_of_range &oor){
		throw BadInput();
	}
}

void BitcoinExchange::checkLimit()
{
	if (_currValue < 0)
		throw NotPositive();
	else if (_currValue > 1000)
		throw TooLarge();
}

void BitcoinExchange::run()
{
	map<string, float>::iterator itr = _data.lower_bound(_currYear);

	if (_currYear != itr->first){
		if (itr == _data.begin()){
			throw (BadInput());
		}
		--itr;
	}

	cout << _currYear << " => " << _currValue << " = " << std::fixed << std::setprecision(2) << (_currValue * itr->second) << endl;
}

void BitcoinExchange::readInput(char *filename)
{
	std::fstream	file;
	string	line;

	file.open(filename, std::ios::in);
	getline(file, line);
	while (getline(file, line)){
		try{
			parseInput(line);
			checkDate();
		}
		catch(std::exception &e){
			cout << e.what() << " => " << line << endl;
			continue ;
		}
		try{
			checkLimit();
		}
		catch(std::exception &e){
			cout << e.what() << endl;
			continue ;
		}
		try{
			run();
		}
		catch(std::exception &e){
			cout << e.what() << " => " << line << endl;
			continue ;
		}
	}
	file.close();
}