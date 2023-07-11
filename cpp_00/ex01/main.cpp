#include "PhoneBook.hpp"

string Contact::get_first()
{
	return (this->first_name);
}

string Contact::get_last()
{
	return (this->last_name);
}

string Contact::get_nick()
{
	return (this->nickname);
}

string Contact::get_phone()
{
	return (this->phone_num);
}

string Contact::get_secret()
{
	return (this->secret);
}

Contact::Contact()
{
}

void Contact::set_contacts(string first, string last, string nick, string phone, string secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->phone_num = phone;
	this->secret = secret;
}

void PhoneBook::print_all(int *total_added)
{
	for (int i = 0; i < 8 && i < *total_added + 1; i++)
	{
		cout << this->contacts[i].get_phone() << endl;
	}
}

PhoneBook::PhoneBook()
{
}

void PhoneBook::add_contact(int index, string first, string last, string nick, string phone, string secret)
{
	this->contacts[index % 8].set_contacts(first, last, nick, phone, secret);
}

void add_funct(PhoneBook &ref, int *total_added)
{
	string first_name;
	string last_name;
	string nickname;
	string phone_num;
	string secret;

	cout << "insert first name:" << endl;
	cin >> first_name;
	cout << "insert last name:" << endl;
	cin >> last_name;
	cout << "insert nickname:" << endl;
	cin >> nickname;
	cout << "insert phone number:" << endl;
	cin >> phone_num;
	cout << "insert PERSONAL secret:" << endl;
	cin >> secret;

	ref.add_contact(*total_added++, first_name, last_name, nickname, phone_num, secret);
}

void search_funct(PhoneBook &ref, int *total_added)
{
	ref.print_all(total_added);
}

int main(void)
{
	int total_added = 0;
	string input;
	PhoneBook phonebook;
	PhoneBook &ref = phonebook;

	while (1)
	{
		cout << "Please insert valid input" << endl;
		cin >> input;
		if (!strcmp("ADD", input.c_str()))
			add_funct(ref, &total_added);
		else if (!strcmp("SEARCH", input.c_str()))
			search_funct(ref, &total_added);
		else if (!strcmp("EXIT", input.c_str()))
			return 0;
		else
			continue;
	}
}