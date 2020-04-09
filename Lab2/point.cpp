#include "point.h"
#include <cmath>


using namespace ShapeLib;



Point::Point()
{
    _x=0;
    _y=0;
}

Point::Point(const double x, const double y):
    _x(x), _y(y)
{}


double Point::getX() const {
    return _x;
}


double Point::getY() const {
    return _y;
}


void Point::setX(const double newX){
    _x = newX;
}


void Point::setY(const double newY){
    _y = newY;
}


bool Point::isSameAs(const Point *otherPoint) const {
    return (otherPoint->getX() == _x && otherPoint->getY() == _y);
}


void Point::setTo(const Point &otherPoint){
    _x = otherPoint.getX();
    _y = otherPoint.getY();
}


double Point::getDistanceTo(const Point otherPoint) const {
    return sqrt(pow(otherPoint.getX()-_x, 2) + pow(otherPoint.getY()-_y, 2));
}


void Point::changeX(const double dx){
    _x += dx;
}


void Point::changeY(const double dy){
    _y += dy;
}




