# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;

class Animal
{
	public:
		virtual ~Animal();
		Animal(Animal &copy);
		Animal &operator = (const Animal &copy);
		virtual void makeSound() const = 0;
		string getType() const;
	protected:
		Animal();
		string type;
};

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		void makeSound() const;
		string getType() const;
	protected:
		string type;
};

#endif