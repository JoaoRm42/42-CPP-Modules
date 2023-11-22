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

class Fixed{
    private:
        int number;
        static const int bitNumber = 8;
    public:
        Fixed();
        Fixed(const Fixed& cpy);
        Fixed& operator = (const Fixed& fixed);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits ( int const raw );
};

#endif //CPP_MODULES_42_FIXED_HPP
