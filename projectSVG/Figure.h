#pragma once
#include <iostream>
#include <vector>

///базов абстракртен клас
class Figure {

public:
    virtual void print() = 0;
    virtual void save(std::ostream&) = 0;
    virtual void load(std::istream&) = 0;
    virtual void translate(double vertical,double horizontal) = 0;

    static Figure *loadFigure(std::istream&in);

    virtual ~Figure();
  
};

/// потоци за вход и изход
std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures);
std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures);