#include <iostream>
#include <stdio.h>

//Класове I: Прости класове, методи и оператори

// 9.1. Задача 2.39.[7] Да се дефинира клас Time, който определя момент от
// денонощието по зададени час и минути. Класът да съдържа подходящи
// методи.

class Time {

private:
    size_t hour;
    size_t minutes;
public:    
    void setHour(size_t hour);
    void setMinutes(size_t minutes);

    size_t getHour() const;
    size_t getMinutes() const;

    void addMinutes(int minutes);
    int pastMinutes();
    bool operator<(Time t2);
    Time operator+(Time t2);
    Time operator-(Time t2);
    Time operator*(int number);

};

//  достъп и промяна на часа и минутите с проверки за коректност;
void Time::setHour(size_t hour) {
    if (hour >= 1 && hour <=12 )
    {
        this->hour = hour;
    }
    
}

void Time::setMinutes(size_t minutes) {
    if (minutes >=0 && minutes <= 59 )
    {
        this->minutes = minutes;
    }
    
}

size_t Time::getHour() const {
     return this->hour;
}
size_t Time::getMinutes() const {
     return this->minutes;
}

//  добавящ към времето цяло число минути;
void Time::addMinutes(int minutes) {

    if (minutes >=0 && minutes <= 59 )
    {
        this->minutes += minutes;

        while (this->minutes >= 60)
        {
            this->minutes -=60;
            this->hour +=1;   
        }
        
    }
  
  }

// достъп до боря минути, изминали от началото на денонощието;
int Time::pastMinutes() {

    return (this->hour*60) + this->minutes;  
}

// оператор за сравнение (казваме, че t 1 < t 2 , ако t 2 е по-късно в
// денонощието от t 1 ).
 bool Time::operator<(Time t2)  {
    return this->pastMinutes() < t2.pastMinutes();
 }


// Да се предефинират операторите +, - и *, така че да могат да се съ-
// бират и изваждат две времена, както и да се умножават време с цяло
// число и цяло число с време.
Time Time::operator+(Time t2) {
    Time t3;
    t3.hour = this->hour+t2.hour;
    t3.minutes = this->minutes + t2.minutes;
    if(t3.minutes >= 0)
    {
        t3.minutes %= 60;
        t3.hour++;
    }
    return t3;
}

Time Time::operator-(Time t2) {
    Time t3;
    
    t3.hour = (this->hour - t2.hour);
    t3.minutes = (this-> minutes - t2.minutes);
    if(t3.minutes < 0)
    {
        t3.minutes += 60;
        t3.hour--;
    }
    
    return t3;
}

Time Time::operator*(int number) {
    Time t3;
    t3.hour = this->hour * number;
    t3.minutes = this->minutes * number;
    if(t3.minutes > 60)
    {
        t3.minutes%=60;
        t3.hour++;
    }
    return t3;
}

//---------------------------------------------------------------------------------

// 9.2. Да се дефинира структура Point, описваща точка в евклидовата равнина
// и клас Line, описващ права в евклидовата равнина, зададена чрез две
// нейни точки.

// Класът Line да съдържа методи, чрез които може да се извършват след-
// ните операции:
// • Проверка дали две прави са успоредни;
// • Проверка дали дадена точка лежи на дадена права;
// • Намиране на пресечната точка на две прави. Приемаме, че правите
// не са успоредни. Стойността на резултата може да е произволна в
// противен случай.
// • Създаване на права, която е ъглополовяща на по-големия ъгъл,
// образуван от две прави. Стойността на резултата може да е произ-
// волна в противен случай.
// Където е подходящо да се дефинират оператори вместо методи.
struct Point {
    double x;
    double y;

};

class Line {
    Point pointOne;
    Point pointTwo;

    bool checkParalel(); 
    bool chekPoint();
    double findPoint();

};

// 9.3. Задача 2.44. [7] (асоциативен масив) Да се дефинира клас Dictionary,
// който създава тълковен речник. Тълковният речник се състои от не по-
// вече от 500 двойки дума–тълкувание, като думата е символен низ с не
// повече от 100 символа, а тълкованието е символен низ с не повече от 500
// символа.
// Да се дефинира подходяща структура, описваща една двойка дума-
// тълкувание;
// • Да се дефинират подходящи член-данни на клас Dictionary;
// Клас Dictionary да съдържа методи, с които може да се извършват
// следните операции над речника:
// • Инициализация на празен речник;
// • извеждане на всички думи в речника и техните тълкувания;
// • включване на нова двойка дума–тълкуване в речника;
// • изключване на двойка дума–тълкуване от речника (по дадена ду-
// ма);
// • търсене на значението на дадена дума в речник.
// • извеждане на всички думи в речника и техните тълкувания по аз-
// бучен ред на думите;
// Да се дефинира оператор +, обединяващ два речника, такъв че:
// • Ако някои думи имат значение и в двата речника, значенията да
// се конкатенират в резултатния сумарен речник;
// Ако общият брой на думите в двата речника надхвърля 500, да се
// използват само първите 500 думи (при произволна наредба).

int main() {

    // Time t1;
    // t1.setHour(1);
    // t1.setMinutes(30);
    // Time t2;
    // t2.setHour(2);
    // t2.setMinutes(30);
    // Time addTime = t1 + t2;
    // Time minusTime = t1 - t2;
    // Time multiplyByNum = t1 * 10;
    // std::cout << addTime.getHour() << ":"<< addTime.getMinutes() << "\n";
    // std::cout << minusTime.getHour() << ":"<< minusTime.getMinutes()<< "\n";
    // std::cout << multiplyByNum.getMinutes() << ":" << multiplyByNum.getMinutes() << "\n";

}