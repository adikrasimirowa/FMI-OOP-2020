// СПОМАГАТЕЛНИ ФУНКЦИИ

///създава начални данни във файла на фигурите
void init() {
    std::vector<Figure*> figures = {
        new Circle(0,0,1,"red"),
        new Circle(3,0,2,"yellow"),
        new Rectangle(1,2,100,200,"blue"),
        new Line(2,3,4,5)
    };

    std::ofstream out ("./figures.svg");

    out<<figures;
    out.close();
}

///помощно меню
void help() {
    std::cout<<"The following commands are supported: \n";
    std::cout<<"open <file>	    opens <file> \n";
    std::cout<<"close			closes currently opened file \n";
    std::cout<<"save			saves the currently open file \n";
    std::cout<<"saveas <file>	saves the currently open file in <file> \n";
    std::cout<<"help			prints this information \n";
    std::cout<<"exit			exists the program \n";
}

///Меню с инструкции
void commands() {

    std::cout<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"print"<<"Prints all figures"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"create"<<"Creates new figure"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"erase"<<"Erases figure"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"translate"<<"Translates figure"<<std::endl;
}
