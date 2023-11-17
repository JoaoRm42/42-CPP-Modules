//
// Created by joaoped2 on 11/17/23.
//

#ifndef CPP_MODULES_42_HARL_HPP
#define CPP_MODULES_42_HARL_HPP

#include <iostream>

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain( std::string level );
        Harl( void );
        ~Harl( void );
};

#endif //CPP_MODULES_42_HARL_HPP
