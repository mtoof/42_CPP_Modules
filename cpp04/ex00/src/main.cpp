#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrongcat->makeSound();
	wronganimal->makeSound();


	delete animal;
	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;
	return (0);
}