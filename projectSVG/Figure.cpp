#include "Figure.h"
#include <string>
#include "factory.h"

///зарежда фигурата, като използва фабрика която създава обект от йерахията
Figure *Figure::loadFigure(std::istream&in) {

    std::string type;
    in >> type;

    Figure *newFigure = FigureFactory::make(type);

    newFigure->load(in);
    return newFigure;
}

/// оператор за входов поток
std::istream& operator>> (std::istream& in, std::vector<Figure*>& figures) {

    figures.clear();

    while (!in.eof()){
        figures.push_back(Figure::loadFigure(in));
    }
    return in;
}

///оператор за изходен поток
std::ostream& operator<< (std::ostream& out, std::vector<Figure*> figures) {

    for (int i = 0; i<figures.size();i++) {
        figures[i]->save(out);
    }
    return out;
}

///Диструктор
Figure::~Figure(){}