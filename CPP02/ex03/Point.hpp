//
// Created by joaoped2 on 11/24/23.
//

#ifndef CPP_MODULES_42_POINT_HPP
#define CPP_MODULES_42_POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point( void );
        Point( const float num1, const float num2 );
        Point( const Point& cpy );
        Point& operator=(const Point& point);
        ~Point();
        float xCoord( void ) const;
        float yCoord( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif //CPP_MODULES_42_POINT_HPP
