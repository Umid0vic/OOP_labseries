#include "plus.h"
#include <point.h>
#include <cmath>



using namespace ShapeLib;


Plus::Plus(){
    _thickness = 0;
    _length = 0;
    _pCenter = new Point(0,0);
}


Plus::Plus(const double thickness, const double length, const double centerX, const double centerY){
    if(thickness > length){
        _thickness = length;
        _length = thickness;
    }else{
        _thickness = thickness;
        _length = length;
    }
    _pCenter = new Point(centerX, centerY);
}


double Plus::getThickness() const{
    return _thickness;
}


double Plus::getLength() const{
    return _length;
}


double Plus::getArea() const{
    return (_thickness * _length * 2) - pow(_thickness, 2);
}


void Plus::setArea(const double newArea, const double newThickness){
    _length = ((newArea / newThickness) + newThickness) / 2;
}


double Plus::getCircumference() const{
    return _length * 4;
}


void Plus::setCircumference(const double newCircumference, const double newThickness){
    _length = newCircumference / 4;
    _thickness = newThickness;
}


double Plus::getLeft() const{
    return _pCenter->getX() - _length/2;
}


double Plus::getRight() const{
    return _pCenter->getX() + _length/2;
}


double Plus::getTop() const{
    return _pCenter->getY() - _length/2;
}


double Plus::getBottom() const{
    return _pCenter->getY() + _length/2;
}


bool Plus::contains(const Point *point) const{
//    bool isInside = ( point->getX() > getLeft() && point->getX() < getRight()
//                    && point->getY() > _pCenter->getY() - (_thickness/2) && point->getY() < _pCenter->getY() + (_thickness/2) )
//                    &&( point->getY() > getTop() && point->getY() < getBottom()
//                    && point->getX() > _pCenter->getX() - (_thickness/2) && point->getX() < _pCenter->getX() + (_thickness/2) );
//    return isInside;

    // Vertical Rect
    double x1 = _pCenter->getX() - _thickness/2;
    double y1 = getTop();
    bool insideVertical = (point->getX() > x1 && point->getX() < x1 + _thickness)
                        && point->getY() > y1 && point->getY() < y1 + _length;

    // Horizontal Rect
    double x2 = getLeft();
    double y2 = _pCenter->getY() - _thickness/2;
    bool insideHorisontal = (point->getX() > x2 && point->getX() < x2 + _length)
                        && point->getY() > y2 && point->getY() < y2 + _thickness;

    return (insideVertical || insideHorisontal);
}


void Plus::move(const double dx, const double dy){
    _pCenter->changeX(dx);
    _pCenter->changeY(dy);
}


void Plus::draw(QPainter *painter, const Qt::GlobalColor color) const{
    //vertical rect
    double x1 = _pCenter->getX() - _thickness/2;
    double y1 = getTop();
    painter->fillRect(x1, y1, _thickness, _length, QBrush(color));

    //horisontal rect
    double x2 = getLeft();
    double y2 = _pCenter->getY() - _thickness/2;
    painter->fillRect(x2, y2, _length, _thickness, QBrush(color));
}
