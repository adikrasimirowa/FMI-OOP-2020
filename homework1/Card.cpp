#include "Card.h"

//статични масиви от стрингове - без значение колко обекти от 
//класа са създадени, има само едно копие на статичния член.
String Card::suits[] = {"clubs","diamonds","hearts","spades"};
String Card::values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

//-------------Конструктори----------------------//

//Конструктор по подразбиране
Card::Card() {
    suit = "";
    value = "";
    strcpy(serialNumber,"default_");
}

//Конструктор с параметри
Card::Card(int suitIndex, int valueIndex) {
    suit = suits[suitIndex];
    value = values[valueIndex];
    strcpy(serialNumber,"default_");
}

//Копи-Конструктор
Card::Card(const Card& other) {
    suit = other.suit;
    value = other.value;
}

//Оператор=
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        suit = other.suit;
        value = other.value;
    }

    return *this;  
}

//----------------Методи----------------------------//

//Сетър на серийня номер
void Card::setSerialNumber(const char* _serialNumber) {
    strcpy(serialNumber,_serialNumber);
}

// Гетър на серийния номер
const char* Card::getSerialNumber() {
     return serialNumber;
};

// принтира всички бои
void Card::printSuits() {
  for (size_t i = 0; i < 4; i++) {
    std::cout << suits[i]<<" ";
  }
}

//принтира всички стойности
void Card::printRanks() {
  for (size_t i = 0; i < 13; i++) {
     std::cout << values[i]<<" ";
  }
  
}
//връща боята
String Card::getSuit() const {
    return suit;
}

//връща стойността 
String Card::getValue() const {
    return value;
}

//връща стринг value (suit)
String Card::returnCard() {
    return (value + "(" + suit + ")" );
}
