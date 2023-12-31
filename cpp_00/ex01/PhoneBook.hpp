#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

	#include <iostream>
	#include <cstring>
	#include <iomanip>
	#include <stdlib.h>

	using std::string;

	class Contact
	{
		public:
			Contact();
			void set_contacts(string first, string last, string nick, string phone, string secret);
			string get_first();
			string get_last();
			string get_nick();
			string get_phone();
			string get_secret();
		private:
			string first_name;
			string last_name;
			string nickname;
			string phone_num;
			string secret;
	};

	class PhoneBook
	{
		public:
			PhoneBook();
			void add_contact(int index, string first, string last, string nick, string phone, string secret);
			void print_table(int *total_added);
			void print_info(int index);
		private:
			Contact contacts[8];
	};

#endif