#pragma once

#include "point.h"
#include <QPainter>

namespace ShapeLib {


    class Plus{

    public:

        /*
        * creates a new cross with the thickness 0 and the length 0 positioned at the origin
        */
        Plus();

        /*
        * creates a new cross with the thickness (thickness) and the length (length) positioned at the center (center, centerY)
        */

        Plus(const double thickness, const double length, const double centerX, const double centerY);


        double getThickness() const;


        double getLength() const;


        double getArea() const;


        void setArea(const double newArea, const double newThickness);


        double getCircumference() const;


        void setCircumference(const double newCircumference, const double newThickness);


        bool contains(const Point *point) const;


        double getLeft() const;


        double getRight() const;


        double getTop() const;


        double getBottom() const;


        void move(const double dx, const double dy);


        void draw(QPainter *painter, const Qt::GlobalColor color) const;

    private:

        double _thickness;
        double _length;
        Point *_pCenter;

    };



}


