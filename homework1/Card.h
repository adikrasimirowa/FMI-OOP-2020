#pragma once
#include <iostream>
#include <cstring>
#include "String. h"

class Card {
    
 private:
    char serialNumber[15];
    String suit;
    String value;
    
public:
    static String suits[] ;
    static String values[] ;

    Card(int,int);
    Card();
    Card(const Card& other);
    Card& operator=(const Card& other);
 
    void setSerialNumber(const char* _serialNumber);
    const char* getSerialNumber();
    void printSuits();
    void printRanks();
    String getSuit() const;
    String getValue() const;
    String returnCard();
    
};
