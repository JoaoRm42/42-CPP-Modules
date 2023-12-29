//
// Created by joaoped2 on 12/27/23.
//

#ifndef CPP_MODULES_42_AMATERIA_HPP
#define CPP_MODULES_42_AMATERIA_HPP


class AMateria {
    protected:

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& cpy);
        AMateria& operator = (const AMateria& cpy);
        ~AMateria();

        //Utility Functions
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};


#endif //CPP_MODULES_42_AMATERIA_HPP
