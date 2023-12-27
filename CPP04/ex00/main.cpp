//
// Created by Juanito on 18/12/2023.
//

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

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
    delete i;
    delete j;
    delete meta;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    const WrongAnimal* meta1 = new WrongAnimal();
    const Animal* k = new Dog();
    const WrongAnimal* l = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    l->makeSound(); //will output the cat sound!
    k->makeSound();
    meta1->makeSound();
    delete l;
    delete k;
    delete meta1;

    return 0;
}
