#include "String.h"

//-----------Конструктори-------------//

//Конструктор по подразбиране
String::String() { 
    initialize ("");
}

//Конструктор с параметър 
String::String(const char *newStr) {
    initialize (newStr);
}

//Конструктор с параметър 
String::String(char c) {
    str = new char[2];
    str[0] = c;
    str[1] = 0;
}

//Копи-Конструктор 
String::String(const String &other) {
    str = new char [other.length() + 1];
    strcpy (str, other.str);
}

//метод, който иницилизира нов едномерен символен динамичен масив
//методът се използва в конструкторите с цел да се спести повторно писане на иницилизацията
void String::initialize (const char *newStr) {
    str = new char[strlen(newStr)+1];
    strcpy (str,newStr);
}

//------------------------Оператори-------------------------//

// Оператор+ - конкатениране на символи 
// добавяне на един низ към друг спрямо дадения край
String String::operator+ (char c){
    String result; //създаване на нов обект

    result.str = new char [length() + 1 + 1]; 
    //зделяме нова памет 
    //length() + 1 + 1 защото искаме новата дължина на масива 
    //да е по-голяма от тази на this->str и в нея да можем да запишем един символ
        
    strcpy (result.str, str); // копираме в празния result.str, str

    result.str[this->length()] = c; 
    // на позиция this->length() в result.str се записва с

    result.str[this->length()+1] = 0;
    // на this->length()+1 позиция се добавя '\0'

    return result;
}

// Оператор+ - конкатениране на стрингове 
// добавяне на един стринг към друг спрямо дадения край

String String::operator+ (String other){
    String result;
    result.str = new char[strlen(str)+strlen(other.str)+1];
    //заделяме памет която е сбор между двете дължини на стриstrнга + 1 

    strcpy (result.str,str);
    strcat (result.str,other.str);

    return result;
}


// Оператор == - сравнява два стринга дали са еднакви
bool String::operator== (String other){
    return strcmp (str,other.str) == 0;
}

//Оператор ==  сравнява два стринга дали са различни
bool String::operator != (String other) 
{
  return strcmp (str,other.str) != 0;
}

//Оператор < -  намира дали даден стринг е по-малък от другия
bool String::operator< (String other){
    return strcmp (str,other.str) < 0;
}
//Оператор[] - за индексация
char& String::operator[] (size_t i){      
    return str[i];
}

// Оператор= - присвоява един символ в стринг
String String::operator= (char c){
    str = new char [2];
    str[0] = c;
    str[1] = 0;
    return *this;
}

//------------ Други функции----------------//

//принтира str
void String::print () {
    std::cout << str << " ";
}

// намира дължината на стринг
size_t String::length () const {
    return strlen (str);
}
// функция operator+ която добавя към символ стринг
String operator+ (char c, String s)
{
    String result;

    result = c;
    result = result + s;
    return result;

}

// функция която превръща цяло положително число в стринг
String toString (unsigned int x)
{
    String result;
    
    if (x < 10)
    {
        result = '0' + x;
        return result;
    }
    while (x > 0)
    {
        result = ('0' + x%10) + result;
        x /= 10;

    }

    return result;
}

//-------- Входно/изходни потоци---------//
std::ostream& operator<< (std::ostream& out, String s)
{
    out << s.str;
    return out;
}

std::istream& operator>> (std::istream& in, String& s)
{
    char c;
    do 
    {
        c = in.get();
        if (c != '\n')
        {
            s = s + c;
        }
    } while (c != '\n');

    return in;    
}
