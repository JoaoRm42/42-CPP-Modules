//
// Created by Juanito on 04/12/2023.
//

#ifndef CPP_MODULES_42_FRAGTRAP_HPP
#define CPP_MODULES_42_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap( std::string );
        FragTrap( const FragTrap& frag );
        FragTrap& operator = ( const FragTrap& frag);
        ~FragTrap( void );
        void attack(const std::string& target);
        void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &out, const FragTrap &frag);

#endif //CPP_MODULES_42_FRAGTRAP_HPP
