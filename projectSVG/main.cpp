#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cassert>

#include "Figure.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Line.cpp"
#include "factory.cpp"
#include "helpers.cpp"

int main()
{
    ///init(); //- при липса на файл с фигури
    std::string command;
    std::string fileName;
    std::vector<Figure*> figures;
    std::string figCommand;
    std::ifstream in;

    while (true) {

        std::cout<<std::endl<<"1.Type file/system command;\n2.Type 'help' for Help Menu;\n";

        if (!figures.empty()){
            std::cout<<"3. Type 'skip' to go to figure commands"<<std::endl;
        }

        std::cin >> command;

        ///Работа с командния ред

        if (!in.is_open()) {
            if (command == "open") {
                std::cin >> fileName;

                in.open(fileName);

                if (!in) {
                    std::cout << "Incorrect file name";
                }else if(figures.empty()) {
                    in>>figures;
                    std::cout<<"Successfully opened "<<fileName<<std::endl;
                }
                else {
                    std::cout << "Successfully opened " << fileName << std::endl;
                }
            }
        }


        if (in.is_open()) {
            if (command == "save") {
                std::ofstream out(fileName);
                out << figures;
                out.close();
                std::cout << "Successfully saved " << fileName << std::endl;
            } else if (command == "saveas") {
                /// Записва направените промени във файл, като позволява на потребителя да укаже неговия път.
                /// > saveas "C:\Temp\another file.xml"
                std::string newFileName;
                std::cin >> newFileName;
                std::ofstream newFile(newFileName);
                newFile << figures;
                newFile.close();
                std::cout << "Successfully saved in another file \n";
            }
        }

        if (command == "help") {
            help();
        } else if (command == "exit") {
            std::cout << "Exiting the program... \n";
            exit(0);
        } else if (command == "close") {
            in.close();
            std::cout << "Successfully closed \n";
        }


        if (!figures.empty()) {

            std::cout<<std::endl<<"Type the command you want : \n If you need to see what the commands type 'command'";
            std::cin >> figCommand;


            if (figCommand == "command"){
                commands();
            } else if (figCommand == "print") {

                for (size_t i = 0; i < figures.size(); i++) {

                    std::cout << i + 1 << ". ";
                    figures[i]->print();

                }

            } else if (figCommand == "create") {
                std::string type;
                std::cin >> type;

                if (type == "rectangle") {
                    double _x, _y, _width, _height;
                    std::string _fill;

                    std::cin >> _x >> _y >> _width >> _height >> _fill;
                    if (_x < 0 || _y < 0) {
                        _x = std::abs(_x);
                        _y = std::abs(_y);
                    }

                    figures.push_back(new Rectangle(_x, _y, _width, _height, _fill));
                    std::cout << "Successfully created rectangle" << figures.size();

                } else if (type == "circle") {
                    double _x, _y, _r;
                    std::string _fill;

                    std::cin >> _x >> _y >> _r>>_fill;
                    if (_x < 0 || _y < 0) {
                        _x = std::abs(_x);
                        _y = std::abs(_y);
                    }

                    figures.push_back(new Circle(_x, _y, _r,_fill));

                    std::cout << "Successfully created circle "<< figures.size();

                } else if (type == "line") {
                    double _x1, _y1, _x2, _y2;

                    std::cin >> _x1 >> _y1 >> _x2 >> _y2;

                    if (_x1 < 0 || _y1 < 0 || _x2 < 0 || _y2 < 0) {
                        _x1 = std::abs(_x1);
                        _y1 = std::abs(_y1);
                        _x2 = std::abs(_x2);
                        _y2 = std::abs(_y2);
                    }

                    figures.push_back(new Line(_x1, _y1, _x2, _y2));

                    std::cout << "Successfully created line " << figures.size();

                } else {
                    std::cout << "Invalid figure" << std::endl;
                }

            } else if (figCommand == "erase") {

                int position;
                std::cin >> position;
                figures.erase(figures.begin() + position);
                std::cout << "Successfully erased " << position;
            } else if (figCommand == "translate") {

                int position;
                double _vertical, _horizontal;

                std::cin >> position;
                std::cin >> _vertical >> _horizontal;

                if (position > figures.size() || position < 0) {
                    for (size_t i = 0; i < figures.size(); i++) {
                        figures[i]->translate(_vertical, _horizontal);
                    }

                } else {
                    figures[position]->translate(_vertical, _horizontal);
                }
                std::cout << "Successfully translated " << position;

            }
        }

    }
}
