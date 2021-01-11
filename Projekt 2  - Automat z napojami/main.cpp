#include "Symulacja.h"
int main() {
Symulacja symulacja; // uruchomienia symulacji automatu z napojami
while(symulacja.get_stan()){
    symulacja.akcja();
}
}
