//
// Created by joaoped2 on 1/23/24.
//

#ifndef CPP_MODULES_42_SERIALIZATION_H
#define CPP_MODULES_42_SERIALIZATION_H

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
    int     a;
    int     b;
};

class Serialization {
    private:
        Serialization();
        Serialization(Serialization const&);
        ~Serialization();
        Serialization& operator=(Serialization const&);
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};


#endif //CPP_MODULES_42_SERIALIZATION_H
