#include "Circle.h"

// Circle::Circle (double _x, double _y, double _r){
//     cx = _x;
//     cy = _y;
//     r  = _r;
// }

Circle::Circle (double _x, double _y, double _r):cx(_x),cy(_y),r(_r){}

double Circle::surface() {
    return 3.14*r*r;
}

void Circle::save(std::ostream &out) {
    out << "circle "<< cx << " " << cy << " " << r << " "; 
}

void Circle::load(std::istream& in) {
    in >> cx >> cy >> r;
}

void Circle::print() {
    std::cout<<cx<< " " <<cy<<" "<<r;
}
Figure *Circle::copy() {
    return new Circle(*this);
}