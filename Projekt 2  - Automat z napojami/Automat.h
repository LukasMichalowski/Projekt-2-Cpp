#include "PrinterNapoi.h"
#include <variant>
#include <memory>
#include "Monety.h"

class Automat{
    unsigned int n; // ilosc napoji w automacie
private:
    using napoje_coca = std:: variant<Coca_cola,Coca_cola_zero,Sprite,Fanta,Cherry_coke>;
    std::unique_ptr<napoje_coca []> napoje ;
    std::unique_ptr<unsigned int []> il_napoji ; // ilosc napoji w automacie, odpowiednio indeks odpowiada tablicy napoje[]
    std::unique_ptr<Monety> monetki = std::make_unique<Monety>();
public:
    Automat() {
        n=5; // ilość rodzajow napojów w automacie
        napoje = std::make_unique<napoje_coca []>(n);
        il_napoji = std::make_unique<unsigned int []>(n);
        for(int i=0;i<n;++i) // liczba napoji w automacie
            il_napoji[i]=10;
        napoje[0] = Coca_cola(); // przypisanie do tablicy za jaki napoj odpowiada
        napoje[1] = Coca_cola_zero();
        napoje[2] = Sprite();
        napoje[3] = Fanta();
        napoje[4] = Cherry_coke();
    }

    void drukuj_napoje(){
        for(int i =0; i<5; i++){
            std::visit(PrinterNapoi{},napoje[i]);
            std::cout<<". Ilosc napoji w automacie: "<<il_napoji[i]<<std::endl; //wyswietlanie napoji w automacie
        }
    }

    void stan_konta(){
        monetki->drukuj_stan_konta(); // stan konta automatu (ile pieniazkow jest wrzuconych)
    }

    void wrzuc_pieniazek()
    {
        double x ;
        std::cout<<"Automat przyjmuje 0.5 zl, 1 zl, 2 zl , 5 zl. Wrzuc monete: "; //symulacja wrzucania monety
        std::cin>>x;
        monetki->wrzuc_pieniazek((int)(100*x)); // wrzuc pieniazek przyjmuje tylko int
        std::cout<<std::endl;
    }

    void wydaj_reszte(){
        monetki->wydaj_reszte();
    }

    void podaj_napoj_coca_cola(){
        if(monetki->test_wydaj_reszte(std::visit(kosztNapoi{}, napoje[0])) == 0 && il_napoji[0] > 0) { //warunek wydania napoju,  musi byc w stanie wydac reszte, stan konta odpowiedni oraz il napoji musi sie zgadzac
                std::cout << "Wydano coca cole, koszt 2.50 zl." << std::endl;
                il_napoji[0] -= 1; //zmniejszenie ilosci napoji w automacie
                monetki->zaplac_za_napoj(std::visit(kosztNapoi{}, napoje[0]));
        } else
            std::cout<<"Blad!! Sprawdz stan konta lub liczbe napoji w automacie. Automat moze nie posiadac monet do wydania reszty."<<std::endl;
    }
    void podaj_napoj_coca_cola_zero(){
        if(monetki->test_wydaj_reszte(std::visit(kosztNapoi{}, napoje[1])) == 0 && il_napoji[1] > 0) {
            std::cout << "Wydano coca cole zero, koszt 3.00 zl." << std::endl;
            il_napoji[1] -= 1;
            monetki->zaplac_za_napoj(std::visit(kosztNapoi{}, napoje[1]));
        }else
            std::cout<<"Blad!! Sprawdz stan konta lub liczbe napoji w automacie. Automat moze nie posiadac monet do wydania reszty."<<std::endl;
    }
    void podaj_napoj_sprite() {
        if(monetki->test_wydaj_reszte(std::visit(kosztNapoi{}, napoje[2])) == 0 && il_napoji[2] > 0) {
        std::cout << "Wydano sprite, koszt 2.00 zl." << std::endl;
        il_napoji[2]-= 1;
        monetki->zaplac_za_napoj(std::visit(kosztNapoi{}, napoje[2]));
        } else
             std::cout<<"Blad!! Sprawdz stan konta lub liczbe napoji w automacie. Automat moze nie posiadac monet do wydania reszty."<<std::endl;
}
    void podaj_napoj_fanta(){
        if(monetki->test_wydaj_reszte(std::visit(kosztNapoi{}, napoje[3])) == 0 && il_napoji[3] > 0) {
            std::cout << "Wydano fante, koszt 1.50 zl." << std::endl;
            il_napoji[3] -= 1;
            monetki->zaplac_za_napoj(std::visit(kosztNapoi{}, napoje[3]));
        } else
            std::cout<<"Blad!! Sprawdz stan konta lub liczbe napoji w automacie. Automat moze nie posiadac monet do wydania reszty."<<std::endl;
    }
    void podaj_napoj_cherry_coke(){
        if(monetki->test_wydaj_reszte(std::visit(kosztNapoi{}, napoje[4])) == 0  && il_napoji[4] > 0 ) {
                std::cout << "Wydano cherry coke, koszt 3.50 zl." << std::endl;
                il_napoji[4] -= 1;
                monetki->zaplac_za_napoj(std::visit(kosztNapoi{}, napoje[4]));
        } else
            std::cout<<"Blad!! Sprawdz stan konta lub liczbe napoji w automacie. Automat moze nie posiadac monet do wydania reszty."<<std::endl;
    }


};

