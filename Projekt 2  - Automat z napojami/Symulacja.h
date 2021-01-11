#include "Automat.h"


class Symulacja{
    bool stan;
    Automat automat;
public:
    Symulacja(): stan(true){}
    [[nodiscard]] bool get_stan() const {return stan;}
    void akcja(){
            std::cout<<"Do wyboru:"<<std::endl;
            automat.drukuj_napoje();
            std::cout<<"Pozycja 6: Wrzuc pieniadze. Automat przyjmuje 0.5 zl, 1 zl, 2 zl, 5 zl."<<std::endl;
            std::cout<<"Pozycja 7: Wydaj reszte."<<std::endl;
            std::cout<<"Pozycja 0: Zakonczenie pracy automatu."<<std::endl;
            automat.stan_konta();
            int akcja;
            while(!(std::cin >> akcja)){ // warunek wrzucenia odpowiedniej monety
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Niepoprawna komenda. Wybierz pozycje ponownie: ";
            }
            if(akcja == 1)
                automat.podaj_napoj_coca_cola();
            else if(akcja == 2)
                automat.podaj_napoj_coca_cola_zero();
            else if(akcja == 3)
                automat.podaj_napoj_sprite();
            else if(akcja == 4)
                automat.podaj_napoj_fanta();
            else if(akcja == 5)
                automat.podaj_napoj_cherry_coke();
            else if(akcja == 6)
                automat.wrzuc_pieniazek();
            else if(akcja == 7)
                automat.wydaj_reszte();
            else if(akcja == 0){ // zakonczenie pracy automatu przez admina, warunek podania hasla "admin"
                std::string s;
                std::cout<<"Podaj haslo: ";
                std::cin>>s;
                if(s == "admin")
                {
                    stan = false;
                    return;
                }
                else
                    std::cout<<"Nieprawidlowe haslo!!!"<<std::endl;

            }
            else
                std::cout << "BLAD!! Niepoprawna komenda!!" << std::endl;



    }

};