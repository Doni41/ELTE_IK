// HANOI TORNYAINAK MEGOLDASA
// TOP-DOWN TERVEZES : FUGGVENY = FEKETE DOBOZ, NEM KELL BELE LATNUNK!
// FELTETELEZZUK, HOGY BIZONYOS FGV-EK HELYES BEMENETRE HELYES EREDMENYT ADNAK
// 

//MEGOLDASA : 

#include <stdio.h>

void hanoi(int n, char honnan, char seged, char hova) {
    if (n == 0) {
        return;
    }
    hanoi(n-1, honnan, hova, seged);
    printf("rakj 1 - et: %c->%c\n", honnan, hova);
    hanoi(n-1, seged, honnan, hova);
}

int main() {
    //FGV HIVASA
    hanoi(4, 'A' , 'B' , 'C');

    return 0;
}