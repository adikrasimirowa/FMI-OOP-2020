#pragma once
#include <iostream>
#include <cstring>
#include "Deck.cpp"

class Player {
private:
    String fullName;
    int years;
    size_t wins;
    double coef;
    size_t currentPoints;

public:
    Player();
    Player(String,int);
    Player(String,size_t,double);
    Player(const Player& other);
    Player& operator=(const Player& other);
    void print();
    bool nameValidation(String);
    void points(String value);
    int retunPoints();
    String getPlayerName();

};