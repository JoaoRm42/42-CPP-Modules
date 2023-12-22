//
// Created by Juanito on 18/12/2023.
//

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(std::string type) {
    this->type = type;
    std::cout << "Parameter Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat &cpy) {
    *this = cpy;
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    this->type = cat.type;
    std::cout << "Cat Copy Assignment Contructor Called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called" << std::endl;
}

const void Cat::makeSound() {
    std::cout << "miaow" << std::endl;
}