#pragma once
#include "Figure.h"

class FigureFactory
{
    public:
    static Figure* make(std::string type);

};