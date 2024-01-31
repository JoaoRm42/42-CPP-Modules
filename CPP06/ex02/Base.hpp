//
// Created by joaoped2 on 1/23/24.
//

#ifndef CPP_MODULES_42_BASE_HPP
#define CPP_MODULES_42_BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class   Base {
    public:
        virtual ~Base() {};
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif //CPP_MODULES_42_BASE_HPP
