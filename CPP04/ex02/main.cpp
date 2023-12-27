//
// Created by joaoped2 on 12/27/23.
//

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	seeBrainAnimal(void){				//Seeing that is a deep copy!
    Cat	cat;
    Cat	deepCat = cat;
    Dog	*dog = new Dog();
    Dog *deepDog = new Dog(*dog);

    std::cout << "------------Cat----------------------" << std::endl;
    std::cout << cat.getType() << std::endl;
    std::cout << cat.getBrain() << ". My name now is: Pepy " << std::endl;
    cat.setType("Peppy");
    std::cout << cat.getType();
    std::cout << std::endl;
    std::cout << deepCat.getBrain() << ": " << deepCat.getType();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------DOG--------------------" << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << dog->getBrain() << ": My name now is Bobby" << std::endl;

    dog->setType("Bobby");
    std::cout << dog->getType();
    std::cout << std::endl;
    std::cout << deepDog->getBrain() << ": " << deepDog->getType();
    std::cout << std::endl;
    std::cout << std::endl;

    delete deepDog;
    delete dog;
}

void	sheetTests(void){
    const Animal* j = new Dog();
    const Animal* x = new Cat();
    const Animal* array[10];

    for(int i = 0; i < 5; i++)
        array[i] = new Dog();

    for(int i = 5; i < 10; i++)
        array[i] = new Cat();

    for(int i = 0; i < 10; i++)
        array[i]->makeSound();

    for(int i = 0; i < 10; i++){
        std::cout << array[i]->getType();
        delete array[i];
    }

    //delete [] array; this doesnt work as the array isnt allocated!
    delete j;//should not create a leak
    delete x;
}

int main()
{
    sheetTests();
    std::cout << std::endl;
    seeBrainAnimal();
    return 0;
}