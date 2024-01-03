//
// Created by joaoped2 on 1/3/24.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    this->index = 0;
    for(int i = 0; i < 4; i++) {
        this->spells[i] = NULL;
    }
//    std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cpy) {
    this->index = cpy.index;
    for(int i = 0; i < 4; i++) {
        this->spells[i] = cpy.spells[i];
    }
//    std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy) {
    if (this == &cpy)
        return (*this);
    for(int i = 0; i < 4; i++) {
        this->spells[i] = cpy.spells[i];
    }
//    std::cout << "MateriaSource Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource() {
    for(int i = 0; i < this->index; i++) {
        delete (this->spells[i]);
    }
//    std::cout << "MateriaSource Destructor Called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *learn) {
    if (this->index == 3)
        return ;
    this->spells[this->index++] = learn;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for(int i = 0; i < this->index; i++) {
        if (this->spells[i]->getType() == type) {
            return (this->spells[i]->clone());
        }
    }
    return (NULL);
}