#include "Napoje.h"
struct PrinterNapoi{
    void operator()  (Coca_cola &picie) {std::cout<<"Pozycja 1: "; picie.drukuj();}
    void operator()  (Coca_cola_zero &picie) {std::cout<<"Pozycja 2: "; picie.drukuj();}
    void operator()  (Sprite &picie) {std::cout<<"Pozycja 3: "; picie.drukuj();}
    void operator()  (Fanta &picie) {std::cout<<"Pozycja 4: "; picie.drukuj();}
    void operator()  (Cherry_coke &picie) { std::cout<<"Pozycja 5: "; picie.drukuj();}
};
struct kosztNapoi{
    int operator()  (Coca_cola &picie) {return picie.get_cena();}
    int operator()  (Coca_cola_zero &picie) {return picie.get_cena();}
    int operator()  (Sprite &picie) {return picie.get_cena();}
    int operator()  (Fanta &picie) {return picie.get_cena();}
    int operator()  (Cherry_coke &picie) {return picie.get_cena();}
};