#pragma once
#include <iostream>
#include <vector>

class Figure {

public:
    virtual double surface() = 0;
    virtual void print() = 0;
    virtual void save(std::ostream&) = 0;
    virtual void load(std::istream&) = 0;

    static Figure *loadFigure(std::istream&in);

    virtual Figure *copy()=0;

    virtual ~Figure();
  
};

std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures);
std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures);
