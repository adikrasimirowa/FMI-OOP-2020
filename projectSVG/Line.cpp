#include "Line.h"

///Конструктор с параметри и списък с инициализатори на членове
Line::Line (double _x1, double _y1, double _x2, double _y2):x1(_x1), y1(_y1),x2(_x2),y2(_y2){}

/// Копиращ конструктор
Line::Line(const Line &other) {
    setX1(other.x1);
    setX2(other.x2);
    setY1(other.y1);
    setY2(other.y2);
}

///Оператор за присвояване - предефинираме =
Line &Line::operator=(const Line &other) {
    if (this != &other) {
        setX1(other.x1);
        setX2(other.x2);
        setY1(other.y1);
        setY2(other.y2);
    }

    return *this;
}

/// Деструктор
Line::~Line() {}

/// връща координата x1 на началото на линията
double Line::getX1() const {
    return x1;
}

//// задава стойност на координата x1 на началото на линията
void Line::setX1(double _x1) {

    if (_x1 > 0 ) {
        x1 = std::abs(_x1);
    } else {
        x1 = _x1;
    }
}

/// връща координата y1 на началото на линията
double Line::getY1() const {
    return y1;
}

/// задава стойност на координатаа y1 на началото на линията
void Line::setY1(double _y1) {
    if ( _y1 < 0 ) {
        y1 = std::abs(_y1);
    } else {
        y1 = _y1;
    }
}

/// връща координата x2 на началото на линията
double Line::getX2() const {
    return x2;
}

/// задава стойност на координатаа x2 на края на линията
void Line::setX2(double _x2) {
    if ( _x2 < 0 ) {
        x2 = std::abs(_x2);
    } else {
        x2 = _x2;
    }
}

/// връща координата y2 на началото на линията
double Line::getY2() const {
    return y2;
}

/// задава стойност на координатаа y2 на края на линията
void Line::setY2(double _y2) {
    if (_y2 < 0) {
        y2 = std::abs(_y2);
    } else {
        y2 = _y2;
    }
}

///записване в потока
void Line::save(std::ostream &out) {
    out << " line "<< x1 << " " << y1 << " " << x2 << " "<<y2;
}

///зареждане от потока
void Line::load(std::istream& in) {
    in >> x1 >> y1 >> x2 >> y2;
}

///извеждане на всички член данни
void Line::print() {
    std::cout<<"line" << " "<<getX1() << " " << getY1() << " " << getX2() << " "<<getY2()<<std::endl;
}

///транслира линията
void Line::translate(double vertical, double horizontal) {
    x1 = x1 + std::abs(horizontal);
    y1 = y1 + std::abs(vertical);
    x2 = x2 + std::abs(horizontal);
    y2 = y2 + std::abs(vertical);
}


