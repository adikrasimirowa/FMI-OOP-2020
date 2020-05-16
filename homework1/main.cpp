#include <iostream>
#include <cstring>
#include "Player.cpp"

/// функция която създава играта на раздавача
void dealer(int playerPoints, Deck deck ) {
    Player dealer;
    String saveValue;
    std::cout<<"The dealer's draw: ";

    while (dealer.retunPoints() <=17) {
        saveValue = deck.draw();
        dealer.points(saveValue[0]);
        std::cout<<" "<<saveValue;
    }

    std::cout<<" "<<"(Points "<<dealer.retunPoints()<<")"<<std::endl;

    if (dealer.retunPoints() > 21 || dealer.retunPoints() == playerPoints) {
       
        //Player win dealer lose
        std::cout<<"You win"<<std::endl;

    } else if(dealer.retunPoints() <= 21 ){
       
        if (dealer.retunPoints() < playerPoints ) {
            std::cout<<"You win"<<std::endl;
        } else {
            std::cout<<"You lose"<<std::endl;
        }
    }  
}

//функция която създава играта на играча
void game(Player player) {
    Deck gameDeck;
    String saveValue;
    String command;
    int sizeOfDeck;

    std::cout<<"You will play as: "<<player.getPlayerName()<<std::endl;
//----------------------Избор на тесте--------------//    
    std::cout<<"Enter with how much cards you want to play:"<<std::endl;
    std::cin>>sizeOfDeck;

    if (sizeOfDeck >0 && sizeOfDeck < 52) {
      Deck gameDeck(sizeOfDeck,"");
    } 
    
//----------------------Теглене на карти--------------//
    std::cout<<"Start!"<<std::endl;
    saveValue = gameDeck.draw();
    std::cout<<saveValue<<std::endl;
    player.points(saveValue[0]);
          
    do {
        std::cout<<"Hit | Stand | Probability"<<std::endl;
                
        std::cin>>command;
                
        if (command == "Hit") {   
            std::cout<<saveValue;
            saveValue = gameDeck.draw();
            std::cout<<" "<<saveValue;
            player.points(saveValue[0]);
            std::cout<<" "<<"(Points "<<player.retunPoints()<<")"<<std::endl;
            command = "";
                    
        } else if(command == "Stand") {
            
            dealer(player.retunPoints(),gameDeck);
            return;

        } else if (command == "Probability"){
            std::cout<<"Probability is not avalible at the moment"<<std::endl;
            command = "";
        } else {
            command = "";
        } 

        if (player.retunPoints()>21){
            std::cout<<"You lose!"<<std::endl; 
            return;
        }               
    } while (1);
            
}

//-------------------Главна Програма----------------------//

int main() {
    int pressedNum;
    String playerName;
    Player playerOne ("Georgi Petrov",2,1.2);
    Player playerTwo ("Petar Gochev",18,1.6);
    Player playerThree ("Monika Petrova",60);

//--------------------------Меню----------------------------//
    std::cout<<"BLACKJACK"<<std::endl;
    std::cout<<"PRESS 1: Create new player or Choose an existing one \n";
    std::cout<<"PRESS 0: To exit \n";

//--------------------Избор на играч----------------------//   
        std::cin>>pressedNum;
        if (pressedNum == 1)
        {
            playerOne.print();
            std::cout<<std::endl;
            playerTwo.print();
            std::cout<<std::endl;
            playerThree.print();
            std::cout<<std::endl;

            std::cout<<"Enter players name   \n";
            std::cin.ignore();
            std::cin>>playerName;


            if(playerName == playerOne.getPlayerName()) {
                game(playerOne);

            } else if(playerName == playerTwo.getPlayerName()) {
                game(playerTwo);

            } else if(playerName == playerThree.getPlayerName()) {
                game(playerThree);

            } else{
                std::cout<<"Enter years"<<std::endl;
                int newYears;
                std::cin>>newYears;
                Player newPlayer(playerName,newYears);
                
                if (newPlayer.getPlayerName() != "" && newYears >= 18)
                {
                    game(newPlayer);
                }
            } 
            
        } else if (pressedNum == 0)
        {   
            std::cout<<"Bye Bye";
            return 0;
        } else
        {
            std::cout<<"Invalid number"<<std::endl<<std::endl;
        }
}