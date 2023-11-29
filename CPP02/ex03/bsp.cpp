//
// Created by joaoped2 on 11/24/23.
//

#include "Point.hpp"

float   absArea(float nr){
    if (nr < 0)
        return nr * -1;
    return nr;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float aX, aY, bX, bY, cX, cY, pointX, pointY, total, w1, w2, w3;

    aX = a.xCoord();
    aY = a.yCoord();
    bX = b.xCoord();
    bY = b.yCoord();
    cX = c.xCoord();
    cY = c.yCoord();
    pointX = point.xCoord();
    pointY = point.yCoord();

    total = absArea((aX * (bY - cY) + bX * (cY - aY) + cX * (aY - bY)) / 2);

    w1 = absArea((aX * (bY - pointY) + bX * (pointY - aY) + pointX * (aY - bY)) / 2);
    w2 = absArea((aX * (cY - pointY) + cX * (pointY - aY) + pointX * (aY - cY)) / 2);
    w3 = absArea((bX * (cY - pointY) + cX * (pointY - bY) + pointX * (bY - cY)) / 2);
    if (!w1 || !w2 || !w3)
        return false;
    if (total == (w1 + w2 + w3))
        return true;
    return false;
}

