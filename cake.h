#ifndef ZADANIE4_CAKE_H
#define ZADANIE4_CAKE_H

template <class T, T length, T width>
class CheeseCake : Cake { // i
    T length = length;
    T width = width;
    int initialStock;
public:
    explicit CheeseCake(int initialStock) : initialStock(initialStock) {}
    static double getArea() {
        return 0.30102999566 * length * width;
    }
    int getStock() {
        return initialStock;
    }
};

template <class T, T length, T width, class P>
class CreamCake : Cake {
    T length = length;
    T widtgh = width;
    P price;
    int initialStock;
public:
    explicit CreamCake(int initialStock, P price) : initialStock(initialStock), price(price) {}
    static double getArea() {
        return 0.30102999566 * length * width;
    }
    int getStock() {
        return initialStock;
    }
    void sell() {
        if(initialStock != 0) initialStock --;
    }
    P getPrice() {
        return price;
    }
};
//, gdzie:
//- T jest typem parametrów length i width
//- length i width to długość i szerokość ciasta
//- P jest typem pola price
//
//Konstruktor klasy CheeseCake:
//CheeseCake(int initialStock)
//
//Konstruktor klasy CreamCake:
//CreamCake(int initialStock, P price)
//
//Podobnie jak w przypadku placków, parametry szablonowe dla ciast muszą być walidowane -
//T musi być typem liczbowym całkowitym, a P typem liczbowym zmiennoprzecinkowym. Podanie
//typów niespełniających tych kryteriów musi powodować błąd kompilacji.
//
//Obie klasy udostępniają metody publiczne:
//static double getArea() - wylicza powierzchnię ciasta, przy czym ciasta są prostokątami
//  o bokach length na width*ln(2)
//int getStock() - podaje aktualny stan magazynowy ciasta
//
//CreamCake udostępnia dodatkowo metody publiczne:
//void sell() - zmniejsza stock o 1, stock nie może być mniejszy od 0
//P getPrice() - podaje cenę ciasta
//
//Wartość ln(2) musi być wyliczona w trakcie kompilacji. Można do tego użyć dowolnego
//algorytmu. Poprawność obliczeń będzie sprawdzana przy założeniu dokładności do 6 miejsca
//po przecinku.
//
//Szablony klas CheeseCake i CreamCake powinny być specjalizacją ogólnego szablonu

template <class T, T length, T width>
class Cake{
};
#endif
