#pragma once
#include "Figure.h"

class Line : public Figure
{
    public:
    Line (double _x1, double _y1, double _x2, double _y2);
    double surface();
    void print();
    void save(std::ostream &out);
    void load(std::istream& in);

    Figure *copy();

    private:
    double x1,y1,x2,y2;
};