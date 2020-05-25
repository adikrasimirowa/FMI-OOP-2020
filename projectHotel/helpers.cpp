#include "Room.h"


// връща колко дни остават до края на месеца
int getRemaingDays(int year, int month, int day) {
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
             if ( year%4 == 0 && year%100 !=0 || year%400 == 0)
            {
                days = 29;
            }
            else days = 28;
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

int getYearFromString(std::string date) {
    int year = 0;
	for (int j = 0; j<4; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				year = year * 10 + (date[j] - '0');
		}
	}

    return year;

}

int getMonthFromString(std::string date) {
    int month = 0;
	for (int j = 5; j<7; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				month = month * 10 + (date[j]- '0');
		}
	}

    return month;
}

int getDayFromString(std::string date) {
    int day = 0;
	for (int j = 8; j<10; j++) {	
		if ( date[j] >= '0' &&  date[j] <= '9' ) {
				day = day * 10 + (date[j]- '0');
		}
	}
    return day;
}


int countDays(std::string _fromDate, std::string _toDate) {
    int countOfDays = 0;
      if( getMonthFromString(_fromDate) ==  getMonthFromString(_toDate)) {
                countOfDays = getDayFromString(_toDate) - getDayFromString(_fromDate);
        } else {
                countOfDays = getRemaingDays(
                                        getYearFromString(_fromDate),
                                        getMonthFromString(_fromDate),
                                        getDayFromString(_fromDate)
                                        ) 
                            + getDayFromString(_toDate);
        }
    
    return countOfDays;
}

void init() {
    std::vector<Room> rooms = {{ 333, 2, "2020-10-27","2020-10-28","dd",false},
                            {300,0,"2020-11-20","2020-11-27","dd",false},
                            {200,0,"2020-11-30","2020-12-27","dd",false}}; 

    std::ofstream out ("rooms.txt");
    out<<rooms;
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
