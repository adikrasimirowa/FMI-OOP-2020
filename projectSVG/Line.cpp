#include "Line.h"
// Line::Line (double _x1, double _y1, double _x2, double _y2){
//     x1 = _x1;
//     y1 = _y1;
//     x2 = _x2;
//     y2  = _y2;
// }

Line::Line (double _x1, double _y1, double _x2, double _y2):x1(_x1), y1(_y1),x2(_x2),y2(_y2){}

double Line::surface() {
    return 0;
}

void Line::save(std::ostream &out) {
    out << "line "<< x1 << " " << y1 << " " << x2 << " "<<y2; 
}

void Line::load(std::istream& in) {
    in >> x1 >> y1 >> x2 >> y2;
}

void Line::print() {
    std::cout<< x1 << " " << y1 << " " << x2 << " "<<y2; 
}

Figure *Line::copy() {
    return new Line(*this);
}