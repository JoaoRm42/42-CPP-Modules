#include "ScalarConverter.hpp"

const char* NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

const char* ImpossibleException::what() const throw()
{
    return ("impossible");
}
