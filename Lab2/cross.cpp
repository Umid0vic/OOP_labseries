#include "cross.h"
#include <point.h>
#include <cmath>



using namespace ShapeLib;


Cross::Cross(){
    _thickness = 0;
    _length = 0;
    _pCenter = new Point(0,0);
}


Cross::Cross(const double thickness, const double length, const double centerX, const double centerY){
    _thickness = thickness;
    _length = length;
    _pCenter = new Point(centerX, centerY);
}


double Cross::getThickness() const{
    return _thickness;
}


double Cross::getLength() const{
    return _length;
}


double Cross::getArea() const{
    return (_thickness * _length * 2) - pow(_thickness, 2);
}


void Cross::setArea(const double newArea, const double newThickness){

}


double Cross::getCircumference() const{

}


void Cross::setCircumference(const double newCircumference){

}


bool Cross::contains(const Point *point) const{

}


void Cross::move(const double dx, const double dy){

}


double Cross::getLeft() const{

}


double Cross::getRight() const{

}


double Cross::getTop() const{

}


double Cross::getBottom() const{

}


void Cross::draw(QPainter *painter, const Qt::GlobalColor color) const{

}
