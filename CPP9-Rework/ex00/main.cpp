/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:14 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/03 16:01:34 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
        BitcoinExchange btc(argv[1]);
    else {
        std::cout << "Error: could not open file." << std::endl;
        std::cout << "Usage: ./btc [File]." << std::endl;
    }
    return 0;
}