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
    return Fixed(
        (p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) +
         p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) +
         p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() )) / 2.0f
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = calculateArea(a, b, c).toFloat();
    if (totalArea < 0) totalArea = totalArea * -1;
    Fixed area1 = calculateArea(point, b, c).toFloat();
    if (area1 < 0) area1 = area1 * -1;
    Fixed area2 = calculateArea(a, point, c).toFloat();
    if (area2 < 0) area2 = area2 * -1;
    Fixed area3 = calculateArea(a, b, point).toFloat();
    if (area3 < 0) area3 = area3 * -1;
    return (totalArea == (area1 + area2 + area3));
}