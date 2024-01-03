//
// Created by joaoped2 on 12/29/23.
//

#ifndef CPP_MODULES_42_CURE_HPP
#define CPP_MODULES_42_CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
    public:
        Cure();
        Cure(const Cure& cpy);
        Cure& operator = (const Cure& cpy);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif //CPP_MODULES_42_CURE_HPP
