#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
    public:
    Rectangle (double _x, double _y);

    void print();
    double surface();
    void save(std::ostream &out);
    void load(std::istream& in);

    Figure *copy();

    private:
    double rx,ry;
};