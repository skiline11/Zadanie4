#ifndef ZADANIE4_CAKE_H
#define ZADANIE4_CAKE_H

#include<iostream>
#include<typeinfo>
#include<cassert>
#include<cmath>

using namespace std;

// użyłem metody szeregu Nilakantha
constexpr double count_pi(double x){
    return x < 400 ? 4 / ((2*x * (2*x + 1) * (2*x + 2))) - count_pi(x + 1) : 0; // UWAGA : rekurencja może miec maksymalnie 512 poziomów, więc ja licze do 400, ale już 100 daje precyzję 6 znaków
};
constexpr double PI = 3 + count_pi(1);

template <class R, int radius, class P, bool isSellable>
class Pie
{
protected:
    int stock;
    P price;
public:
    Pie();
    Pie(int initialStock, P price = 0) {
        assert(initialStock > 0);
        static_assert(is_integral<R>::value, "R powinno być typem całkowito liczbowym\n");
        static_assert(is_floating_point<P>::value, "P powinno byc typem zmiennoprzecinkowym\n");
        this->stock = initialStock;
        this->price = price;
    }

//    Obie klasy udostępniają metody publiczne:
//    static double getArea() - wylicza powierzchnię placka, przy czym placki są idealnymi
//            kołami
//    int getStock() - podaje aktualny stan magazynowy placka
    static double getArea() {
        return PI * radius * radius;
    }
    int getStock() {
        return stock;
    }

//    ApplePie udostępnia dodatkowo metody publiczne:
//    void sell() - zmniejsza stock o 1, stock nie może być mniejszy od 0
//    P getPrice() - podaje cenę placka
    template <bool s = isSellable, typename = typename std::enable_if<s, void>::type>
    void sell() {
        assert(this->stock > 0);
        this->stock--;
    }
    template <bool s = isSellable, typename = typename std::enable_if<s, void>::type>
    P getPrice() {
        return price;
    }
};

template <class R, int radius>
using CherryPie = Pie<R, radius, int, false>;

template <class R, int radius, class P>
using ApplePie = Pie<R, radius, P, true>;

#endif //ZADANIE4_CAKE_H