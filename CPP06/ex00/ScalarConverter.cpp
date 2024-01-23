//
// Created by joaoped2 on 1/18/24.
//

#include "ScalarConverter.hpp"

int     ScalarConverter::_type;
double  ScalarConverter::_value;

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
    *this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy) {
    (void)cpy;
    return (*this);
}

ScalarConverter::~ScalarConverter() {

}

static void checkString(const std::string &str, int &type, double &value) {
    size_t  pos = 0;
    size_t  tmp = 0;

    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
    {
        value = static_cast<double>(str[0]);
        type = CHAR;
        return ;
    }
    tmp = str.find_first_not_of("-+", pos);
    if (tmp < std::string::npos)
        pos = tmp;
    tmp = str.find_first_not_of("0123456789", pos);
    if (tmp == std::string::npos || tmp < str.find_first_of(".fFeE", pos))
    {
        std::istringstream  iss(str.substr(0, tmp));
        iss >> value;
        if (iss.fail() || !iss.eof())
            type = DEFAULT;
        else if (value <= INT_MAX && value >= INT_MIN)
            type = INT;
        else
            type = DOUBLE;
        return ;
    }
    if (tmp == str.find_first_of("fF", pos))
    {
        value = strtod(str.c_str(), NULL);
        type = FLOAT;
        return ;
    }
    if (tmp == str.find_first_of(".eE", pos))
    {
        pos = tmp + 1;
        if (str.find_first_of("eE", tmp) < str.find_first_of(".", tmp))
            tmp = str.find_first_not_of("0123456789", pos);
        else
            tmp = str.find_first_not_of("eE0123456789", pos);
        std::istringstream  iss(str.substr(0, tmp));
        iss >> value;
        if (iss.fail() || !iss.eof())
            type = DEFAULT;
        else if (tmp < std::string::npos && tmp == str.find_first_of("fF", pos))
            type = FLOAT;
        else
            type = DOUBLE;
        return ;
    }
}

static void printChar(double const& value)
{
    if (!(value >= 0 && value <= 127))
        throw ScalarConverter::ImpossibleException();
    if (!isprint(static_cast<char>(value)))
        throw ScalarConverter::NonDisplayableException();
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double const& value)
{
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw ScalarConverter::ImpossibleException();
    std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double const& value)
{
    if (value < -FLT_MAX || \
        value > FLT_MAX)
    {
        throw ScalarConverter::ImpossibleException();
    }
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
    if (str.find("nan") == 0)
        _type = NNAN;
    else if (str.find("-inf") == 0)
        _type = NINF;
    else if (str.find("inf") <= 2)
        _type = INF;
    else
        checkString(str, _type, _value);
    if (_type > DEFAULT && _type <= DOUBLE)
    {
        std::cout << "char: ";
        try
        {
            printChar(_value);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "int: ";
        try
        {
            printInt(_value);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
    }
    switch (_type)
    {
        case DEFAULT:
            std::cout << "float : impossible" << std::endl;
            std::cout << "double : impossible" << std::endl;
            break ;
        case INF:
            std::cout << "float : inff" << std::endl;
            std::cout << "double : inf" << std::endl;
            break ;
        case NINF:
            std::cout << "float : -inff" << std::endl;
            std::cout << "double : -inf" << std::endl;
            break ;
        case NNAN:
            std::cout << "float : nanf" << std::endl;
            std::cout << "double : nan" << std::endl;
            break ;
        default:
            std::cout << "float: ";
            try
            {
                printFloat(_value);
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "double: " << std::fixed << std::setprecision(1) << _value << std::endl;
            break ;
    }
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
    return ("impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return ("Non displayable");
}