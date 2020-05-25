#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "helpers.cpp"
#include "Room.cpp"

int main() {
init();
std::vector<Room> rooms;
std::string command;
std::string fileName;
std::string commandRoom;

std::cout<<"Type open and files name to see rooms:\n";
std::cin>>command;

//--------Работа с командния ред--------///
if(command == "open") {
    std::cin>>fileName;
    std::ifstream in (fileName);
    std::cout<<"Successfully opened "<<fileName<<std::endl;
    in>>rooms;
} else if(command =="save") {
    std::ofstream out (fileName);
    out<<rooms;
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

//---------Меню с инструкции------//
std::cout<<std::endl;
std::cout<<"Welcome to the computer reservations system \n";
std::cout<<std::setw(21)<<std::left<<"checkin"<<"Regidtration in room"<<std::endl;
std::cout<<std::setw(21)<<std::left<<"availability"<<"List of free rooms for <date>"<<std::endl;
std::cout<<std::setw(21)<<std::left<<"checkout"<<"Checkout a room"<<std::endl;
std::cout<<std::setw(21)<<std::left<<"report"<<"Report of rooms for <dates>"<<std::endl;
std::cout<<std::setw(21)<<std::left<<"find"<<"Finds free room"<<std::endl;
std::cout<<std::setw(21)<<std::left<<"find!"<<"Quick find "<<std::endl;
std::cout<<std::setw(21)<<std::left<<"unavailable"<<"Make room unavailible"<<std::endl;
std::cout<<"Type the command you want : \n";

std::cin>>commandRoom;

//-----Изпълнение на команди----//
if(commandRoom == "checkin") {
   std::string fromDate;
    std::string toDate;
    std::string note;
    int room;

    std::cin>>room>>fromDate>>toDate>>note;

    for(size_t i=0; i < rooms.size(); i++) {
        
        if(rooms[i].getRoom() == room) {
            rooms[i].chekin(fromDate, toDate,note);
        }

    }
    
} else if(commandRoom =="availability") {

    std::string date;
    std::cin>>date;
    for(size_t i=0; i < rooms.size(); i++) {
        rooms[i].availability(date);
    }

} else if(commandRoom =="checkout") {
   
    int room;
    for(size_t i=0; i < rooms.size(); i++) {
        if(rooms[i].getRoom() == room) {
            rooms[i].checkout(room);
        }
    }

} else if(commandRoom == "report") {
   
    std::string fromDate;
    std::string toDate;
    std::cin>>fromDate>>toDate;
    report( fromDate, toDate, rooms);

} else if(commandRoom == "find") {
  
   std::cout<<"Coming soon";

} else if(commandRoom == "find!") {
    
    std::cout<<"Coming soon";

}else if(commandRoom == "unavailable") {
    
    int room;
    std::string note;
    std::string fromDate;
    std::string toDate;
    std::cin>>room>>fromDate>>toDate>>note;
    for(size_t i=0; i < rooms.size(); i++) {
        if(rooms[i].getRoom() == room) {
            rooms[i].unavailable(fromDate, toDate, note);
        }
    }
    
}

}
