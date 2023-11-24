/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:25:44 by joaoped           #+#    #+#             */
/*   Updated: 2023/11/22 12:25:44 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MODULES_42_FIXED_HPP
#define CPP_MODULES_42_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int number;
        static const int bitNumber = 8;
    public:
        Fixed();
        Fixed( const int integer );
        Fixed ( const float number );
        Fixed( const Fixed& cpy );
        Fixed& operator = ( const Fixed& fixed );
        bool operator > ( const Fixed& fixed )const;
        bool operator < ( const Fixed& fixed )const;
        bool operator >= ( const Fixed& fixed )const;
        bool operator <= ( const Fixed& fixed )const;
        bool operator == ( const Fixed& fixed )const;
        bool operator != ( const Fixed& fixed )const;
        Fixed operator + ( const Fixed& fixed )const;
        Fixed operator - ( const Fixed& fixed )const;
        Fixed operator * ( const Fixed& fixed )const;
        Fixed operator / ( const Fixed& fixed )const;
        Fixed& operator ++ ( void );
        Fixed& operator -- ( void );
        Fixed operator ++ ( int );
        Fixed operator -- ( int );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits ( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        const static Fixed& min( const Fixed& a, const Fixed& b );
        static Fixed& min( Fixed& a, Fixed& b );
        const static Fixed& max( const Fixed& a, const Fixed& b );
        static Fixed& max( Fixed& a, Fixed& b );
};

std::ostream & operator<<(std::ostream & out, Fixed const & num);

#endif //CPP_MODULES_42_FIXED_HPP
