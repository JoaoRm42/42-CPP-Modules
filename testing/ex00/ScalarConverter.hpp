#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <climits>
# include <limits>
# include <cfloat>
# include <cmath>
# include <iomanip>
# include <cctype>
# include <cstdlib>
# include <sstream>

enum    e_type
{
    DEFAULT,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL_NAN,
    SPECIAL_INF,
    SPECIAL_NINF
};

class   ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const&);
        ScalarConverter& operator=(ScalarConverter const&);
        static int      _type;
        static double   _value;

    public:
        ~ScalarConverter();

        static void    convert(std::string const&);
};

class   NonDisplayableException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class   ImpossibleException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
