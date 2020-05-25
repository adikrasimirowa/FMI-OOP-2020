#pragma once
class Room {
private:
    size_t room;
    std::string fromDate;
    std::string toDate;
    std::string note;
    size_t beds;
    bool status;
    size_t numberOfguests;
public:
    Room();
    Room(size_t _room,size_t _beds,std::string _fromDate, std::string _toDate, std::string _note, bool _status);

    void chekin(std::string _fromDate, std::string _toDate, std::string _note);
    void availability(std::string date);
    void checkout(size_t room);
    void unavailable(std::string _fromDate, std::string _toDate, std::string _note);
    int getRoom();
    int getBeds();
    std::string getFromDate(); 
    std::string getToDate();
    void save(std::ostream &out);
    void load(std::istream& in);
};

void report(std::string _fromDate, std::string _toDate, std::vector<Room> rooms);
void find(int _beds, std::string _fromDate, std::string _toDate, std::vector<Room> rooms );
std::istream& operator >> (std::istream& in, std::vector<Room>& rooms);
std::ostream& operator << (std::ostream& out, std::vector<Room> rooms);