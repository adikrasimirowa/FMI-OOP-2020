#pragma once
#include "Figure.h"

///шаблон за дизайн - фабрика, иницилизира обект от йераргията на база на дадено правило без да имаме експлицитно класа
class FigureFactory
{
    public:
    static Figure* make(const std::string& type);

};