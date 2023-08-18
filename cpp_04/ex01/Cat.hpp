# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat &copy);
		Cat &operator = (const Cat &copy);
		void makeSound() const;
	private:
		Brain* brain;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		void makeSound() const;
};

#endif