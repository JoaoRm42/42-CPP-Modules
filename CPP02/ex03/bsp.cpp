//
// Created by joaoped2 on 11/24/23.
//

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float aX, aY, bX, bY, cX, cY, pointX, pointY, w1, w2, w3;

    aX = a.xCoord();
    aY = a.yCoord();
    bX = b.xCoord();
    bY = b.yCoord();
    cX = c.xCoord();
    cY = c.yCoord();
    pointX = point.xCoord();
    pointY = point.yCoord();

    // Using barycentric method
    w1 = (((bY - cY) * (pointX - cX) + (cX - bX) * (pointY - cY)) / ((bY - cY) * (aX - cX) + (cX - bX) * (aY - cY)));
    w2 = (((cY - aY) * (pointX - cX) + (aX - cX) * (pointY - cY)) / ((bY - cY) * (aX - cX) + (cX - bX) * (aY - cY)));
    w3 = 1 - w1 - w2;

    if ((w1 <= 1 && w1 >= 0) || (w2 <= 1 && w2 >= 0) ||(w3 <= 1 && w3 >= 0))
        return (true);
    return (false);
}

