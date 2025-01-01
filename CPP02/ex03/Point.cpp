#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}
Point::Point(Point const &point) : _x(point.getX()), _y(point.getY()) {}
Point::~Point() {}

Point& Point::operator=(const Point& point) {
    (void)point;
    return *this;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

static Fixed calculateArea(Point const& p1, Point const& p2, Point const& p3) {
    Fixed area = (
        (p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) +
         p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) +
         p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() )) / 2.0f);
    return area < Fixed(0) ? area * Fixed(-1) : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);
    if (totalArea == Fixed(0) || area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    return (totalArea == (area1 + area2 + area3));
}