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
//    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const int integer) {
//    std::cout << "Int constructor called" << std::endl;
    this->number = integer << this->bitNumber;
}

Fixed::Fixed(const float number) {
//    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(number * (1 << this->bitNumber));
}

Fixed::Fixed(const Fixed &cpy) {
//    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
//    std::cout << "Copy assignment operator called" << std::endl;
    this->number = fixed.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
    if (this->number > fixed.number)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &fixed) const {
    if (this->number < fixed.number)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &fixed) const {
    if (this->number >= fixed.number)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &fixed) const {
    if (this->number <= fixed.number)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &fixed) const {
    if (this->number == fixed.number)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &fixed) const {
    if (this->number != fixed.number)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return (this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++( void ) {
    this->number++;
    return (*this);
}

Fixed &Fixed::operator--( void ) {
    this->number--;
    return (*this);
}

Fixed Fixed::operator++( int ) {
    Fixed tmp = *this;
    this->number++;
    return (tmp);
}

Fixed Fixed::operator--( int ) {
    Fixed tmp = *this;
    this->number--;
    return (tmp);
}

Fixed::~Fixed() {
//    std::cout << "Destructor called" << std::endl;
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

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if(a > b)
        return (b);
    return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if(a > b)
        return (b);
    return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if(a > b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if(a > b)
        return (a);
    return (b);
}

std::ostream & operator<<(std::ostream & out, Fixed const & num){
    out << num.toFloat();
    return out;
}