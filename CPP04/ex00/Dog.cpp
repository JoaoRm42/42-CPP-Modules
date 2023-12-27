//
// Created by Juanito on 18/12/2023.
//

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(std::string type) {
    this->type = type;
    std::cout << " Dog Parameter Constructor Called" << std::endl;
}

Dog::Dog(const Dog &cpy) {
    *this = cpy;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    this->type = dog.type;
    std::cout << "Dog Copy Assignment Constructor called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bark" << std::endl;
}