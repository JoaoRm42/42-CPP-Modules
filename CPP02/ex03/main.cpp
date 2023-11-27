/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:14:05 by joaoped           #+#    #+#             */
/*   Updated: 2023/11/22 12:14:05 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

int main( void ) {
    system("clear");
    while (1) {
        float aX, aY, bX, bY, cX, cY, pointX, pointY;

        std::cout << "X coordinates for 'a'" << std::endl;
        std::cin >> aX;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "Y coordinates for 'a'" << std::endl;
        std::cin >> aY;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "X coordinates for 'b'" << std::endl;
        std::cin >> bX;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "Y coordinates for 'b'" << std::endl;
        std::cin >> bY;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "X coordinates for 'c'" << std::endl;
        std::cin >> cX;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "Y coordinates for 'c'" << std::endl;
        std::cin >> cY;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "X coordinates for 'target'" << std::endl;
        std::cin >> pointX;
        if (std::cin.eof())
            return (1);
        system("clear");
        std::cout << "Y coordinates for 'target'" << std::endl;
        std::cin >> pointY;
        if (std::cin.eof())
            return (1);
        system("clear");

        const Point a(aX, aY);
        const Point b(bY, bY);
        const Point c(cX, cY);
        const Point target(pointX, pointY);

        if (bsp(a, b, c, target))
            std::cout << "It's inside" << std::endl;
        else
            std::cout << "It's outside" << std::endl;
        usleep(2000000);
        system("clear");
    }
    return 0;
}

