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
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits ( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & out, Fixed const & num);

#endif //CPP_MODULES_42_FIXED_HPP
