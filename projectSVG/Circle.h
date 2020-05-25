#pragma once
#include "Figure.h"

class Circle : public Figure
{
    public:
    Circle (double _x, double _y, double _r);

    void print();
    double surface();
    void save(std::ostream &out);
    void load(std::istream& in);

    Figure *copy();

    private:
    double cx,cy;
    double r;
};