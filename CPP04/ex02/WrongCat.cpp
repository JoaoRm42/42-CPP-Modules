//
// Created by Juanito on 18/12/2023.
//

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "Wrong Cat";
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(std::string type) {
    this->type = type;
    std::cout << "WrongCat Parameter Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) {
    *this = cpy;
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cpy) {
    this->type = cpy.type;
    std::cout << "WrongCat Assignment Copy Constructor Called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Bip bop" << std::endl;
}