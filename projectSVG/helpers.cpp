void init() {
    std::vector<Figure*> figures = {
        new Circle(0,0,1),
        new Circle(3,0,2),
        new Rectangle(1,2),
        new Line(2,3,4,5)
    };

    std::ofstream out ("figures.svg");

    out<<figures;
    out.close();
}

void help() {
    std::cout<<"The following commands are supported: \n";
    std::cout<<"open <file>	    opens <file> \n";
    std::cout<<"close			closes currently opened file \n";
    std::cout<<"save			saves the currently open file \n";
    std::cout<<"saveas <file>	saves the currently open file in <file> \n";
    std::cout<<"help			prints this information \n";
    std::cout<<"exit			exists the program \n";
}
