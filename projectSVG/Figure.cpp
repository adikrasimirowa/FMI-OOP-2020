#include "Figure.h"
#include <string>
#include "factory.h"

Figure *Figure::loadFigure(std::istream&in) {
    std::string type;
    in >> type;
    Figure *newFigure = FigureFactory::make(type);
    newFigure->load(in);
    return newFigure;
}

std::istream& operator>> (std::istream& in, std::vector<Figure*>& figures) {
    size_t nFigures;
    in >> nFigures;

    figures.clear();

    for (size_t i = 0; i < nFigures; ++i) {
        figures.push_back(Figure::loadFigure(in));
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, std::vector<Figure*> figures) {
    out << figures.size() << " ";
    for (int i = 0; i<figures.size();i++) {
        figures[i]->save(out);
    }
    return out;
}

Figure::~Figure(){}