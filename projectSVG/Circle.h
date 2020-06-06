#pragma once
#include "Figure.h"

class Circle : public Figure
{
    public:
    Circle (double _x, double _y, double _r, std::string fill);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
     ~Circle();

    void print();
    void save(std::ostream &out);
    void load(std::istream& in);
    void translate(double vertical,double horizontal);

    double getCx() const;

    void setCx(double cx);

    double getCy() const;

    void setCy(double cy);

    double getR() const;

    void setR(double r);
    void setFill(const std::string &fill);

    const std::string &getFill() const;


private:
    ///атрибутите cx и cy определят координатите на центъра на кръга
    double cx,cy;

    ///свойството r описва радиуса на елемента "кръг".
    double r;
    std::string fill;
};