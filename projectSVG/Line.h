#pragma once
#include "Figure.h"

class Line : public Figure
{
    public:
    Line (double _x1, double _y1, double _x2, double _y2);

    Line( const Line& other);
    Line& operator=(const Line& other);
    ~Line () ;

    void print();
    void save(std::ostream &out);
    void load(std::istream& in);
    void translate(double vertical,double horizontal);


    double getX1() const;

    void setX1(double x1);

    double getY1() const;

    void setY1(double y1);

    double getX2() const;

    void setX2(double x2);

    double getY2() const;

    void setY2(double y2);

private:
    ///координатите x1 и y1 на началото на линията
    ///координатите x2 и y2 на края на линията
    double x1,y1,x2,y2;
};