#include "Room.h"

Room::Room() {
    room = 100;
    fromDate = "2020-10-27";
    toDate = "2020-10-27";
    note = "";
    status = false;
    numberOfguests = 0;
    beds = 2;
}

Room::Room(size_t _room,size_t _beds,std::string _fromDate, std::string _toDate, std::string _note, bool _status)
    :room(_room),
    beds(_beds),
    fromDate(_fromDate),
    toDate(_toDate),
    note(_note),
    status(_status){}


// checkin <room> <from> <to> <note> [<guests>]
// Регистриране в стая с номер <room> от дата <from> до дата <to> и се добавя бележка <note>. Незадължителният параметър <guests> задава броя на гостите, настанени в стаята. Ако той не е указан, се счита, че броят на настанените гости е равен на броя на леглата в стаята.
// Пример: checkin 229 2020-03-23 2020-03-31 The Simpsons

void Room::chekin(std::string _fromDate, std::string _toDate, std::string _note) {
    fromDate = _fromDate;
    toDate = _toDate;
    note = _note;
    status = true;
    numberOfguests = beds;
}


// availability [<date>]
// Извежда списък на свободните стаи на дата <date>, ако не е зададена, се използва текущата дата.

void Room::availability(std::string date){
    if(date==fromDate) {
        if(!status){
            std::cout<<"Availabile rooms: "<<room<<std::endl;
        }
    }
} 


// checkout <room>
// Освобождаване на заета стая с номер <room>.

void Room::checkout(size_t room) {
    note = "";
    numberOfguests = 0;
    status = false;
}

// unavailable <room> <from> <to> <note>
// Обявява стаята с номер <room> от дата <from> до дата <to> за временно недостъпна и се добавя бележка <note>.
// В стаята няма регистриран гост, но никой не може да бъде настанен в нея.
// Пример:
// unavailable 200 2018-06-01 2019-03-01 Under construction
void Room::unavailable(std::string _fromDate, std::string _toDate, std::string _note) {
    note = _note;
    numberOfguests = 0;
    status = false;
    fromDate = _fromDate;
    toDate = _toDate;
}

int Room::getRoom() {
    return room;
}
    
int Room::getBeds() {
    return beds;
}

std::string Room::getFromDate() {
    return fromDate;
}
    
std::string Room::getToDate() {
    return toDate;
}
void Room::save(std::ostream &out) {
    out<<room<<" "<<fromDate<<" "<<toDate<<" "<<note<<" ";
}    
void Room::load(std::istream& in) {
    in>>room>>fromDate>>toDate>>note;
}

std::istream& operator >> (std::istream& in, std::vector<Room>& rooms) {
    
    rooms.clear();
    Room newRoom;
    for (size_t i = 0; i < 3; ++i) {
        newRoom.load(in);
        rooms.push_back(newRoom);
    }
    return in;
}

std::ostream& operator << (std::ostream& out, std::vector<Room> rooms){
      
    for (int i = 0; i<rooms.size();i++) {
        rooms[i].save(out);
    }
    return out;
}

// report <from> <to>
// Извежда справка за използването на стаи в периода от дата <from> до <to>. 
//Извежда се списък, в който за всяка стая, използвана в дадения период, се извежда и броя на дните, в които е била използвана.
//---note:refactoring, не работи за периода пр. 2020.12.01 - 2020.01.01
void report(std::string _fromDate, std::string _toDate, std::vector<Room> rooms) {
      
       for (size_t i = 0; i < rooms.size(); i++) {
            if( getMonthFromString(_fromDate) <=  getMonthFromString(rooms[i].getFromDate()) 
                && getMonthFromString(_toDate) >= getMonthFromString(rooms[i].getToDate()) 
            ) {
                 
                if((getDayFromString(rooms[i].getFromDate()) >= getDayFromString(_toDate)||
                    getDayFromString(rooms[i].getToDate()) <= getDayFromString(_toDate)) && 
                    ( 
                        getDayFromString(rooms[i].getToDate()) >= getDayFromString(_fromDate) ||
                        getDayFromString(rooms[i].getToDate()) <= getDayFromString(_fromDate) 
                    )
                ) {
                    std::cout<<std::endl;
                    std::cout<<"Room "<<rooms[i].getRoom()<<std::endl;
                    std::cout<<"Period: "<<rooms[i].getFromDate()<<" - "<<rooms[i].getToDate()<<std::endl;
                    std::cout<<"Count of days:" <<countDays(rooms[i].getFromDate(),rooms[i].getToDate())<<std::endl;
                    
                 }
              
            }
       }
}

// find <beds> <from> <to>
// Намиране на подходяща свободна стая с поне <beds> на брой легла в периода от <from> до <to>. 
//При наличие на повече свободни стаи се предпочитат такива с по-малко на брой легла.
void find(int _beds, std::string _fromDate, std::string _toDate, std::vector<Room> rooms ) {

}
// find! <beds> <from> <to>
// Да се реализира алгоритъм, който предлага спешно намиране на стая за важен гост в случай на липса на свободни стаи за даден период.
//  Алгоритъмът да предлага разместване на настанените от най-много две стаи.