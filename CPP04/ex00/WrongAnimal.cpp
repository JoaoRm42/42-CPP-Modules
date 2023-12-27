//
// Created by Juanito on 18/12/2023.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "Not an animal";
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    this->type = type;
    std::cout << "WrongAnimal Parameter Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
    *this = cpy;
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    this->type = animal.type;
    std::cout << "WrongAnimal Assignment Copy Constructor Called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Virtual Destructor Called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}

void WrongAnimal::setType(std::string type) {
    this->type = type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Not an animal Sound" << std::endl;
}