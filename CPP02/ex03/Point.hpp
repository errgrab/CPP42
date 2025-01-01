#pragma once
#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(const Fixed x, const Fixed y);
    Point(const Point& point);
    ~Point();

    Point& operator=(const Point& point);

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);