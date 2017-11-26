#ifndef ZADANIE4_PIE_H
#define ZADANIE4_PIE_H

template <class R, R radius>
class CherryPie : Pie{
    R radius = radius;
    int initialStock;
public:
    CherryPie(int initialStock) : initialStock(initialStock) {};
    static double getArea() {
        return radius * radius * 3.14;
    }
    int getStock(){
        return initialStock;
    }
};
template <class R, R radius, class P>
class ApplePie : Pie{
    R radius = radius;
    P price;
    int initialStock;
public:
    ApplePie(int initialStock, P price) : initialStock(initialStock), price(price) {};
    static double getArea() {
        return radius * radius * 3.14;
    }
    int getStock(){
        return initialStock;
    }
    void sell() {
        if(initialStock != 0) initialStock --;
    }
    P getPrice() {
        return price;
    }
};
//- R jest typem parametru radius
//- radius jest promieniem placka
//- P jest typem pola price
//
//Konstruktor klasy CherryPie:
//CherryPie(int initialStock)
//
//Konstruktor klasy ApplePie:
//ApplePie(int initialStock, P price)
//
//Parametr initialStock określa początkowy stan magazynowy (musi być większy od 0). Należy
//dokonać walidacji typów - R musi być typem liczbowym całkowitym, a P typem liczbowym
//zmiennoprzecinkowym. Podanie typów niespełniających tych kryteriów musi powodować błąd
//kompilacji.
//
//Obie klasy udostępniają metody publiczne:
//static double getArea() - wylicza powierzchnię placka, przy czym placki są idealnymi
//  kołami
//int getStock() - podaje aktualny stan magazynowy placka
//
//ApplePie udostępnia dodatkowo metody publiczne:
//void sell() - zmniejsza stock o 1, stock nie może być mniejszy od 0
//P getPrice() - podaje cenę placka
//
//Wartość liczby pi musi być wyliczona w trakcie kompilacji. Można do tego użyć dowolnego
//algorytmu. Poprawność obliczeń będzie sprawdzana przy założeniu dokładności do 6 miejsca
//po przecinku.
//
//Szablony klas CherryPie i ApplePie powinny być specjalizacją ogólnego szablonu
template <class R, R radius>
class Pie{
};//gdzie etc to pozostałe parametry, których trzeba użyć
//w implementacji - ich dobór należy do Ciebie).
//

#endif
