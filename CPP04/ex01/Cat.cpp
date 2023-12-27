//
// Created by Juanito on 18/12/2023.
//

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->CatBrain = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(std::string type) {
    this->type = type;
    this->CatBrain = new Brain();
    std::cout << "Parameter Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat &cpy) {
    *this = cpy;
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    this->type = cat.type;
    this->CatBrain = new Brain(*cat.CatBrain);
    std::cout << "Cat Copy Assignment Contructor Called" << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete this->CatBrain;
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "miaow" << std::endl;
}

Brain *Cat::getBrain() const {
    return(this->CatBrain);
}