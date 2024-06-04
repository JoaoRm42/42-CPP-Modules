//
// Created by Neddy on 20/02/2024.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fdOut("Default") {
    csvReader();
    checkerInput();
}

BitcoinExchange::BitcoinExchange(std::string fdOut) : _fdOut(fdOut) {
    csvReader();
    checkerInput();
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

void BitcoinExchange::setNameFile(std::string name) {
    _fdOut = name;
}

std::string BitcoinExchange::getNameFile() {
    return (_fdOut);
}

/**
 * Prints the Bitcoin exchange rate map.
 * 
 * This function iterates over the Bitcoin exchange rate map and prints each currency
 * along with its corresponding exchange rate. The exchange rate is displayed with a
 * precision of 7 decimal places.
 */
void BitcoinExchange::printBTCMap() {
    std::map<std::string, float>::iterator it;
    for (it = btc.begin(); it != btc.end(); ++it) {
        std::cout << it->first << "," << std::setprecision(7) << it->second << std::endl;
    }
}

/**
 * Checks if all characters in a given string are digits.
 *
 * @param str The string to be checked.
 * @return True if all characters are digits, false otherwise.
 */
bool BitcoinExchange::checkerDigits(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

/**
 * Checks if a given year is a leap year.
 *
 * @param year The year to be checked.
 * @return True if the year is a leap year, false otherwise.
 */
bool BitcoinExchange::checkerLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return (true);
    }
    return (false);
}

void BitcoinExchange::csvReader() {
    std::ifstream openfile("data.csv");
    if (!openfile.is_open()) {
        throw CantOpenFileException();
    }

    std::string reader;
    std::getline(openfile, reader);
    while (std::getline(openfile, reader)) {
        std::istringstream isString(reader);

        std::string date;
        float btc_value;
        std::getline(isString, date, ',');
        isString >> btc_value;
        btc[date] = btc_value;
    }

    openfile.close();
}

void BitcoinExchange::checkerInput() {
    std::ifstream openfile(this->_fdOut.c_str());
    if (!openfile.is_open()) {
        throw CantOpenFileException();
    }

    std::string reader;
    if (!std::getline(openfile, reader)) {
        return ;
    }
    if (reader != "date | value") {
        throw FormatException();
    }
    while (std::getline(openfile, reader)) {
        checkerLine(reader);
    }
}

void BitcoinExchange::checkerLine(std::string &line) {
    if (!checkerDate(line)) {
        return ;
    }
    if (checkerPipes(line) == false) {
        return ;
    }
}

bool BitcoinExchange::checkerPipes(std::string &line) {
    int countpipes = 0;

    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == '|') {
            countpipes++;
        }
    }
    if (countpipes != 1) {
        std::cout << "Pipes Error" << std::endl;
        return (false);
    }
    return (true);
}

bool BitcoinExchange::checkerDate(std::string &line) {
    size_t position = line.find('|');

    std::string date = line.substr(0, position);

    date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());

    int mincount = 0;
    for (size_t i = 0; i < date.length(); i++) {
        if (line[i] == '-') {
            mincount++;
        }
    }

    if (mincount != 2) {
        std::cout << "Minus Error" << std::endl;
        return (false);
    }

    std::istringstream dateStream(date);
    std::string year, month, day;

    std::getline(dateStream, year, '-');
    std::getline(dateStream, month, '-');
    std::getline(dateStream, day);

    if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }

    if (checkerYear(year, date) == false || checkerMonth(month) == false || checkerDay(year, month, day) == false) {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }

    if (checkerValue(line, date) == false) {
        return (false);
    }

    return (true);
}

bool BitcoinExchange::checkerYear(std::string &year, std::string &date) {
    if (checkerDigits(year) == false) {
        return (false);
    }

    if (atoi(year.c_str()) < 2009 || date == "2009-01-01") {
        return (false);
    }

    return (true);
}

bool BitcoinExchange::checkerMonth(std::string &month) {
    if (checkerDigits(month) == false) {
        return (false);
    }

    if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12) {
        return (false);
    }

    return (true);
}

bool BitcoinExchange::checkerDay(std::string &year, std::string &month, std::string &day) {
    if (checkerDigits(day) == false) {
        return (false);
    }

    if (month == "02") {
        if (checkerLeapYear(atoi(year.c_str())) == true) {
            if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 29) {
                return (false);
            }
        } else {
            if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 28) {
                return (false);
            }
        }
    } else if (month == "04" || month == "06" || month == "09" || month == "11") {
        if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 30) {
            return (false);
        }
    } else {
        if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31) {
            return (false);
        }
    }

    return (true);
}

//bool BitcoinExchange::checkerValue(std::string &line, std::string &date) {
//    size_t position = line.find('|');
//
//    std::string value = line.substr(position + 1);
//
//    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
//
//    if (value.length() <= 0) {
//        std::cout << "Error: No correct Value" << std::endl;
//        return (false);
//    }
//
//    float numValue = atof(value.c_str());
//
//    if (numValue < 0.0) {
//        std::cout << "Error: number is not positive!" << std::endl;
//        return (false);
//    }
//
//    if (numValue > 1000.0) {
//        std::cout << "Error: Number is too big" << std::endl;
//        return (false);
//    }
//
//    int countdots = 0;
//
//    for (size_t i = 0; i < value.length(); i++) {
//        if (!checkerDigits(value[i]) && value[i] != '.') {
//            std::cout << "Error!" << line << std::endl;
//            return (false);
//        }
//
//        if (value[i] == '.')
//            countdots++;
//    }
//
//    if (countdots > 1 || !checkerDigits(value[0])) {
//        std::cout << "Error!" << line << std::endl;
//        return (false);
//    }
//
//    size_t dotsPosition = value.find('.');
//    if (dotsPosition != std::string::npos && !checkerDigits(value[dotsPosition + 1])) {
//        std::cout << "Error!" << line <<std::endl;
//        return (false);
//    }
//
//    BTCValueConverter(date, value);
//    return (true);
//}

bool	BitcoinExchange::checkerValue(std::string& line, std::string& date)
{
    size_t pos = line.find('|');

    std::string value = line.substr(pos + 1);
    // Remove all whitespaces
    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

    if(value.length() <= 0)
    {
        std::cout << "Error(5): bad input => " << line << std::endl;
        return false;
    }
    float numValue = atof(value.c_str());
    if (numValue < 0.0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (numValue > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    int dotCount = 0;
    for (size_t i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]) && value[i] != '.')
        {
            std::cout << "Error(6): bad input => " << line << std::endl;
            return false;
        }
        if(value[i] == '.')
            dotCount++;
    }
    if (dotCount > 1 || !isdigit(value[0]))
    {
        std::cout << "Error(7): bad input => " << line << std::endl;
        return false;
    }
    size_t dotPos = value.find('.');
    if(dotPos != std::string::npos && !isdigit(value[dotPos + 1]))
    {
        std::cout << "Error(8): bad input => " << line << std::endl;
        return false;
    }

    BTCValueConverter(date, value);
    return true;
}

void BitcoinExchange::BTCValueConverter(std::string& date, std::string& value) {
    float valueCalc;

    std::map<std::string, float>::iterator  it;

    for (it = btc.begin(); it != btc.end(); ++it) {
        if (date < it->first) {
            --it;
            valueCalc = it->second;
            break ;
        }
    }

    if (it == btc.end()) {
        --it;
        valueCalc = it->second;
    }

    float result = atof(value.c_str()) * valueCalc;
    std::cout << date << " => " << value << " = " << std::setprecision(7) << result << std::endl;
}