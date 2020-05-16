#pragma once
#include <iostream>
#include <cstring>
#include "Card.cpp"

const int DEFAULT_DECK_SIZE = 52;
class Deck {
private:
    Card *deck;
    char serial[10];
    size_t deckSize;

public:
    Deck();
    Deck(int, const char*);
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    ~Deck();

    int suit_count(String) const;
    int rank_count(String) const;
    String draw();
    void print();
    void swap(int k, int n);

    void init();
    void printD(int k);
};
