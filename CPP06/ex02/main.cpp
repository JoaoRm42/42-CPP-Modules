//
// Created by joaoped2 on 1/23/24.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base*   p;

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Test " << i << std::endl;
        p = generate();
        identify(p);
        identify(*p);
        delete p;
    }
    return 0;
}