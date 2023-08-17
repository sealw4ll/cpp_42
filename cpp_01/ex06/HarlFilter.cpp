#include "HarlFilter.hpp"

void Harl::debug(void)
{
	cout << "[ DEBUG ]" << endl;
	cout << "Please stop downvoting comments because they missed a joke." << endl;
}

void Harl::info(void)
{
	cout << "[ INFO ]" << endl;
	cout << "I wish we could confine all the people whining about Trump to one subreddit." << endl;
}

void Harl::warning(void)
{
	cout << "[ WARNING ]" << endl;
	cout << "I hate trap music. Also, mumble rap. Oh, and Drake, fuck his vapid bitch-ass too." << endl;
}

void Harl::error(void)
{
	cout << "[ ERROR ]" << endl;
	cout << "The r/askreddit moderators are a joke and straight losers." << endl;
}

void Harl::complain(string level)
{
	string checks[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int x = 0;
	while (x < 4 && checks[x].compare(level))
		++x;
	// else
	// 	cout << "Probably complaining about other insignificant problems." << endl;
	if (x == 4)
		cout << "Probably complaining about other insignificant problems." << endl;
	switch (x)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
	}
}

Harl::Harl()
{
}

Harl::~Harl()
{
}