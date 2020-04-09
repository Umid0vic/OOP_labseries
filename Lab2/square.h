#pragma once

#include "point.h"
#include <QPainter>

namespace ShapeLib{

    /**
    * A class representing a square with a position in a two-dimensional
    * plane.
    */
    class Square{

    public:

        /**
        * Creates a new square with the side length 0 positioned at
        * origin.
        */
        Square();

        /**
        * Creates a new square with the side length sideLength positioned
        * at (centerX, centerY).
        */
        Square(const double _sideLength, const double centerX=0, const double centerY=0);

        /**
        * Returns this square's side length.
        *
        * @return This square's side length.
        */
        double getSideLength() const;

        /**
        * Returns this square's circumference.
        *
        * @return This square's circumference.
        */
        double getCircumference() const;

        /**
        * Sets this square's circumference to newCircumference.
        *
        * @parameter newCircumference This square's new circumference.
        */
        void setCircumference(const double newCircumference);

        /**
        * Returns this square's area.
        *
        * @return This square's area.
        */
        double getArea() const;

        /**
        * Sets this square's area to newArea.
        *
        * @parameter newArea This square's new area.
        */
        void setArea(const double newArea);

        /**
        * Checks if point is located inside this square.
        *
        * @parameter point The point to check for.
        * @return True if the point is inside this square, otherwise false.
        */
        bool contains(const Point *point) const;

        /**
        * Move this square by dx in the x-direction and dy in the y-direction.
        *
        * @parameter dx The amount to move in the x-direction.
        * @parameter dy The amount to move in the y-direction.
        */
        void move(const double dx, const double dy);

        /**
        * Returns the x-coordinate for this square's left side.
        *
        * @return The x-coordinate for this square's left side.
        */
        double getLeft() const;

        /**
        * Returns the x-coordinate for this square's right side.
        *
        * @return The x-coordinate for this square's right side.
        */
        double getRight() const;

        /**
        * Returns the y-coordinate for this square's top side.
        *
        * @return The y-coordinate for this square's top side.
        */
        double getTop() const;

        /**
        * Returns the y-coordinate for this square's bottom side.
        *
        * @return The y-coordinate for this square's bottom side.
        */
        double getBottom() const;

        /**
        * Draws this square with the provided background color and painter.
        */
        void draw(QPainter* painter, const Qt::GlobalColor backgroundColor) const;

        ~Square();

    private:
        double _sideLength;
        Point *_pCenter; // Allocated dynamically for demonstrating destructors.

    };

}
