#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <iomanip>

#include "Figure.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Line.cpp"
#include "factory.cpp"
#include "helpers.cpp"
int main()
{ 
    init();
    std::string command;
    std::string fileName;
    std::vector<Figure*> figures;

    //--------Работа с командния ред--------///
    //не работи
    if(command == "open") {
        std::cin>>fileName;
        std::ifstream in (fileName);
        std::cout<<"Successfully opened "<<fileName<<std::endl;
        in>>figures;
    } else if(command =="save") {
        std::ofstream out (fileName);
        out<<figures;
        out.close();
        std::cout<<"Successfully saved"<< fileName<<std::endl;
    } else if(command =="saveas") {
        // Записва направените промени във файл, като позволява на потребителя да укаже неговия път.
        // > saveas "C:\Temp\another file.xml"
        std::cout<<"Successfully saved another \n";
    } else if(command == "help") {
        help();
    } else if(command == "exit") {
        std::cout<<"Exiting the program... \n";
        exit(0);
    } else if(command == "close") {
        std::cout<<"Successfully closed \n";
    }

    std::ifstream in ("figures.svg");    
    std::vector<Figure*> figures2;
    in>>figures2;
    for (size_t i = 0; i < figures2.size(); i++)
    {
             figures2[i]->print();
    }
}
