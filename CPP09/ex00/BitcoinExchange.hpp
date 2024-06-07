/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:10 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 10:04:38 by joaoped2         ###   ########.fr       */
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
#include <limits>
#include <map>
#include<unistd.h>
#include <iterator>

class BitcoinExchange {
    private:
        std::string _file;
        std::map<int, std::string> _map;
        std::map<int, std::string> _mapcsv;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator = (const BitcoinExchange &cpy);
    public:
        BitcoinExchange(const std::string &file);
        ~BitcoinExchange();
        void filereader();
        int available_file();
        void parse_data();
        void populatecsvmap();
        int available_database();
        int is_leap_year(int year);
        bool check_digits(const std::string &reader);
        bool check_pipes(const std::string &reader);
        std::string ymd_valRet(const std::string &buffer, size_t pos, size_t npos);
        int utils_convert(const std::string &reader, size_t pos, size_t npos);
        int check_month(const std::string &reader);
        int check_day(const std::string &reader, int month, int year);
        int check_year(const std::string &reader);
        int check_value(const std::string &reader);
        void printMap(const std::map<int, std::string> &m);
        float value_convert(const std::string &reader, size_t pos, size_t npos);
        float value_convert_csv(const std::string &reader, size_t pos, size_t npos);
        int month;
        int year;
};

#endif
