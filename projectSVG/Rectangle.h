#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
    public:
    Rectangle (double _x, double _y, double _width, double _height, std::string _fill);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();

    void print();

    void save(std::ostream &out);
    void load(std::istream& in);
    void translate(double vertical,double horizontal);

    double getRx() const;

    void setRx(double rx);

    double getRy() const;

    void setRy(double ry);

    double getWidth() const;

    void setWidth(double width);

    double getHeight() const;

    void setHeight(double height);

    const std::string &getFill() const;

    void setFill(const std::string &fill);

private:

    /// координатите x и y се отнасят за левия и горния ръб на правоъгълника, в текущата координатна система
    double rx,ry;
    double width, height;
    std::string fill;
};