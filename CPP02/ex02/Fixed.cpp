/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:25:02 by joaoped           #+#    #+#             */
/*   Updated: 2023/11/22 12:25:02 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const int integer) {
    std::cout << "Int constructor called" << std::endl;
    this->number = integer << this->bitNumber;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(number * (1 << this->bitNumber));
}

Fixed::Fixed(const Fixed &cpy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->number = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return ((float)this->number / (1 << this->bitNumber));
}

int Fixed::toInt() const {
    return (this->number >> this->bitNumber);
}

int Fixed::getRawBits() const {
//    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}

void Fixed::setRawBits(const int raw) {
//    std::cout << "getRawBits member function called" << std::endl;
    this->number = raw;
}

std::ostream & operator<<(std::ostream & out, Fixed const & num){
    out << num.toFloat();
    return out;
}