#include <textwindow.h>
#include <drawwindow.h>
#include <point.h>
#include <square.h>
#include <circle.h>



using namespace ShapeLib;

//Function declarations:
void printPoint(TextWindow &textW, Point point);
Point averagePoint(Point points[], int numberOfPoints);
Point closestToOrigin(Point &point1, Point *point2);
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();




int main(int argc, char *argv[])
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();

    return 0;
}


void printPoint(TextWindow &textW, Point point)
{
    textW.print(" (");
    textW.print(point.getX() );
    textW.print(", ");
    textW.print(point.getY() );
    textW.print(") ");
}


Point averagePoint(Point points[], int numberOfPoints)
{
    double averageX, averageY, xTot = 0.0, yTot = 0.0;

    for(int i=0; i<numberOfPoints; i++)
    {
        xTot = points[i].getX()+xTot;
        yTot = points[i].getY()+yTot;
    }
    averageX = xTot/numberOfPoints;
    averageY = yTot/numberOfPoints;

    return Point(averageX, averageY);

}


Point closestToOrigin(Point &point1, Point *point2)
{
    Point origin(0,0);
    Point closestP;

    if(point1.getDistanceTo(origin) > point2->getDistanceTo(origin))
        return *point2;
    else
        return point1;
}


void task1()
{
    TextWindow textW;
    textW.print(" Hello, world!");
    textW.start();
}


//Prints out the distance between the point and the origin
void task2()
{
    TextWindow textW;
    Point origin(0, 0);
    Point point(7, 3);
    double distance = point.getDistanceTo(origin);

    textW.print("The distance from origin to");
    printPoint(textW, point);
    textW.print(") is");
    textW.print(distance);
    textW.start();
}



void task3()
{
    TextWindow textW;
    Point point1(1, 2);
    Point point2(3, 4);

    textW.print("Before: ");
    printPoint(textW, point1);
    printPoint(textW, point2);
    textW.printLine();

    point2.setTo(point1); //changes point2 to point1

    textW.print("After:   ");
    printPoint(textW, point1);
    printPoint(textW, point2);
    textW.start();
}


//Checks if given points are the same
void task4()
{
    TextWindow textW;
    Point point1(3, 4);
    Point point2(4, 3);

    if(point1.isSameAs(&point2))
        textW.print("It is the same point");
    else
        textW.print("It is not the same point");
    textW.start();
}


//Prints out the the average point // ayyub töpalangchisdkalfhdsaljfhöufgadshfvjöasdhfk
void task5()
{
    TextWindow textW;
    Point points[3];
    Point averageP;

    points[0] = Point(1, 4);
    points[1] = Point(5, 3);
    points[2] = Point(2, 2);
    averageP = averagePoint(points, 3);
    textW.print("The average point is ");
    printPoint(textW, averageP);
    textW.start();
}


// Prints out the closest point to origin
void task6()
{
    TextWindow textW;
    Point point1(2, 5);
    Point point2(3, 4);
    textW.print("Closest point to origin is ");
    printPoint(textW, closestToOrigin(point1, &point2));
    textW.start();
}


// prints out the sum of the areas of the objects
void task7()
{
    TextWindow textW;
    Square square1(3.5, 0, 0);
    Square square2;
    Circle circle1(1.6, 0, 0);
    Circle circle2;
    Circle circle3;
    square2.setCircumference(13);
    circle2.setArea(6);
    circle3.setCircumference(5);

    double areaSum;
    areaSum = square1.getArea() + square2.getArea() + circle1.getArea() + circle2.getArea() + circle3.getArea();
    textW.print("The sum of the areas is ");
    textW.print(areaSum);
    textW.start();
}


// Checks if the square contains the point
void task8()
{
    TextWindow textW;
    Point point(10, 10);
    Square square(3, 8, 8);

    if(square.contains(&point))
        textW.print("The square contains the point");
    else
        textW.print("The square does not contains the point");
    textW.start();
}


// Checks if the circle contains the point
void task9()
{
    TextWindow textW;
    Point point(10, 10);
    Circle circle(3, 8, 8);

    if(circle.contains(&point))
        textW.print("The cirlce contains the point");
    else
        textW.print("The circle does not contains the point");
    textW.start();
}


void task10()
{
    DrawWindow drawX(600, 600);
    QPainter *painter = drawX.getPainter();
    QPen pen(Qt::red, 20);
    painter->setPen(pen);
    painter->drawLine(0 , 0, 600, 600);
    painter->drawLine(600, 0, 0, 600);

    drawX.commitPainterChanges();
    drawX.start();
}


void task11()
{
    DrawWindow drawFace(600, 600);
    QPainter *painter =drawFace.getPainter();
    Circle face(100, 300, 300);
    Circle leftEye(15, 270, 275);
    Circle rightEye(15, 330, 275);
    face.draw(painter, Qt::yellow);
    leftEye.draw(painter, Qt::white);
    rightEye.draw(painter, Qt::white);
    painter->drawRect(270, 325, 60, 20);

    drawFace.commitPainterChanges();
    drawFace.start();

}


void task12()
{
    DrawWindow drawSquare(600, 600);
    QPainter *painter = drawSquare.getPainter();
    int sideLength = 60;
    Square square(sideLength, 300, 300);

    drawSquare.setInterval(15,  [&](){
        painter->fillRect(0, 0, 600, 600,QBrush(Qt::black));
        square.draw(painter, Qt::red);
        square.move(-2, 0);

        if(square.getLeft() > 600){
            square.move(-600-sideLength, 0);
        }
        else if(square.getRight() < 0){
            square.move(600+sideLength, 0);
        }
        else if(square.getTop() > 600){
            square.move(0, -600-sideLength);
        }
        else if(square.getBottom() < 0){
            square.move(0, 600+sideLength);
        }
        drawSquare.commitPainterChanges();
    });
    drawSquare.start();
}
