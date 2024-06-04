/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:10 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/03 16:03:04 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cctype>
#include <fstream>
#include <ctype.h>
#include <string>
#include <sstream>


class BitcoinExchange {
    private:
        std::string _file;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &file);
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator = (const BitcoinExchange &cpy);
        ~BitcoinExchange();
        bool date_checker(char &str);
        void filereader();
};

#endif