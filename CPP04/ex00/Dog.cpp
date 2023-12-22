//
// Created by Juanito on 18/12/2023.
//

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Default Dog Constructor Called" << std::endl;
}

Dog::Dog(std::string type) {
    this->type = type;
    std::cout << "Parameter Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &cpy) {
    *this = cpy;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    this->type = dog.type;
    std::cout << "Dog Copy Assignment Constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

const void Dog::makeSound() {
    std::cout << "bark" << std::endl;
}