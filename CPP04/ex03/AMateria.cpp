//
// Created by joaoped2 on 12/27/23.
//

#include "AMateria.hpp"

AMateria::AMateria() {
    this->type = "Default";
    std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria(const std::string &type) {
    this->type = type;
    std::cout << "AMateria Parameter Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy) {
    *this = cpy;
    std::cout << "AMateria Copy Constructor Called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &cpy) {
    if (this == &obj)
            return (*this);
    this->type = cpy.type;
    std::cout << "AMateria Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria Destructor Called" << std::endl;
}

const std::string &AMateria::getType() const {
    return (this->type);
}

void AMateria::use(int &target) {
    std::cout << "Attacked " << target.getName() << std::endl;
}
