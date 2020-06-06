#pragma once

class Room {
private:
    size_t room{};  /// номер на стая
    std::string fromDate; /// дата на настаняване
    std::string toDate; /// дата на напускабне
    std::string note; /// бележка към стаята
    size_t beds{}; /// брой легла
    bool status{}; /// статус който показва дали е заета стаята
    size_t numberOfGuests{}; /// брой гости настанени в стаята
public:
    Room();
    Room(size_t _room,size_t _beds,std::string _fromDate, std::string _toDate, std::string _note, bool _status);
    Room& operator=(const Room& other);
    Room(const Room& other);
    ~Room();

    void checkin(const std::string& _fromDate, const std::string& _toDate, const std::string& _note);
    void availability(const std::string& date);
    void checkout(size_t room);
    void unavailable(const std::string& _fromDate, const std::string& _toDate, const std::string& _note);
    int getRoom() const;
    int getBeds() const;
    bool getStatus() const;
    std::string getFromDate(); 
    std::string getToDate();
    void save(std::ostream &out);
    void load(std::istream& in);

    void setRoom(size_t room);
    void setFromDate(const std::string &fromDate);
    void setToDate(const std::string &toDate);
    void setNote(const std::string &note);
    void setBeds(size_t beds);
    void setStatus(bool status);
    void setNumberOfGuests(size_t numberOfGuests);
};

///други операции
void report(const std::string& _fromDate, const std::string& _toDate, std::vector<Room> rooms);
void find(int _beds, const std::string& _fromDate, const std::string& _toDate, std::vector<Room> rooms );

/// потоци за вход и изход
std::istream& operator >> (std::istream& in, std::vector<Room>& rooms);
std::ostream& operator << (std::ostream& out, std::vector<Room> rooms);