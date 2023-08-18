#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	cout << endl << "Wrong test:" << endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	delete(wrong);
	delete(wrongCat);
	system("leaks polymorph");
	return 0;
}