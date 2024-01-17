/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:38:33 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/09 17:26:58 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    switch (rand() % 3)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (0);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void    identify(Base& p)
{
    try
    {
        A&  a = dynamic_cast<A&>(p);

        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e)
    {
        try
        {
            B&  b = dynamic_cast<B&>(p);

            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception& e)
        {
            try
            {
                C&  c = dynamic_cast<C&>(p);

                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception& e)
            {
                std::cout << "Error" << std::endl;
            }
        }
    }
}
