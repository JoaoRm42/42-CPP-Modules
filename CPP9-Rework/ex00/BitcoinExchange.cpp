/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:06 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 10:04:59 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _file("Default"), _map(), _mapcsv(), month(0), year(0) {}

BitcoinExchange::BitcoinExchange(const std::string &file) : _file(file), _map(), _mapcsv(), month(0), year(0) {
    filereader();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    (void)cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
    (void)cpy;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

int BitcoinExchange::is_leap_year(int year) {
    if (year % 4 != 0) {
        return (0);
    }
    else if (year % 100 == 0 && year % 400 != 0) {
        return (0);
    }
    else
        return (1);
}

bool BitcoinExchange::check_digits(const std::string &reader) {
    for (size_t i = 0; reader[i]; ++i) {
        if (!isdigit(reader[i])) {
            std::cout << "Error: bad input => " << reader << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::check_pipes(const std::string &reader) {
    size_t number_pipes = 0;
    for (size_t i = 0; reader[i]; i++) {
        if (reader[i] == '|') {
            number_pipes += 1;
        }
    }
    if (number_pipes == 1)
        return true;
    else {
        std::cout << "Error: bad input => " << reader << std::endl;
        return false;
    }
}

std::string BitcoinExchange::ymd_valRet(const std::string &buffer, size_t pos, size_t npos) {
    std::string year_str = buffer.substr(pos, npos);
    return (year_str);
}

int BitcoinExchange::utils_convert(const std::string &reader, size_t pos, size_t npos) {
    std::string year_str = reader.substr(pos, npos);
    if (!check_digits(year_str))
        return (0);
    int value;
    std::stringstream ss(year_str);
    ss >> value;
    return (value);
}

float BitcoinExchange::value_convert(const std::string &reader, size_t pos, size_t npos) {
    std::string year_str = reader.substr(pos, npos);
    float value;
    std::stringstream ss(year_str);
    ss >> value;
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return (1001);
    } else if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return (1001);
    }
    return (value);
}

float BitcoinExchange::value_convert_csv(const std::string &reader, size_t pos, size_t npos) {
    std::string year_str = reader.substr(pos, npos);
    float value;
    std::stringstream ss(year_str);
    ss >> value;
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return (1001);
    }
    return (value);
}

int BitcoinExchange::check_month(const std::string &reader) {
    if (reader[7] != '-') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    int month = utils_convert(reader, 5, 2);
    if (month < 1 || month > 12) {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    return (month);
}

int BitcoinExchange::check_day(const std::string &reader, int month, int year) {
    if (!isdigit(reader[8]) || reader[10] != ' ' || reader[11] != '|') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    int day = utils_convert(reader, 8, 2);
    if ((day == 1 && month == 1 && year == 2009) || (year == 2022 && month >= 04) || (year > 2022)) {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    if (is_leap_year(year) == 1 && month == 2 && day <= 29) {
        return 1;
    } else if (is_leap_year(year) == 0 && month == 2 && day <= 28) {
        return 1;
    } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
        return 1;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
        return 1;
    } else {
        std::cout << "Error: bad input => " << reader << std::endl;
        return 0;
    }
}

int BitcoinExchange::check_year(const std::string &reader) {
    if (reader[4] != '-') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    std::string year_str = reader.substr(0, 4);
    int year = utils_convert(year_str, 0, 4);
    if (year < 2009) {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    return (year);
}

int BitcoinExchange::check_value(const std::string &reader) {
    float value = value_convert(reader, 13, 1000);
    return (value);
}

int BitcoinExchange::available_database() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1002);
    }
    file.close();
    return (0);
}

int BitcoinExchange::available_file() {
    std::ifstream file(this->_file.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1002);
    }
    file.close();
    return (0);
}

void BitcoinExchange::printMap(const std::map<int, std::string> &m) {
    std::map<int, std::string>::const_iterator it = m.begin();

    while (it != m.end()) {
        std::cout << "Iterator state: " << &it << ", Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
}

void BitcoinExchange::populatecsvmap() {
    std::ifstream openfile("data.csv");

    std::string buffer;
    size_t i = 0;
    while(std::getline(openfile, buffer)) {
        if (i != 0) {
            this->_mapcsv[i] = buffer;
            i++;
        } else
            i++;
    }
    openfile.close();
}

void BitcoinExchange::parse_data() {
    std::map<int, std::string>::const_iterator it = this->_mapcsv.begin();
    std::map<int, std::string>::const_iterator it2 = this->_map.begin();

    while (it2 != this->_map.end())
        ++it2;
    --it2;
    while (it2 != this->_map.end()) {
        it = this->_mapcsv.begin();
        std::string input_value = ymd_valRet(it2->second, 0, 10);
        std::string input_ym = ymd_valRet(it2->second, 0, 7);
        int input_d = utils_convert(it2->second, 8, 2);
        while (it != this->_mapcsv.end()) {
            std::string csv_value = ymd_valRet(it->second, 0, 10);
            std::string csv_ym = ymd_valRet(it->second, 0, 7);
            int csv_d = utils_convert(it->second, 8, 2);
            if (csv_ym == input_ym) {
                if (csv_d == input_d) {
                    float csv_val = value_convert_csv(it->second, 11, 100);
                    float list_val = value_convert(it2->second, 13, 100);
                    float final_value = csv_val * list_val;
                    std::cout << input_value << " => " << list_val << " = " << final_value << std::endl;
                    break;
                } else if (csv_d > input_d) {
                    --it;
                    float csv_val = value_convert_csv(it->second, 11, 100);
                    float list_val = value_convert(it2->second, 13, 100);
                    float final_value = csv_val * list_val;
                    std::cout << input_value << " => " << list_val << " = " << final_value << std::endl;
                    break;
                } else if (csv_d < input_d && csv_ym == "2022-03" && input_ym == "2022-03" && csv_d == 29 && (input_d == 30 || input_d == 31)) {
                    float csv_val = value_convert_csv(it->second, 11, 100);
                    float list_val = value_convert(it2->second, 13, 100);
                    float final_value = csv_val * list_val;
                    std::cout << input_value << " => " << list_val << " = " << final_value << std::endl;
                    break;
                }
            }
            ++it;
        }
        break;
    }
}

void BitcoinExchange::filereader() {
    if (available_database() == 1002)
        return;
    else if (available_file() == 1002)
        return ;
    populatecsvmap();
    std::ifstream openfile(this->_file.c_str());
    size_t i = 0;
    std::string reader;
    while(std::getline(openfile, reader)) {
        if (i != 0) {
            if (check_pipes(reader)) {
                int month = check_month(reader);
                int year = check_year(reader);
                if (month!= 0 && year!= 0) {
                    if (check_day(reader, month, year)!= 0) {
                        if (check_value(reader)!= 1001) {
                            int nextKey = _map.size();
                            this->_map.insert(std::make_pair(nextKey, reader));
                            parse_data();
                        }
                    }
                }
            }
        } else {
            i++;
        }
    }
    openfile.close();
    // printMap(_mapcsv);
}
