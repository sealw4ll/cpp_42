#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	const Animal *arr[10];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		arr[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]->getType() << endl;
	}
	for (int i = 0; i < 10; i++)
		delete(arr[i]);
	system("leaks brain");
	return 0;
}