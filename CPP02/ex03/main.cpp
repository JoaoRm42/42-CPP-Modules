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
    const Point a(10, 5);
    const Point b(7, 3);
    const Point c(2, 1);
    const Point target(1, 1);

    if (bsp(a, b, c, target))
        std::cout << "It's inside" << std::endl;
    else
        std::cout << "It's outside" << std::endl;
    return 0;
}

