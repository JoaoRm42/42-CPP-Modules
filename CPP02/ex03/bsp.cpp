//
// Created by joaoped2 on 11/24/23.
//

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    const float aX, aY, bX, bY, cX, cY, pointX, pointY, Area, w1, w2, w3;

    a.xCoord() = aX;
    a.yCoord() = aY;
    b.xCoord() = bX;
    b.yCoord() = bY;
    c.xCoord() = cX;
    c.yCoord() = cY;
    point.xCoord() = pointX;
    point.yCoord() = pointY;

    Area = ((aX * bY + bX * cY + cX * aY) - (aY * bX + bY * cX + cY * aX) / 2);
    w1 = (((bY - cY) * (pointX - cX) + (cX - bX) * (pointY - cY)) / ((bY - cY) * (aX - cX) + (cX - bX) * (aY - cY)));
    w2 = (((cY - aY) * (pointX - cX) + (aX - cX) * (pointY - CY)) / ((bY - cY) * (aX - cX) + (cX - bX) * (aY - cY)));
    w3 = 1 - w1 - w2;

    if ((0 <= w1 <= 1) || (0 <= w2 <= 1) || (0 <= w3 <= 1))
        return (true);
    return (false);
}

