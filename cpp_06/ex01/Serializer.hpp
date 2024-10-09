# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

using std::cout;
using std::endl;

struct Data
{
	int test;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t data);
	private:
		Serializer();
		Serializer(Serializer &copy); // dont need you

		Serializer &operator=(Serializer &copy); // dont need you
		~Serializer();
};

# endif