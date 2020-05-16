#include <iostream>
#include <cstring>
//Шаблони и указатели към функции | Шаблони на функции

//въвежда от клавиатурата стойностите на елементите на
// масива array от произволен тип T с големина n.
template <class T>
void input ( T array[] ,int n) {
        std::cout<<"Enter";
        for (size_t i = 0; i < n; i++)
        {
            std::cin>>array[i];
        } 

        for (size_t i = 0; i < n; i++)
        {
            std::cout<<" "<<array[i];
        } 
}

// проверява дали елементите на масива array от произволен тип T с големина n 
// образуват монотонно-растяща редица спрямо релацията <.

template <class T>
bool ordered(T array, int n) {

    for (int i = 1; i < n; ++ i) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
    return true;
}

//проверява дали x е елемент на масива array от произволен тип T с големина n.
template <class T,class M>
bool member(T array, int n, M x) {
    for (int i = 1; i < n; ++ i) {
            if (array[i] == x) {
                return true;
            }
        }
    return false;
}

//---------------------------------------------------------------------------------

//Шаблони и указатели към функции | Функции от високо ниво
// !!!! В РЕШЕНИЯТА НА ЗАДАЧИТЕ ИМА НЕТОЧНОСТИ!!!!!!!!

// 8.4. Да се дефинира масив functions с 5 елемента от тип функция double →
// double.
// Да се дефинират 5 произволни функции от този тип и адресите
// им да се се присвоят на елементите на масива.
// При въведено от клавиатурата число x : double, да се намери и отпечата
// индексът на тази функция в масива functions, чиято стойност е най-
// голяма в точката x спрямо стойностите на всички функции в масива.
// Ако има няколко такива функции, да се отпечата индекса на коя да е от
// тях.

using doubleFunc = double (*) (double);
double func1(double v1) { return v1;}
double func2(double v2) { return 8.5;}
double func3(double v3) { return 5.6;}
double func4(double v4) { return 2.5;}
double func5(double v5) { return 7.6;}
doubleFunc functions[5] = {func1,func2,func3,func4,func5};

void test(double x, doubleFunc* arr) {
    double largest = 0;
    for (size_t i = 0; i < 5; i++)
    {   
            if(largest < (*arr[i])(x)) {
                largest = i;
            }    
         
    }
    std::cout<<largest<<std::endl; 
}


//----------------------------------------------------------------------------------

// 8.5. Да се дефинира функция double fmax([подходящ тип]f, [подходящ тип]g,
// double x), където f и g са две произволни функции от тип double →
// double, за които приемаме, че са дефинирани в x. Функцията да връща
// по-голямата измежду стойностите на f и g в точката x.

using funcDouble = double(*) (double); 

double f (double f1) {
    return f1;
}
double g (double g1) {
    return g1+1;
}
double fmax(funcDouble f, funcDouble g, double x) {

        if((*f)(x) > (*g)(x)) {
            return (*f)(x);
        } else
        {
            return (*g)(x);
        }       
}

//-----------------------------------------------------------------------------

// 8.6. Да се дефинира функция double maxarray ([подходящ тип] array, int
// n, double x), където array е масив от функции от тип double → double
// с големина n.
// Функцията maxarray да връща най-голямата измежду стойностите на
// всички функции от масива в точката x като приемаме, че всички те са
// дефинирани в тази точка.
// Задачата да се реши със и без използването на функцията fmax от пре-
// дишната задача.
// Да се реализира и изпълни подходящ тест за функцията.


using doubleFn = double(*) (double);

double maxarray(doubleFn* array, int n, double x) {
        for (size_t i = 0; i < n; i++)
        {
            return fmax(array[i],array[i+1],x);
        }     
}

//-----------------------------------------------------------------------------

// Да се дефинира функция void sort([подходящ тип]array, int n, [подходящ
// тип]compare), където array е масив от n структури от тип S.
// Типът на функцията compare да се подбере така, че чрез нея да може
// да се реализира произволна наредба за типа S, т.е. функцията да може
// да сравнява “по големина” две структури от S по произволен критерий.
// Да се създаде и инициализира масив с 5 структури от тип S. Като се
// използва функцията sort да се сортира масива по веднъж по всеки от
// следните начини:
// а) по полето a
// б) по полето b
// в) лексикографски по тройката (a, b, c)

struct S {
    int a; 
    int b; 
    int c;
};

using structArr ; 
template<class T, class M>
void sort(T array, int n, M compare) {

}

int main() {
    // char array[4];
    // input(array,3);
    //int arr[] = {1,3,5,1};
    //std::cout<<ordered(arr,4);<
    //std::cout<<member(arr,4,3.6)<;
    //std::cout<<addOne(5);
    //double arr[5] = {addOne};
    //std::cout<<*arr;
    //std::cout<<maxarray(addOne,4,5);
   // test(4.5,functions);

   //std::cout<<fmax(f,g,5.3);
    std::cout<<maxarray(functions,5,4.5);
    return 0;
}