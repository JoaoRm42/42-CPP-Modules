//
// Created by Juanito on 04/12/2023.
//

#ifndef CPP_MODULES_42_SCAVTRAP_HPP
#define CPP_MODULES_42_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    public:
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap& scav );
        ScavTrap& operator = ( const ScavTrap& scav );
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &scav);

#endif //CPP_MODULES_42_SCAVTRAP_HPP
