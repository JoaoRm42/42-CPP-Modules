/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:38:23 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/30 03:27:43 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
