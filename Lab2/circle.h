#pragma once

#include "point.h"
#include <QPainter>

namespace ShapeLib{

    /**
    * A class representing a circle with a position in a two-dimensional
    * plane.
    */
    class Circle{

    public:

        /**
        * Creates a new circle with the radius 0 positioned at origin.
        */
        Circle();

        /**
        * Creates a new circle with the given radius positioned at
        * (centerX, centerY).
        */
        Circle(const double _radius, const double centerX=0, const double centerY=0);

        /**
        * Returns this circle's radius.
        *
        * @return This circle's radius.
        */
        double getRadius() const;

        /**
        * Returns this circle's circumference.
        *
        * @return This circle's circumference.
        */
        double getCircumference() const;

        /**
        * Sets this circle's circumference to newCircumference.
        *
        * @parameter newCircumference This circles's new circumference.
        */
        void setCircumference(const double newCircumference);

        /**
        * Returns this circle's area.
        *
        * @return This circle's area.
        */
        double getArea() const;

        /**
        * Sets this circle's area to newArea.
        *
        * @parameter newArea This circle's new area.
        */
        void setArea(const double newArea);

        /**
        * Checks if point is located inside this circle.
        *
        * @parameter point The point to check for.
        * @return True if the point is inside this circle, otherwise false.
        */
        bool contains(const Point *point) const;

        /**
        * Moves this circle by dx in the x-direction and dy in the y-direction.
        *
        * @parameter dx The amount to move in the x-direction.
        * @parameter dy The amount to move in the y-direction.
        */
        void move(const double dx, const double dy);

        /**
        * Returns the x-coordinate for this circle's left side.
        *
        * @return The x-coordinate for this circle's left side.
        */
        double getLeft() const;

        /**
        * Returns the x-coordinate for this circle's right side.
        *
        * @return The x-coordinate for this circle's right side.
        */
        double getRight() const;

        /**
        * Returns the y-coordinate for this circle's top side.
        *
        * @return The y-coordinate for this circle's top side.
        */
        double getTop() const;

        /**
        * Returns the y-coordinate for this circle's bottom side.
        *
        * @return The y-coordinate for this circle's bottom side.
        */
        double getBottom() const;

        /**
        * Draws this circle with the provided background color and painter.
        */
        void draw(QPainter *painter, const Qt::GlobalColor color) const;

        ~Circle();

    private:
        double _radius;
        Point *_pCenter; // Allocated dynamically for demonstrating destructors.

    };

}
