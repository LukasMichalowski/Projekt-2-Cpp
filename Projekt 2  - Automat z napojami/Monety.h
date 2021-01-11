
class Monety{
    int stan_konta; // stan konta w automacie
    int il_monet[4]{}; //ilosc monet danego nomianlu
    static constexpr int nominaly[4] = {500,200,100,50}; // dostepny nominaly 5 zl , 2 zl , 1 zl , 50 gr
public:


    Monety() {
        stan_konta = 0;
        for(int & i : il_monet)
            i = 25; // poczatkowa ilosc monet kazdego nominalu wynosi 25
    }
    void drukuj_stan_konta() const{std::cout<<"Stan konta: "<< (double)stan_konta/100<<" zl."<<std::endl;}

    void wrzuc_pieniazek(int x){
        if(x==50) // 50 gr
        {
            il_monet[3]+=1;
            stan_konta +=x;
        }
        else if(x == 100){ //100 gr itd.
            il_monet[2]+=1;
            stan_konta +=x;
        }
        else if(x == 200)
        {
            il_monet[1]+=1;
            stan_konta +=x;
        }
        else if(x == 500)
        {
            il_monet[0]=1;
            stan_konta +=x;
        }
        else
            std::cout<< "Nieznany nominal"<< std::endl;
    }

    void zaplac_za_napoj(int cena){
        stan_konta-=cena;
    }



    void wydaj_reszte() // implementacja alogrytmu zachłannego do wydania reszty
    {
        int n;
        while (stan_konta>0){
            n = 0;
            for(int i = 0; i<4;++i)
            {
                if ((nominaly[i] <= stan_konta) && (nominaly[i] > n) && (il_monet[i]>0)){
                    n = nominaly[i];
                    il_monet[i]-=1;
                }
            }
            stan_konta -= n;
        }

    }

    int test_wydaj_reszte(int x){ // metoda testowa czy automat jest w stanie wydac reszte przy zamowieniu napoju oraz stan konta odpowiedni do zakupu
        int n;
        int virtualny_stan_konta = stan_konta-x;
        int virtual_il_monet[4];
        for(int j =0;j<4;j++)
            virtual_il_monet[j]=il_monet[j];
        while (virtualny_stan_konta>0){
            n = 0;
            for(int i =0; i<4;++i)
            {
                if ((nominaly[i] <= virtualny_stan_konta) && (nominaly[i] > n)&& (virtual_il_monet[i]>0)){
                    n = nominaly[i];
                    virtual_il_monet[i]-=1;
                }
            }
            if(n == 0) {
                break;
            }
            virtualny_stan_konta -= n;
        }
        return virtualny_stan_konta;
    }

};
