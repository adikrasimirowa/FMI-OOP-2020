#include <iostream>
#include <cstring>
// Жизнен цикъл на обектите | Конструктори

// 10.1. Да се дефинира клас Word, описващ дума, съставена от не повече от 20
// символа от тип char. Класът да съдържа следните операции:

 class Word {
     char words[20];
public:
// оператор [] за намиране на i-тия пореден символ в думата
    char operator[](size_t i) {
        return words[i];
    }

// оператори + и += за добавяне на един символ в края на думата. Ако
// думата вече има 20 символа, операторите да нямат ефект

    Word operator+(Word other){
       Word newBuffer;
        if(strlen(this->words) < 20) {
            strcpy(newBuffer.words,this->words);
            strcat(newBuffer.words,other.words);
            return newBuffer;
        }
    }

    Word operator+=(Word other) {
        Word newBuffer;
        if(strlen(this->words) < 20) {
            strcpy(newBuffer.words,this->words);
            strcat(newBuffer.words,other.words);
            return newBuffer;
        }
    }

// оператори < и == за сравнение на думи спрямо лексикографската наредба

    bool operator==(Word other){
        for (size_t i = 0; i < strlen(this->words); i++)
        {
            if(this->words[i] != other.words[i]) {
                return false;
            }
        }
        return true;
        
    }

    bool operator<(Word other){
         for (size_t i = 0; i < strlen(this->words); i++)
        {
            if(this->words[i] > other.words[i]) {
                return false;
            }
        }
        return true;
    }


// подходящи конструктори
    Word(){
      strcpy(this->words,"");
    }

    Word(char* newWords){
        for (size_t i = 0; i < strlen(newWords); i++)
        {
            /* code */
            this->words[i] = newWords[i];
        }    
       
    }

    Word(const Word& other){
        // if (other != NULL)
        // {
            for (size_t i = 0; i < strlen(other.words); i++)
            {
                this->words[i] = other.words[i];
            }
        // }
        
    }
    
    Word& operator=(Word& other){
        if (this != &other)
        {
        
            for (size_t i = 0; i < strlen(other.words); i++)
            {
                this->words[i] = other.words[i];
            }
        }

        return *this;
        
    }
    ~Word() {}

    void print() {
        std::cout<<this->words;
    }

 };


//---------------------------------------------------------------------------------
// 10.2. Да се реализира клас NumbersSummator, който поддържа сума на цели
// числа. При създаване на обект от класа, съответната му сума да се ини-
// циализира с число, което се подава като аргумент на конструктора. За
// класа да се реализират следните методи:
// • sum, който връща текущата стойност на сумата
// • add, увеличаващ сумата с дадено число
// • sub, намаляващ сумата с дадено число
// • num, връща колко пъти сумата е била променяна
// • average, връщащ средното аритметично на всички числа, с които
// сумата е била променяна.
// Забележка:Функционалност извън тези 4 метода, като например съхра-
// няване на отделните числа от поредицата, не е необходима. Пример:
// NumbersSummator s e q 1 ( 1 0 ) ;
// s e q 1 . add ( 1 0 ) ;
// s e q 1 . add ( 5 ) ;
// s e q 1 . sub ( 1 5 ) ;
// c o u t << s e q 1 . sum ( ) ; //−>10 (10+10+5−15)
// c o u t << s e q 1 . a v e r a g e ( ) ; //−>0 (10+5 −15) /3

///--------------------------------------------------------------------------------
// 10.3. Да се дефинира клас BrowserHistory, който съдържа информация за ис-
// торията на посещението до най-много N Web сайта. N е параметър на кон-
// структора на класа. За целта да се реализира структура HistoryEntry,
// описваща едно посещение на сайт чрез:
// 49а) Месец от годината, през който е посетен сайтът;
// б) Неговото URL.
// Класът codeBrowserHistory да поддържа следните операции:
// • Метод за добавяне на нов сайт към историята. Информацията за
// всеки сайт се въвежда от клавиатурата
// • Оператор += с параметър HistoryEntry, добавящ сайт към исто-
// рията
// • Метод за отпечатване на информацията за всички сайтове в исто-
// рията
// • Метод, който по даден месец от годината намира броя на сайтовете,
// посетени през този месец
// • Намиране на този месец от годината, в който има най-много посе-
// тени сайтове
// • Премахване на най-скоро добавеният сайт в историята
// • Оператор +, който обединява двете истории
// Да се реализира и изпълни подходящ тест за класа и неговите методи.
///---------------------------------------------------------------------------------------------
// 10.4. За клас BrowserHistory от задача 10.3. да се реализират конструктор за
// копиране, оператор за присвояване, оператори за събиране + и +=, обе-
// диняващи две истории и деструктор.
// Да се реализира подходящ тест на класа.
int main() {
    char str[] = "test";
    char str2[] = "2test";
    Word t1 = str;
    Word t2 = str;
    t1.print();
    //Word(t1);
   // Word t2("bbb");
    

}