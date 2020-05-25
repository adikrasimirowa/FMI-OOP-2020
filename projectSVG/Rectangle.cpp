#include "Rectangle.h"

// Rectangle::Rectangle (double _x, double _y) {
//     rx = _x;
//     ry = _y;
// }

Rectangle::Rectangle (double _x, double _y):rx( _x),ry(_y){}

double Rectangle::surface()
{
    return rx*ry;
}

void Rectangle::save(std::ostream &out)
{
    out << "rect " << rx << " " << ry << " "; 
}

void Rectangle::load(std::istream& in)
{
    in >> rx >> ry;
}

Figure *Rectangle::copy()
{
    return new Rectangle(*this);
}

void Rectangle::print() {
    std::cout<<std::endl<<"rectangle "<<rx<<" "<<ry<<std::endl;
}