//
// Created by joaoped2 on 11/24/23.
//

#include "Point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(const float num1, const float num2) : x(num1), y(num2) {

}

Point::Point(const Point &cpy) : x(cpy.x), y(cpy.y) {

}

Point &Point::operator=(const Point &point) {
    (Fixed)this->x = point.x;
    (Fixed)this->y = point.y;
    return (*this);
}

Point::~Point() {

}

const float Point::xCoord( void ) {
    return (x.toFloat());
}

const float Point::yCoord( void ) {
    return (y.toFloat());
}