//
// Created by joaoped2 on 1/3/24.
//

#ifndef CPP_MODULES_42_MATERIASOURCE_HPP
#define CPP_MODULES_42_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>
#include <cstring>

class MateriaSource: public IMateriaSource {
    private:
        AMateria* spells[4];
        int index;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const& cpy);
        MateriaSource& operator=(MateriaSource const& cpy);
        ~MateriaSource();

        void learnMateria(AMateria* learn);
        AMateria* createMateria(std::string const& type);
};


#endif //CPP_MODULES_42_MATERIASOURCE_HPP
