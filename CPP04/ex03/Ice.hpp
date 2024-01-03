//
// Created by joaoped2 on 12/29/23.
//

#ifndef CPP_MODULES_42_ICE_HPP
#define CPP_MODULES_42_ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria {
    public:
        Ice();
        Ice(const Ice& cpy);
        Ice& operator = (const Ice& cpy);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif //CPP_MODULES_42_ICE_HPP
