#include "Deck.h"

//-----------Конструктори------------------//

//Конструктор по подразбиране
Deck::Deck() {
    strcpy(serial,"Default");
    init();
    deckSize = DEFAULT_DECK_SIZE;
}

void Deck::init() {
    //динамичен масив от 52 Card обекта
    deck = new Card[DEFAULT_DECK_SIZE]; 
   
    srand(time(0));//дава на случайната функция отправна точка

    for (size_t i = 0; i < DEFAULT_DECK_SIZE; i++)
    {
        deck[i] = Card(i/13,i%13);
    }

    for (size_t j = 0; j < DEFAULT_DECK_SIZE; j++)
    {
        // връща произволна стойност от останалите позиции 
        //0 + число от [0-52]
        //1 + числп от [0 -51] и тн.
        int random = j + (rand() % (DEFAULT_DECK_SIZE -j)); 
  
        swap(j,random); 
    }
}


//Конструктор с параметри
Deck::Deck(int k, const char* _serial) {
    
    //проверка за валидност на големината тестото
    if(k > 0 && k < 53) {
        deckSize = k;
    }

    //създаване на тесте от 52 карти
    init ();

    //Серия на тестето
    if (serial && !serial[0]) {
        strcpy(serial,"Custom");
    }else
    {
        strcpy(this->serial,_serial);
    }

    //създаване на тесте с прозволен брой карти
    Card *customDeck;
    customDeck = new Card[k];

    for (size_t i = 0; i < k; i++)
    {
       customDeck[i] = deck[i];
    }

    delete[] deck;
    deck = customDeck; 
}


//Копи-конструктор
Deck::Deck(const Deck& other) {

    strcpy(serial,other.serial);

    deck = new Card[deckSize];
    for (int i = 0; i <  deckSize; i++){
        deck[i] = other.deck[i];
    }
}

//Оператор =
Deck& Deck::operator=(const Deck& other){
    if (this != &other) {
        delete[] deck;
        strcpy(serial,other.serial);
        for (int i = 0; i < deckSize; i++){
            deck[i] = other.deck[i];
        }
    }
    return *this;
}

//Диструктор
Deck::~Deck() {

    delete [] deck;
} 

///---------------Методи----------------------------------

//по подадена боя се връща броя на картите в тестето с тази боя.
 int Deck::suit_count(String suit) const {
    int count = 0;
    for (size_t i = 0; i < deckSize; i++) { 
        if (deck[i].getSuit()==suit) {
            count++;
        }
    }

    return count;
 }

//по подадена стойност се връща броя на картите с тази стойност от все още неизтеглените карти. 

int Deck::rank_count(String value) const {
    int count = 0;
    for (size_t i = 0; i < deckSize; i++)
    { 
        if (deck[i].getValue()==value)
        {
            count++;
        }
    }

    return count;
 }


// функции за принтиране на тестето
void Deck::print() {
    for (size_t i = 0; i < 52; i++) {      
    std::cout<<deck[i].returnCard();
    } 
    std::cout<<std::endl<<serial;
}

void Deck::printD(int k) {
     for (size_t i = 0; i < k; i++) {      
    std::cout<<deck[i].returnCard();
    } 
}

//първата карта се премества на дъното на тестето и се връща като резултат.
// В частност, ако в тестето има k на брой карти, след k пъти извикване на draw, 
//то трябва да се върне в първоначалния си вид.

String Deck::draw() {
    Card *buffer = new Card[deckSize+1];
    String fristCard = deck[0].returnCard();

    for (size_t i = 0; i < deckSize-1; i++)
    {
        buffer[i] = deck[i+1];
    }

    buffer[deckSize-1] = deck[0];
    delete [] deck;
    deck = buffer;

    return fristCard;
}

//по подадени две цели положителни числа се разменят картите с тези поредни номера в тестето.
//Операцията трябва да се изпълни само ако и двата подадени поредни номера са валидни за тестето.  

void Deck::swap(int k, int n) {
    if( k>=0 && k < deckSize && n>=0 && n< deckSize ) {
        Card temp = deck[k];
        deck[k] = deck[n];
        deck[n] = temp;
    }
   
}

