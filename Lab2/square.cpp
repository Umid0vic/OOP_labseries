#include "square.h"
#include <point.h>
#include <cmath>


using namespace ShapeLib;


Square::Square()
{
    _sideLength = 0;
    _pCenter = new Point(0, 0);
}


Square::Square(const double sideLength, const double centerX, const double centerY)
{
    _sideLength = sideLength;
    _pCenter = new Point(centerX, centerY);
}


double Square::getSideLength() const {
    return _sideLength;
}


double Square::getCircumference() const {
    return _sideLength * 4;
}


void Square::setCircumference(const double newCircumference){
    _sideLength = newCircumference / 4;
}


double Square::getArea() const {
    return _sideLength * _sideLength;
}


void Square::setArea(const double newArea){
    _sideLength = sqrt(newArea);
}


double Square::getLeft() const {
    return _pCenter->getX() - (_sideLength/2);
}


double Square::getRight() const {
    return _pCenter->getX() + (_sideLength/2);
}


double Square::getTop() const {
    return _pCenter->getY() - (_sideLength/2);
}


double Square::getBottom() const{
    return _pCenter->getY() + (_sideLength/2);
}


bool Square::contains(const Point *point) const {
    return (point->getX() < getRight() && point->getX() > getLeft() &&
            point->getY() < getBottom() && point->getY() > getTop());
}


void Square::move(const double dx, const double dy){
    _pCenter->changeX(dx);
    _pCenter->changeY(dy);
}


void Square::draw(QPainter *painter, const Qt::GlobalColor backgroundColor) const {
    painter->fillRect(_pCenter->getX() - _sideLength/2, _pCenter->getY() - _sideLength/2, _sideLength, _sideLength, backgroundColor);
}


Square::~Square(){
    delete _pCenter;
}




