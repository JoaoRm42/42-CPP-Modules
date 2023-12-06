//
// Created by Juanito on 04/12/2023.
//

#ifndef CPP_MODULES_42_DIAMONDTRAP_HPP
#define CPP_MODULES_42_DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
    private:
        std::string _name;
    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap& cpy);
        DiamondTrap& operator=(const DiamondTrap& diamondtrap);
        ~DiamondTrap();
        void attack(std::string target);
        void whoAmI(void);
        std::string GetDiamondTrapName( void ) const;
};

std::ostream	& operator<<(std::ostream & out, DiamondTrap const& diamondtrap);

#endif //CPP_MODULES_42_DIAMONDTRAP_HPP
