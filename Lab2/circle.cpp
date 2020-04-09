#include "circle.h"
#include <point.h>
#include <cmath>


using namespace ShapeLib;




Circle::Circle(){
    _radius = 0;
    _pCenter = new Point(0, 0);
}


Circle::Circle(const double radius, const double centerX, const double centerY){
    _radius = radius;
    _pCenter = new Point(centerX, centerY);
}


double Circle::getRadius() const{
    return _radius;
}


double Circle::getCircumference() const{
    return M_PI * 2 * _radius;
}


void Circle::setCircumference(const double newCircumference){
    this->_radius = newCircumference / (M_PI * 2);
}


double Circle::getArea() const{
    return M_PI * pow(_radius, 2);
}


void Circle::setArea(const double newArea){
    _radius = sqrt(newArea/M_PI);
}


double Circle::getLeft() const {
    return _pCenter->getX() - _radius;
}


double Circle::getRight() const {
    return _pCenter->getX() + _radius;
}


double Circle::getTop() const {
    return _pCenter->getY() - _radius;
}


double Circle::getBottom() const{
    return _pCenter->getY() + _radius;
}


bool Circle::contains(const Point *point) const{
    return (_pCenter->getDistanceTo(*point) <= _radius );
}


void Circle::draw(QPainter *painter, const Qt::GlobalColor color) const{
    painter->setBrush(QBrush(color));
    painter->drawEllipse(_pCenter->getX() - _radius, _pCenter->getY() - _radius, _radius * 2, _radius * 2);
}

Circle::~Circle(){
    delete _pCenter;
}
















