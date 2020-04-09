#pragma once

#include <QApplication>
#include <QString>

using std::string;

namespace ShapeLib{

    /**
    * A class representing a window to which text can be printed.
    *
    * This class represents a window that will be shown on the screen and to
    * which you can print text. Use the print*-methods to print different
    * values to the window, and after that call the start method to show the
    * window.
    */
    class TextWindow{

    public:

        /**
        * Creates a new window.
        */
        TextWindow();

        /**
        * Prints a string to this window
        *
        * @param theString The string to be printed.
        */
        void print(const char* theString);

        /**
        * Prints an int to this window.
        *
        * @param theInt The int to be printed.
        */
        void print(const int theInt);

        /**
        * Prints a double to this window.
        *
        * @param theDouble The double to be printed.
        */
        void print(const double theDouble);

        /**
        * Prints a newline character to this window.
        */
        void printLine();

        /**
        * Starts to show this window on the screen. This method returns when
        * the window is closed.
        */
        void start();

    private:
        QApplication app;
        QString output;

    };

}

