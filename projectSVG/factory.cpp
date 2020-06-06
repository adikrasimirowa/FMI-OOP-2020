#include "factory.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

/// създава "кух" обект, член-даните му са реализирани с различни стойности
Figure* FigureFactory::make(const std::string& type)
{
    Figure *newFigure = nullptr;
    if (type == "circle")
        newFigure = new Circle(0,0,0,"");
    else if (type == "rectangle")
        newFigure = new Rectangle(0,0,0,0,"");
    else if (type == "line")
        newFigure = new Line(0,0,0,0);
    else
        assert(false);

    return newFigure;
}