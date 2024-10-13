#include "PhoneBook.hpp"

using std::setw;
using std::strcmp;
using std::cout;
using std::endl;
using std::cin;

string trunc(string str)
{
	if (str.length() > 10)
		return (str.substr(1, 10).replace(9, 10, "."));
	return (str);
}

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

void PhoneBook::print_info(int index)
{
	cout << "First Name: " << this->contacts[index].get_first() << endl;
	cout << "Last Name: " << this->contacts[index].get_last() << endl;
	cout << "Nickname: " << this->contacts[index].get_nick() << endl;
	cout << "Phone Number: " << this->contacts[index].get_phone() << endl;
	cout << "DARKEST secret: " << this->contacts[index].get_secret() << endl;
}

void PhoneBook::print_table(int *total_added)
{
	cout << "_____________________________________________" << endl;
	cout << "|     Index|First Name| Last Name|  Nickname|" << endl;
	for (int i = 0; i < 8 && i < *total_added; i++)
	{
		cout << "|"  << setw(10) << i;
		cout << "|"  << setw(10) << trunc(this->contacts[i].get_first());
		cout << "|"  << setw(10) << trunc(this->contacts[i].get_last());
		cout << "|"  << setw(10) << trunc(this->contacts[i].get_nick());
		cout << "|" << endl;
	}
	cout << "_____________________________________________" << endl;
}

PhoneBook::PhoneBook()
{
}

void PhoneBook::add_contact(int index, string first, string last, string nick, string phone, string secret)
{
	this->contacts[index % 8].set_contacts(first, last, nick, phone, secret);
}

void add_funct(PhoneBook &phonebook, int *total_added)
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
	cout << "insert DARKEST secret:" << endl;
	cin >> secret;

	phonebook.add_contact((*total_added)++, first_name, last_name, nickname, phone_num, secret);
}

bool num_check(string str)
{
	return (str.find_first_not_of("0123456789") == std::string::npos);
}

void search_funct(PhoneBook &phonebook, int *total_added)
{
	string input;

	phonebook.print_table(total_added);
	cout << "input index:" << endl;
	cin >> input;
	int num = std::strtod(input.c_str(), NULL);
	if (num_check(input) == false || num > 7 || num >= *total_added || *total_added < 1)
	{
		cout << "invalid index" << endl;
		return;
	}
	phonebook.print_info(num);
}

int main(void)
{
	int total_added = 0;
	string input;
	PhoneBook phonebook;

	while (1)
	{
		cout << "Please insert valid input" << endl;
		cin >> input;
		if (!strcmp("ADD", input.c_str()))
			add_funct(phonebook, &total_added);
		else if (!strcmp("SEARCH", input.c_str()))
			search_funct(phonebook, &total_added);
		else if (!strcmp("EXIT", input.c_str()))
			return 0;
		else
			continue;
	}
}