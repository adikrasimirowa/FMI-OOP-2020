#include "Room.h"

// СПОМАГАТЕЛНИ ФУНКЦИИ

/// връща колко дни остават до края на месеца
int getRemainingDays(int year, int month, int day) {
    int days = 0;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
        break;
        case 2:
            days = year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? 29 : 28;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
        break;
        default: std::cout<<"Wrong number";
    }
    return days-day;
}

///връща годината от стринга като цяло число
int getYearFromString(std::string date) {
    int year = 0;
	for (int j = 0; j<4; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				year = year * 10 + (date[j] - '0');
		}
	}
    return year;

}

///връща месеца като цяло число от String
int getMonthFromString(std::string date) {
    int month = 0;
	for (int j = 5; j<7; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				month = month * 10 + (date[j]- '0');
		}
	}
    return month;
}

///връща деня като цяло число от String
int getDayFromString(std::string date) {
    int day = 0;
	for (int j = 8; j<10; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				day = day * 10 + (date[j]- '0');
		}
	}
    return day;
}

///брои дните между датите
///note: не работи за дати между две години
int countDays(const std::string& _fromDate, const std::string& _toDate) {
    int countOfDays;
      if(getMonthFromString(_fromDate) ==  getMonthFromString(_toDate)) {
                countOfDays = getDayFromString(_toDate) - getDayFromString(_fromDate);
        } else {
                countOfDays = getRemainingDays(
                                        getYearFromString(_fromDate),
                                        getMonthFromString(_fromDate),
                                        getDayFromString(_fromDate)
                                        )
                            + getDayFromString(_toDate);
        }
    
    return countOfDays;
}

///връща текущата дата като стринг
///източник: https://www.cplusplus.com/reference/ctime/strftime/
std::string currentDate() {
    time_t rawTime;
    struct tm * timeInfo;
    char buffer [11];
    std::string  current;

    time (&rawTime);
    timeInfo = localtime (&rawTime);

    strftime (buffer,11,"%Y-%m-%d",timeInfo);
    current = buffer;

    return current;
}

///създава начални данни във файла на стаите
void init() {
    std::string lastYearDate = "2020-12-31";
    std::vector<Room> rooms = {
                            {301,2,currentDate(),lastYearDate,"Free",false},
                            {302,5,currentDate(),lastYearDate,"Free",false},
                            {303,6,currentDate(),lastYearDate,"Free",false},
                            {304,2,currentDate(),lastYearDate,"Free",false},
                            {305,1,currentDate(),lastYearDate,"Free",false},
                            {201,2,currentDate(),lastYearDate,"Free",false},
                            {202,2,currentDate(),lastYearDate,"Free",false},
                            {203,3,currentDate(),lastYearDate,"Free",false},
                            {204,5,currentDate(),lastYearDate,"Free",false},
                            {205,4,currentDate(),lastYearDate,"Free",false},
    };

    std::ofstream out ("./rooms.txt");
    out<<rooms;
    out.close();
}

///помощно меню
void help() {
    std::cout<<"The following commands are supported: \n";
    std::cout<<"open <file>	    opens <file> \n";
    std::cout<<"close			closes currently opened file \n";
    std::cout<<"save			saves the currently open file \n";
    std::cout<<"save as <file>	saves the currently open file in <file> \n";
    std::cout<<"help			prints this information \n";
    std::cout<<"exit			exists the program \n";
}

///Меню с инструкции
void commands() {

    std::cout<<std::endl;
    std::cout<<"Welcome to the computer reservations system \n";
    std::cout<<std::setw(21)<<std::left<<"checkin"<<"Regidtration in room"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"availability"<<"List of free rooms for <date>"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"checkout"<<"Checkout a room"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"report"<<"Report of rooms for <dates>"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"find"<<"Finds free room"<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"find!"<<"Quick find "<<std::endl;
    std::cout<<std::setw(21)<<std::left<<"unavailable"<<"Make room unavailible"<<std::endl;
}

/// проверява дали в дадения период попада и периода на заетост на дадена стая
bool inPeriod(const std::string& _fromDate, const std::string& _toDate,const std::string& _roomFromDate, const std::string& _roomToDate) {
    if( getMonthFromString(_fromDate) <=  getMonthFromString(_roomFromDate)
        && getMonthFromString(_toDate) >= getMonthFromString(_roomToDate)
            ) {

        if((getDayFromString(_roomFromDate) >= getDayFromString(_toDate)||
            getDayFromString(_roomToDate) <= getDayFromString(_toDate)) &&
           (
                   getDayFromString(_roomToDate) >= getDayFromString(_fromDate) ||
                   getDayFromString(_roomToDate) <= getDayFromString(_fromDate)
           )
           ){
            return  true;
        }
    }
    return false;
}

/// валидатор на датите
bool dateValidator(std::string date) {
    if (date.size() !=10) {
        return false;
    }
    if(getDayFromString(date) <= 0 || getDayFromString(date) > 31 || getMonthFromString(date) <1 || getMonthFromString(date) > 12) {
        return false;
    }
    return getYearFromString(date) > 0;
}