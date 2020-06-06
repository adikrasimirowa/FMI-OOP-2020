#include "Rectangle.h"


///Конструктор с параметри и списък с инициализатори на членове
Rectangle::Rectangle(double _x, double _y, double _width, double _height, std::string _fill)
:rx( _x),
ry(_y),
width( _width),
height(_height),
fill(_fill){}

/// Копиращ конструктор
Rectangle::Rectangle(const Rectangle &other) {
    setRx(other.rx);
    setRy(other.ry);
    setWidth(other.width);
    setHeight(other.height);
    setFill(other.fill);
}

///Оператор за присвояване - предефинираме =
Rectangle &Rectangle::operator=(const Rectangle &other) {
    if (this != &other) {
        setRx(other.rx);
        setRy(other.ry);
        setWidth(other.width);
        setHeight(other.height);
        setFill(other.fill);
    }
    return *this;
}

/// Диструктор
Rectangle::~Rectangle() {}

/// връща координатите rx
double Rectangle::getRx() const {
    return rx;
}

/// задава координатите yx
void Rectangle::setRx(double _rx) {
    if (_rx < 0) {
        rx = std::abs(_rx);
    } else {
        rx = _rx;
    }
}

/// връща координатите ry
double Rectangle::getRy() const {
    return ry;
}

/// задава координатите rx
void Rectangle::setRy(double _ry) {
    if (_ry < 0) {
        ry = std::abs(_ry);
    } else {
        ry = _ry;
    }
}

/// задава ширината на правоъгълника
double Rectangle::getWidth() const {
    return width;
}

/// задава ширината на правоъгъкника
void Rectangle::setWidth(double _width) {
    width = _width;
}

/// връща височината на правоъгълника
double Rectangle::getHeight() const {
    return height;
}

/// задава височината на правоъгълника
void Rectangle::setHeight(double _height) {
   height = _height;
}

/// връща цвета на фигурата
const std::string &Rectangle::getFill() const {
    return fill;
}

/// задава цвета на фигурата
void Rectangle::setFill(const std::string &_fill) {
    fill = _fill;
}

///записване в потока
void Rectangle::save(std::ostream &out)
{
    out << " rectangle " << rx << " " << ry << " "<<width<<" "<<height <<" "<<fill;
}

///зареждане от потока
void Rectangle::load(std::istream& in)
{
    in >> rx >> ry >> width >> height >> fill;
}

///извеждане на всички член данни
void Rectangle::print() {
    std::cout<<"rectangle "<<getRx()<<" "<<getRy()<<" "<<getWidth()<<" "<<getHeight() <<" "<<getFill()<<std::endl;
}

///транслира правоъгълника
void Rectangle::translate(double vertical, double horizontal) {
    rx = rx + std::abs(horizontal);
    ry = ry + std::abs(vertical);

}