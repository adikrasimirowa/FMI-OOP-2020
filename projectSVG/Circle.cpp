#include "Circle.h"

///Конструктор с параметри и списък с инициализатори на членове
Circle::Circle (double _x, double _y, double _r,std::string _fill):cx(_x),cy(_y),r(_r), fill(_fill){}

/// Копиращ конструктор
Circle::Circle(const Circle &other) {
    setCx(other.cx);
    setCy(other.cy);
    setR(other.r);
    setFill(other.fill);
}

///Оператор за присвояване - предефинираме =
Circle &Circle::operator=(const Circle &other) {
    if (this != &other) {
        setCx(other.cx);
        setCy(other.cy);
        setR(other.r);
        setFill(other.fill);
    }
    return *this;
}

/// Диструктор
Circle::~Circle() {}

/// връща координата cx на центъра на кръга
double Circle::getCx() const {
    return cx;
}

///задава стойност на cy на центъра на кръга
void Circle::setCx(double _cx) {
    if (_cx < 0 ) {
        cx = std::abs(_cx);
    } else {
        cx = _cx;
    }
}

/// връща координата cy на центъра на кръга
double Circle::getCy() const {
    return cy;
}

///задава стойност на cy на центъра на кръга
void Circle::setCy(double _cy) {
    if ( _cy < 0) {
        cy = std::abs(_cy);
    } else {
        cy = _cy;
    }
}

/// връща радиуса на кръга
double Circle::getR() const {
    return r;
}

/// задава стойност на радиуса
void Circle::setR(double _r) {
    if (r < 0 ) {
        r = std::abs(_r);
    } else {
        r = _r;
    }
}

/// връща цвета на фигурата
const std::string &Circle::getFill() const {
    return fill;
}

/// задава цвета на фигурата
void Circle::setFill(const std::string &_fill) {
    fill = _fill;
}

///записване в потока
void Circle::save(std::ostream &out) {
    out << " circle "<< cx << " " << cy << " " << r <<" "<<fill;
}

///зареждане от потока
void Circle::load(std::istream& in) {
    in >> cx >> cy >> r>> fill;
}

///извеждане на всички член данни
void Circle::print() {
    std::cout<<"circle"<<" "<<getCx()<< " " <<getCy()<<" "<<getR()<<" "<<getFill()<<std::endl;
}

///транслира  кръга
void Circle::translate(double vertical, double horizontal) {
    cx = cx + std::abs(horizontal);
    cy = cy + std::abs(vertical);
}
