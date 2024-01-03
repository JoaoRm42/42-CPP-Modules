//
// Created by joaoped2 on 12/29/23.
//

#include "Cure.hpp"

Cure::Cure() {
    std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure &cpy) {
    *this = cpy;
    std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure &Cure::operator=(const Cure &cpy) {
    std::cout << "Cure Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

Cure::~Cure(){
    std::cout << "Cure Destructor Called" << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}