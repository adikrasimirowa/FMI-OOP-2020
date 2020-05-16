#include <iostream>
#include <cstring>
// Динамична памет | Заделяне на динамична памет

//---------------------------------------------------------------------------------------

// strduplicate, която създава копие на символен низ. 
char* strduplicate( const char *str) {
        char* strNew = new char[strlen(str)+1];
        strcpy(strNew, str);

        return strNew;
}

//----------------------------------------------------------------------------------------

//преобразува положително цяло число в съответния му символен низ и връща така построения
// символен низ.
char castIntToChar ( size_t number) {
   return char('a'+ number);
}

//----------------------------------------------------------------------------------------

//Обединение на два символни низа s 1 и s 2 наричаме
// всеки символен низ, който съдържа без повторение всички символи на
// s 1 и s 2 
//намира и връща обединението на два символни низа.
char* concatinate (const char *str1, const char *str2 ) {
    
    char *buffer = new char[strlen(str1)+ strlen(str2) + 1 ];
    strcpy(buffer,str1);
    strcat(buffer,str2);

    return buffer;
}

//-----------------------------------------------------------------------------------------

// връща първия символ (елемент) на низа x;
char car(const char* x) {
    return x[0];
}
   
 // връща останалата част от низа x след, отделянето на първия елемент на низа x;
char* cdr(char* x) {
    char* newStr = new char[strlen(x)];
    for (size_t i =1 ; i < strlen(x); i++)
    {
        newStr[i-1] = x[i];   
    }

    return newStr;
}

//връща указател към символен низ, разположен в динамичната памет и 
//съдържащ конкатенацията на символa x със символния низ y;
char* cons(char x, const char* y) {
    
    char *buffer = new char[strlen(y) + 1];
    strcpy(buffer,y);
    buffer[strlen(y)] = x;
    return buffer;
}
    
// връща true тогава и само тогава, когато низовете съвпадат.
bool eq(const char* x, const char* y) {
    int i = 0;
    while ( i != strlen(x) || i != strlen(y))
    {   
        if (x[i] != y[i])
        {   
                
            return false;
        }
            i++;
    }
       return true;    
}

//----------------------------------------------------------------------------------------

 //връща указател към символен низ,разположен в динамичната памет
 // и съдържащ символите на x, зaписани в обратен ред;
char* reverse(char* x) {
    char* strNew = new char[strlen(x)+1];
    int count = 0;
    for (int i =  strlen(x)-1; i >= 0; --i)
    {
        strNew[count] = x[i];
        count++;
    }
    
    return strNew;
}
    
 // връща указател към символен низ,разположен в динамичната памет
 // и съдържащ копие на символния низ x;
 char* copy(char* x){
    char* strNew = new char[strlen(x)+1];
    strcpy(strNew, x);

    return strNew;
}

// която връща указател към символен низ, разположен в динамичната памет и 
//съдържащ първите n символа на символния низ x;
char* car_n( char* x, int n){
    char* newStr = new char[n+1];
    
    for (size_t i = 0; i < n; i++)
    {
        newStr[i] = x[i];
    }

    return newStr;
}

// връща останалата част от низа x след отделянето на първите n символа. 
//Предварително е известно, че x притежава поне n символа;
char* cdr_n(char* x, int n) {

    char* newStr = new char[n+1];
    int count =0;
    for (size_t i = n; i < strlen(x); i++)
    {
        newStr[count] = x[i];
        count++;
    }

    return newStr;
    
}
    
 // намира колко пъти символът ch се среща в символния низ x;
int number_of_char( char* x, char ch) {
        
    int i = 0;
    int count = 0;
    while ( i != strlen(x) )
    {   
        if (x[i] == ch)
        {                   
           count++;
        }
        i++;
    }

    return count;
}
    
 // намира колко пъти символният низ y се среща в символния низ x;
int number_of_substr( char* x, char* y) {

    int count = 0;
    int xLength = strlen(x);
    int yLength = strlen(y);

    char* newStr = new char[yLength];

    for (int i = 0; i < xLength; i++)
    {
        newStr = car_n(x, yLength);

        if (eq(newStr, y))
        {
            count++;
        }

        x = cdr(x);
    }

    return count;
}
    
// връща указател към символен низ, разположен в динамичната памет и 
//съдържащ символите на низа x, от който са изтрити всички срещания
//на символния низ y.
// char* delete_substr(char* x, char* y) {
//     char* newStr = new char[strlen(x)+1);

    
//     return newStr; 

// }
char * delete_substr(char *x, char *y)
{
	int xLength = strlen(x);
    int yLength = strlen(y);

    char* newStr = new char[xLength];
    int currentIndex = 0;

    char* extract = new char[yLength];

    for (int i = 0; i < xLength; i++)
    {
        extract = car_n(x, yLength);

        if (!eq(extract, y))
        {
            newStr[currentIndex] = car(x);

            currentIndex++;
        }
        else
        {
            x = cdr_n(x, yLength - 1);

            i += yLength - 1;
        }

        x = cdr(x);
    }

   newStr[currentIndex] = '\0';

    return newStr;
}

int main() {

    // char *str = "Adi";
    // std::cout<<strduplicate(str);
    //std::cout<<castIntToChar(10);
    // std::cout<<concatinate("Help", "Help");
    //std::cout<<cdr_n("hhoho",3);
    //std::cout<<reverse("help");
    //std::cout<<number_of_char("holaaa", 'a');
    std::cout<<delete_substr("DaDaDA","Da");

}