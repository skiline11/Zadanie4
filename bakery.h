#ifndef ZADANIE4_BAKERY_H
#define ZADANIE4_BAKERY_H

#include "cake.h"
#include "pie.h"
#include <vector>
#include <map>

using namespace std;

template <class C, class A, A shelfArea, class... P>
class Bakery{
//, gdzie:
    C profits; //jest typem pola profits (dochód piekarni, początkowo wynosi 0)
    A shelfArea = shelfArea; //jest typem parametru shelfArea
//- shelfArea to dostępna przestrzeń na półkach
//- C... to typy wypieków, które są oferowane przez piekarnię
//
//Konstruktor klasy Bakery:
    enum type_p { ApplePie, CherryPie, CheeseCake, CreamCake };
    vector<P> product = {P};
    map<P,P> typy;
public:
    Bakery(P... products) {
        /*va_start(args, count);
        for(i = 0; i < count; i++)
            sum += va_arg(args, int);
        va_end(ap);*/
    }
    C getProfits() {
        return profits;
    }
    template <class Product>
    void sell() {}
    template <class Product>
    int getProductStock() {
        return
    }
    template <class Product>
    restock(int additionalStock) {}
}
//
//Podajemy w nim konkretne obiekty typów przekazanych jako parametry szablonu.
//
//W przypadku klasy Bakery dokonujemy następujących walidacji:
//- parametr C musi być typem liczbowym zmiennoprzecinkowym
//- parametr A musi być typem liczbowym całkowitym
//- typy zawarte w ramach parametru P muszą być unikatowe
//- produkty w piekarni nie mogą mieć łącznej powierzchni większej niż przestrzeń na półkach
//- typ wymiaru wszystkich produktów w piekarni musi być taki sam jak typ A
//- typ ceny wszystkich produktów (przeznaczonych na sprzedaż) w piekarni musi być taki sam
//jak typ C
//
//        Niespełnienie któregokolwiek z tych warunków musi skutkować błędem kompilacji.
//
//Klasa Bakery udostępnia metody publiczne:
//- C getProfits() - podaje dochody piekarni
//- template <class Product> void sell() - dokonuje sprzedaży produktu o typie Product,
//        zmniejszając jego stock o 1 i zwiększając dochód piekarni o jego cenę; jeśli stock
//wynosi 0, sprzedaż nie ma żadnego efektu; podanie typu, który nie występuje na stanie
//piekarni albo nie jest na sprzedaż (CherryPie i CheeseCake) musi powodować błąd
//        kompilacji
//- template <class Product> int getProductStock() - pobiera stan magazynowy produktu
//o typie Product; podanie typu, który nie występuje na stanie piekarni musi powodować
//        błąd kompilacji
//- template <class Product> restock(int additionalStock) - jeśli Product jest typem
//ApplePie i występuje na stanie piekarni, to zwiększ jego stock o additionalStock;
//w przeciwnym przypadku powinien wystąpić błąd kompilacji
//
//        Wszystkie komunikaty o błędzie kompilacji muszą zawierać stosowne opisy.

#endif
