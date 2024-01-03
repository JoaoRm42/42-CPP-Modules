//
// Created by joaoped2 on 12/29/23.
//

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
//    std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy) {
//    std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice &Ice::operator=(const Ice &cpy) {
    if (this == &cpy)
        return (*this);
    this->type = cpy.type;
//    std::cout << "Ice Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

Ice::~Ice() {
//    std::cout << "Ice Destructor Called" << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}