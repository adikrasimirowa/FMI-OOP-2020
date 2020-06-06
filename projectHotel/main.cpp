#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <ctime>       /* time_t, struct tm, time, localtime, strftime */
#include "helpers.cpp"
#include "Room.cpp"

int main() {
///init(); //- при липса на файл със стаи
std::vector<Room> rooms;
std::string command;
std::string fileName;
std::string commandRoom;
std::ifstream in;

while (true) {
    std::cout<<std::endl<<"1.Type file/system command;\n2.Type 'help' for Help Menu;\n";

    if (!rooms.empty()){
        std::cout<<"3. Type 'skip' to go to Hotel system commands"<<std::endl;
    }

    std::cin>>command;

    ///Работа с командния ред

    if (!in.is_open()) {
        if(command == "open") {
            std::cin>>fileName;

            in.open(fileName);

            if (!in) {
                std::cout<<"Incorrect file name";
            } else if(rooms.empty()){
                in>>rooms;
                std::cout<<"Successfully opened "<<fileName<<std::endl;
            } else {
                std::cout<<"Successfully opened "<<fileName<<std::endl;
            }
        }
    }


    if (in.is_open()) {
        if(command =="save") {
            std::ofstream out (fileName);
            out<<rooms;
            out.close();
            std::cout<<"Successfully saved "<< fileName<<std::endl;
        } else if(command =="saveas") {
            /// Записва направените промени във файл, като позволява на потребителя да укаже неговия път.
            /// > saveas "C:\Temp\another file.xml"
            std::string newFileName;
            std::cin>>newFileName;
            std::ofstream newFile (newFileName);
            newFile<<rooms;
            newFile.close();
            std::cout<<"Successfully saved as\n";
        }
    }

    if(command == "help") {
        help();
    } else if(command == "exit") {
        std::cout<<"Exiting the program... \n";
        exit(0);
    } else if(command == "close") {
        in.close();
        std::cout<<"Successfully closed \n";
    }

    if (!rooms.empty()) {
        std::cout<<std::endl<<"Type the command you want : \n If you need to see what the commands type 'command'";
        std::cin>>commandRoom;

        ///Изпълнение на команди
        if (commandRoom == "command"){
            commands();
        } else if(commandRoom == "checkin") {
           std::string fromDate;
           std::string toDate;
           std::string note;
           int room;

           std::cin>>room>>fromDate>>toDate;
           getline(std::cin,note);

           if (dateValidator(fromDate) && dateValidator(toDate)) {
               for(size_t i=0; i < rooms.size(); i++) {

                   if(rooms[i].getRoom() == room) {
                       rooms[i].checkin(fromDate, toDate,note);
                   }
               }
           } else {
               std::cout<<"Invalid date"<<std::endl;
           }



        } else if(commandRoom =="availability") {

            std::string date;
            std::cin>>date;
            if (date.empty()) {
                date = currentDate();
            }

            if (dateValidator(date)) {
                for (size_t i = 0; i < rooms.size(); i++) {
                    rooms[i].availability(date);
                }
            } else {
                std::cout<<"Invalid Date"<<std::endl;
            }

        } else if(commandRoom =="checkout") {

            int room;
            std::cin>>room;

            for(size_t i=0; i < rooms.size(); i++) {
                if(rooms[i].getRoom() == room) {
                    rooms[i].checkout(room);
                }
            }

        } else if(commandRoom == "report") {

            std::string fromDate;
            std::string toDate;
            std::cin>>fromDate>>toDate;

            if (dateValidator(fromDate) && dateValidator(toDate)) {
                report(fromDate, toDate, rooms);
            } else {
                std::cout<<"Invalid date"<<std::endl;
            }
        } else if(commandRoom == "find") {

            size_t beds;
            std::string fromDate;
            std::string toDate;

            std::cin>>beds>>fromDate>>toDate;

            if(beds <= 0) {
                beds = 1;
            }

            if (dateValidator(fromDate) && dateValidator(toDate)) {
                find(beds, fromDate, toDate, rooms);
            }

        } else if(commandRoom == "find!") {
            std::cout<<"Coming soon";

        } else if(commandRoom == "unavailable") {

            int room;
            std::string note;
            std::string fromDate;
            std::string toDate;

            std::cin>>room>>fromDate>>toDate;
            getline(std::cin,note);

            if (dateValidator(fromDate) && dateValidator(toDate)) {
                for (size_t i = 0; i < rooms.size(); i++) {
                    if (rooms[i].getRoom() == room) {
                        rooms[i].unavailable(fromDate, toDate, note);
                    }
                }
            }

        } else {
            std::cout<<"Incorrect Command"<<std::endl;
        }
    }
}
}