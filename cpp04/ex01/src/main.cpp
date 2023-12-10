#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongCat.hpp"
#include <sstream>

int main()
{
	std::cout << "First test" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

//==============================================//

	std::cout << "Second test" << std::endl;
	Animal** animal = new Animal*[10];


	for (int index = 0; index < 10; index++)
	{
		if (index < 5)
		{
			animal[index] = new Cat();
		}
		else
			animal[index] = new Dog();
	}

	for (int index = 0; index < 10; index++)
	{
		animal[index]->makeSound();
	}

	for (int index = 0; index < 10; index++)
	{
		delete	animal[index];
	}

	delete [] animal;

	Cat cat1;
	std::stringstream idea;


	for (int index = 0; index < 20; index++)
	{
		idea << "new idea " << index << " cat 1";
		cat1.setAnIdea(index, idea.str());
		idea.str("");
	}
	
	std::cout << "cat1 ideas" << std::endl;
	for (int index = 0; index < 10; index++)
		std::cout << cat1.getAnIdea(index) << std::endl;

	Cat cat2;
	cat2 = cat1;

	std::cout << "cat2 ideas" << std::endl;
	cat2.getAllIdeas();
//==============================================//

	return (0);
}

