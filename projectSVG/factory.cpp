#include "factory.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

Figure* FigureFactory::make(std::string type)
{
    Figure *newFigure = nullptr;
    if (type == "circle")
        newFigure = new Circle(0,0,0);
    else if (type == "rect")
        newFigure = new Rectangle(0,0);
    else if (type == "line")
        newFigure = new Line(0,0,0,0);
    else
        assert(false);

    return newFigure;
}