#include "Player.h"

//-----------Конструктори------------------//

//Конструктор по подразбиране
Player::Player() {
    this->fullName = "Ivan Ivanov";
    this->years = 18;
    this->wins = 0;
    this->coef = 0;
    this->currentPoints = 0;
}

//Конструктор с параметри
Player::Player(String newFullName,int newYears){
    
    if (nameValidation(newFullName))
    {
        this->fullName = newFullName;
    } else
    {
        std::cout<<"Enter valid name!"<<std::endl;
    }

    if (newYears>= 18 && newYears <=90)
    {
       this->years = newYears;
    } 
    else{
        std::cout<<"You must be 18+ years to play this game!"<<std::endl;
    }
    
    this->wins = 0;
    this->coef = 0;
    this->currentPoints = 0;
}

//Конструктор с три параметъра
Player::Player(String newFullName,size_t newWins ,double newCoef) {
   
    if (nameValidation(newFullName))
    {
        this->fullName = newFullName;
    } else
    {
        std::cout<<"Enter valid name!"<<std::endl;
    }
    
    this->wins = newWins;
    this->coef = newCoef;
    this->currentPoints = 0;
}

//Копи-конструктор
Player::Player(const Player& other) {
    fullName = other.fullName;
    years = other.years;
    wins = other.wins;
    coef = other.coef;
    currentPoints = other.currentPoints;
}

//Оператор=
Player& Player::operator=(const Player& other) {
    if (this != &other)
    {
        fullName = other.fullName;
        years = other.years;
        wins = other.wins;
        coef = other.coef;
        currentPoints = other.currentPoints;
    }

    return *this;
}

//------------Методи---------------------------//

//валидация на името на играча
//две имена, състоящи се от латински букви, 
//започващи с главна буква и разделени с точно един интервал

bool Player::nameValidation(String fullName) {
    
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int index; // запазва позицията на ' ' 
    
    for (int i = 0; i<fullName.length(); i++) {
        if(fullName[i] == ' '){
            count++;
            index = i;
        } 
    } 

    if(count == 1) {
    
        int i = 0;
        while(fullName[i] != ' ') {
            if(fullName[i] >= 'A' && fullName[i] <= 'Z'){
                count2++;
            } 
            i++;
        }
        
        int j = index;
        while(j<fullName.length()) {
            if(fullName[j] >= 'A' && fullName[j] <= 'Z'){
                count3++;
            } 
            j++;
        }

        if(count2 == 1 && count3 == 1) {
            
            for (size_t k = 0; k < count; k++){
            
                if(fullName[i] == ' ' && fullName[i+1] >='a' && fullName[i+1] <='z'|| fullName[0] >= 'a' && fullName[0] <= 'a'){
                    return false;
                } else{
                    return true;
                } 
            } 

        } else {
           return false;
        }
    
    } else{
        return false;
    }

}

//птинтира информация за играча
void Player::print() {
    std::cout<< fullName <<" Wins: "<< wins <<" Coefficient: "<<coef ;
}

// натрупване на точки от играча
void Player::points(String value) {
     
    if(value[0] =='J' || value[0] =='Q' || value[0]== 'K' ) {
        currentPoints+=10;
    } else if(value[0] == 'A') {

        if(currentPoints+11 <= 21) {

            currentPoints+=11;

        } else if(currentPoints == 20 || currentPoints+11 > 21 ) {
            
            currentPoints++;
        }

    } else {
        switch(value[0]) {
        case '2' :
            currentPoints+=2; 
        break;
        case '3' :
            currentPoints+=3; 
        break;
        case '4' :
            currentPoints+=4; 
        break;
        case '5' :
            currentPoints+=5; 
        break;
        case '6' :
            currentPoints+=6; 
        break;
        case '7' :
            currentPoints+=7; 
        break;
        case '8' :
            currentPoints+=8; 
        break;
        case '9' :
            currentPoints+=9; 
        break;
        default :
            //10
            currentPoints+=10;
        }
    } 
}

//връща името на играча
String Player::getPlayerName() {
      return this->fullName;
}

//връща точките на играча
int Player::retunPoints() {
       return  this->currentPoints;
}

