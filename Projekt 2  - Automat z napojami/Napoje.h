#include <iostream>
#include <string>
#include <utility>

class Napoj {
public:
    explicit Napoj(std:: string s): nazwa(std::move(s)) {}
    virtual void drukuj() { std:: cout<<nazwa<<std::endl;}
protected:
    std:: string nazwa;
};

class Coca_cola : public Napoj{
public:
    Coca_cola(): Napoj("Coca cola") {}
    void drukuj() override { std:: cout<<nazwa<<", cena: "<<(double ) cena/100<<"zl";} //wyswietlanie ceny napoju w zlotowkach
    static int get_cena() { return cena;}
private:
    static constexpr int cena = 250; // cena napoju w groszach
};

class Coca_cola_zero : public Napoj{
public:
    Coca_cola_zero(): Napoj("Coca cola zero") {}
    void drukuj() override { std:: cout<<nazwa<<", cena: "<<(double)cena/100<<"zl";}
    static int get_cena() { return cena;}
private:
    static constexpr int cena = 300;
};

class Sprite : public Napoj{
public:
    Sprite(): Napoj("Sprite") {}
    void drukuj() override { std:: cout<<nazwa<<", cena: "<<(double)cena/100<<"zl";}
    static int get_cena() { return cena;}
private:
    static constexpr int cena = 200;
};

class Fanta : public Napoj{
public:
    Fanta(): Napoj("Fanta") {}
    void drukuj() override { std:: cout<<nazwa<<", cena: "<<(double ) cena/100<<"zl";}
    static int get_cena() { return cena;}
private:
    static constexpr int cena = 150;
};

class Cherry_coke : public Napoj{
public:
    Cherry_coke(): Napoj("Cherry coke") {}
    void drukuj() override { std:: cout<<nazwa<<", cena: "<<(double ) cena/100<<"zl";}
    static int get_cena() { return cena;}
private:
    static constexpr int cena = 350;
};


