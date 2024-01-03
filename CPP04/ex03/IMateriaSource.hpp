//
// Created by joaoped2 on 12/29/23.
//

#ifndef CPP_MODULES_42_IMATERIASOURCE_HPP
#define CPP_MODULES_42_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //CPP_MODULES_42_IMATERIASOURCE_HPP
