#include "Room.h"

/// Конструктор по подразбиране
/// задаваме "default" стойности на член-даните на класа
/// status = false; - стаята не е заета
/// fromDate и toDate приемат стойноста currentDate() - текуща дата

Room::Room() {
    setRoom(100);
    setBeds(1);
    setFromDate(currentDate());
    setToDate(currentDate());
    setNote("");
    setStatus(false);
    setNumberOfGuests(0);
}

///Конструктор с параметри и списък с инициализатори на членове
Room::Room(size_t _room,size_t _beds,std::string _fromDate, std::string _toDate, std::string _note, bool _status)
    :room(_room),
    beds(_beds),
    fromDate(_fromDate),
    toDate(_toDate),
    note(_note),
    status(_status){}

///Оператор за присвояване - предефинираме =
Room& Room::operator=(const Room& other) {
    if (this != &other) {
        setRoom(other.room);
        setBeds(other.beds);
        setFromDate(other.fromDate);
        setToDate(other.toDate);
        setNote(other.note);
        setStatus(other.status);
        setNumberOfGuests(other.numberOfGuests);
    }
    return *this;
}

/// Копиращ конструктор
Room::Room(const Room& other ) {
    setRoom(other.room);
    setBeds(other.beds);
    setFromDate(other.fromDate);
    setToDate(other.toDate);
    setNote(other.note);
    setStatus(other.status);
    setNumberOfGuests(other.numberOfGuests);
}

/// Дeструктор
Room::~Room() = default;


/// задава стойност на стаите
void Room::setRoom(size_t _room) {
    this->room =_room;
}

/// задава стойност на дата на настаняване
void Room::setFromDate(const std::string &_fromDate) {
    this->fromDate = _fromDate;
}

/// задава стойност на дата на напускане
void Room::setToDate(const std::string &_toDate) {
    this->toDate = _toDate;
}

/// задава стойност на бележка
void Room::setNote(const std::string &_note) {
    this->note = _note;
}

/// задава стойност на леглата в стаята
void Room::setBeds(size_t _beds) {
    this->beds = _beds;
}

/// задава стойноаст на статуса на стая
void Room::setStatus(bool _status) {
    this->status = _status;
}

///задава стойносст на броят гости в стая
void Room::setNumberOfGuests(size_t _numberOfGuests) {
    this->numberOfGuests = _numberOfGuests;
}

///връща номера на стаята
int Room::getRoom() const {
    return room;
}

///връща броя легла в стаята
int Room::getBeds() const {
    return beds;
}

///връща датата на настаняване
std::string Room::getFromDate() {
    return fromDate;
}

///връща датата на напускане
std::string Room::getToDate() {
    return toDate;
}
bool Room::getStatus() const {
    return status;
}

///записване в потока
void Room::save(std::ostream &out) {
    out<<room<<" "<<beds<<" "<<fromDate<<" "<<toDate<<" "<<note<<" "<<status<<" ";
}

///зареждане от потока
void Room::load(std::istream& in) {
    in>>room>>beds>>fromDate>>toDate>>note>>status;
}

/// метод за вход на вектор
std::istream& operator >> (std::istream& in, std::vector<Room>& rooms) {

    rooms.clear();
    Room newRoom;
    while (!in.eof()){
        newRoom.load(in);
        rooms.push_back(newRoom);
    }
    return in;
}

///метод за изход на вектор
std::ostream& operator << (std::ostream& out, std::vector<Room> rooms){
      
    for (int i = 0; i<rooms.size();i++) {
        rooms[i].save(out);
    }
    return out;
}

