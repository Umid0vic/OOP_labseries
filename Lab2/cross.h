#pragma once

#include "point.h"
#include <QPainter>

namespace ShapeLib {


    class Cross{

    public:

        /*
        * creates a new cross with the thickness 0 and the length 0 positioned at the origin
        */
        Cross();

        /*
        * creates a new cross with the thickness (thickness) and the length (length) positioned at the center (center, centerY)
        */

        Cross(const double thickness, const double length, const double centerX, const double centerY);


        double getThickness() const;


        double getLength() const;


        double getArea() const;


        void setArea(const double newArea, const double newThickness);


        double getCircumference() const;


        void setCircumference(const double newCircumference);


        bool contains(const Point *point) const;


        void move(const double dx, const double dy);


        double getLeft() const;


        double getRight() const;


        double getTop() const;


        double getBottom() const;


        void draw(QPainter *painter, const Qt::GlobalColor color) const;

    private:

        double _thickness;
        double _length;
        Point *_pCenter;

    };



}


