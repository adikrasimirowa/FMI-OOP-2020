// Някои от следните задачи са взаимствани от библиотеката на JavaScript
// за функционално програмиране “lodash”. За примери и повече информа-
// ция: документация на библиотеката.
// 11.3. Да се дефинира функция negate(p), където p : A → bool е едноместен
// предикат. negate да връща предиката ¬p.
// 11.4. Да се дефинира функция repeated(k,f), където k ≥ 0 е естествено
// число, а f : A → A е едноместна функция. Ако h = repeated(k, f ),
// то h : A → A е такава, че h = f k (x) = f (f... (x)).
// | {z }
// k
// 11.5. Да се дефинира функция createfn(args,values), където args е вектор
// с елементи от тип U, а values е вектор с елементи от тип V. Двата вектора
// са с еднакъв брой елементи. Ако h = createf n(args, values), то h : U →
// V . По дефиниция h(u) = v т.с.т.к. u е елемент на args с индекс i, a
// v = values[i] (при повече от едно срещания на u приемаме най-малкия
// индекс). Ако u не е елемент на values, функцията h е недефинирана.
// 11.6. Да се дефинира функция switch(n,f,g), където n ≥ 1 е естествено
// число, а f, g : A → B са едноместни функции. switch да връща функция
// h : A → B, която при първите си n извиквания да дава същите стойности
// като f, а след това - като g.
// 5411.7. Да се дефинира функция before(n,f), където n ≥ 1 е естествено число,
// а f : A → B е едноместна функция от произволен тип. before да връща
// функция h : A → B, която при първите си n извиквания да дава същите
// стойности като f, а след това - последната върната от f стойност.



#include <iostream>

template<class T>
using fn = (*T)(T&);

template <class T>
void map(T arr[], int arrSize, fn<T> func) {

    for (size_t i = 0; i < arrSize; i++)
    {
        arr[i] = func(arr[i]);
    }
    
}
struct S {
    int a,b,c;
    friend std::istream& operator>>(std::istream& in, S element);
    friend std::iostream& operator<<(std::iostream& out, S element);
};

template <class T> 
T fill(T& element) {
  //  T tmp;
    std::cin>>element;
    return element;
}
template <class T> 
T print(T& element) {
    return element;
}

friend std::istream& operator>>(std::istream& in, S element) {
        in>>element.a>>element.b>>element.c;
        return in;
 }

friend std::iostream& operator<<(std::iostream& out, S element){

}

int main() {
int arr[] = {1,2,3,4,5,6 };
map<5>(A,5,fill);
}