/// checkin <room> <from> <to> <note> [<guests>]
/// Регистриране в стая с номер <room> от дата <from> до дата <to> и се добавя бележка <note>. Незадължителният параметър <guests> задава броя на гостите, настанени в стаята.
/// Ако той не е указан, се счита, че броят на настанените гости е равен на броя на леглата в стаята.
/// Пример: checkin 229 2020-03-23 2020-03-31 The Simpsons
void Room::checkin(const std::string& _fromDate, const std::string& _toDate, const std::string& _note) {
    setFromDate(_fromDate);
    setToDate(_toDate);
    setNote(_note);
    setStatus(true);
    setNumberOfGuests(beds);

    std::cout<<"Room "<<getRoom()<<" successfully reserved!"<<std::endl;
}


/// availability [<date>]
/// Извежда списък на свободните стаи на дата <date>, ако не е зададена, се използва текущата дата.
void Room::availability(const std::string& date){
    if(date==getFromDate()) {

        if(!getStatus()){
            std::cout<<"Available rooms: "<<getRoom()<<std::endl;
        }
    }
}


/// checkout <room>
/// Освобождаване на заета стая с номер <room>.
void Room::checkout(size_t _room) {

    if (getRoom() == _room) {
        setToDate(currentDate());
        setNote( "Free");
        setStatus(false);
        setNumberOfGuests(0);
        std::cout<<"Room "<<getRoom()<<" is free!";
    }

}

/// unavailable <room> <from> <to> <note>
/// Обявява стаята с номер <room> от дата <from> до дата <to> за временно недостъпна и се добавя бележка <note>.
/// В стаята няма регистриран гост, но никой не може да бъде настанен в нея.
/// Пример:
/// unavailable 200 2018-06-01 2019-03-01 Under construction
void Room::unavailable(const std::string& _fromDate, const std::string& _toDate, const std::string& _note) {
    setFromDate(_fromDate);
    setToDate(_toDate);
    setNote( _note);
    setStatus(false);
    setNumberOfGuests(0);

    std::cout<<"Room status "<<getRoom()<<" successfully changed!"<<std::endl;
}

/// report <from> <to>
/// Извежда справка за използването на стаи в периода от дата <from> до <to>.
///Извежда се списък, в който за всяка стая, използвана в дадения период, се извежда и броя на дните, в които е била използвана.
///note: не работи за периода пр. 2020.12.01 - 2020.01.01
void report(const std::string& _fromDate, const std::string& _toDate, std::vector<Room> rooms) {
      
       for (size_t i = 0; i < rooms.size(); i++) {
            if (inPeriod(_fromDate,_toDate,rooms[i].getFromDate(),rooms[i].getToDate())) {
                std::cout<<std::endl;
                    std::cout<<"Room "<<rooms[i].getRoom()<<std::endl;
                    std::cout<<"Period: "<<rooms[i].getFromDate()<<" - "<<rooms[i].getToDate()<<std::endl;
                    std::cout<<"Count of days:" <<countDays(rooms[i].getFromDate(),rooms[i].getToDate())<<std::endl;
            }
       }
}

/// find <beds> <from> <to>
/// Намиране на подходяща свободна стая с поне <beds> на брой легла в периода от <from> до <to>.
///При наличие на повече свободни стаи се предпочитат такива с по-малко на брой легла.
void find(int _beds, const std::string& _fromDate, const std::string& _toDate, std::vector<Room> rooms ) {

    for (int i = 0; i < rooms.size(); ++i) {

        if (_beds <= rooms[i].getBeds() && !rooms[i].getStatus() && inPeriod(_fromDate,_toDate,rooms[i].getFromDate(),rooms[i].getToDate())) {
            std::cout<<"Room "<<rooms[i].getRoom()<<std::endl;
            std::cout<<"Period: "<<rooms[i].getFromDate()<<" - "<<rooms[i].getToDate()<<std::endl;
            std::cout<<"Beds: "<<rooms[i].getBeds()<<std::endl<<std::endl;
        }
    }

}
/// find! <beds> <from> <to>
/// Да се реализира алгоритъм, който предлага спешно намиране на стая за важен гост в случай на липса на свободни стаи за даден период.
///  Алгоритъмът да предлага разместване на настанените от най-много две стаи.