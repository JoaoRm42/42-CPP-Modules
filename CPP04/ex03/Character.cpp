//
// Created by joaoped2 on 1/3/24.
//

#include "Character.hpp"

Character::Character() {
    this->name = "Default";
    this->index = 0;
    for(int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
        this->drop[i] = NULL;
    }
    std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string name) {
    this->name = name;
    this->index = 0;
    for(int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
        this->drop[i] = NULL;
    }
    std::cout << "Character Parameter Constructor Called" << std::endl;
}

Character::Character(const Character &cpy) {
    *this = cpy;
    std::cout << "Character Copy Constructor Called" << std::endl;
}

Character &Character::operator=(const Character &cpy) {
    if (*this == &obj)
        return (*this);
    this->name = cpy.name;
    this->index = cpy.index;
    for(int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete (this->inventory[i]);
        if (this->drop[i])
            delete (this->drop[i]);
        if (cpy.inventory[i])
            this->inventory[i] = cpy.inventory[i]->clone();
        if (cpy.drop[i])
            this->drop[i] = cpy.drop[i]->clone();
    }
    std::cout << "Character Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

Character::~Character() {
    for(int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL)
            delete (this->inventory[i]);
        if (this->drop[i] != NULL)
            delete(this->drop[i]);
    }
    std::cout << "Character Destructor Called" << std::endl;
}

void Character::equip(AMateria *spell) {
    if (this->index > 3) {
        std::cout << "Character doesn't have enough inventory space!" << std::endl;
        delete (spell);
        return ;
    }
    this->inventory[this->index] = spell;
    this->index++;
}

void Character::unequip(int index) {
    if (index < 0 || index > 3) {
        std::cout << "Character only has 4 inventory slots" << std::endl;
        return ;
    }
    if (this->inventory[index] == NULL) {
        return ;
    }
    this->drop[index] = this->inventory[index];
    this->inventory[index] = NULL;
    std::cout << this->name << " dropped " << this->drop[index]->getType() << std::endl;
    std::cout << "The memory of the spell dropped is " << this->drop[index] << std::endl;
    this->index--;
}

void Character::use(int index, ICharacter &target) {
    if (index < 0 || index > 3) {
        std::cout << "Character only has 4 inventory slots" << std::endl;
        return ;
    }
    if (this->inventory[index] == NULL) {
        std::cout << "Character doesn't have a spell in that slot" << std::endl;
        return ;
    }
    this->inventory[index]->use(target);
}

std::string const &Character::getName() const {
    return (this->name);
}