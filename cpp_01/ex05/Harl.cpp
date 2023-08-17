#include "Harl.hpp"

void Harl::debug(void)
{
	cout << "Please stop downvoting comments because they missed a joke." << endl;
}

void Harl::info(void)
{
	cout << "I wish we could confine all the people whining about Trump to one subreddit." << endl;
}

void Harl::warning(void)
{
	cout << "I hate trap music. Also, mumble rap. Oh, and Drake, fuck his vapid bitch-ass too." << endl;
}

void Harl::error(void)
{
	cout << "The r/askreddit moderators are a joke and straight losers." << endl;
}

void Harl::complain(string level)
{
	void (Harl::*harlPointer[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string checks[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int x = 0;
	while (x < 4 && checks[x].compare(level))
		++x;
	if (x < 4)
		(this->*harlPointer[x])();
	else
		cout << "Probably complaining about other insignificant problems." << endl;

}

Harl::Harl()
{
}

Harl::~Harl()
{
}