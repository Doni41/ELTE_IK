// GNOME SORT
// HA AZ EGYMAS MELLETTIEK JO SORRENDBEN VANNAK, AKKOR LEPHETUNK EGYET ELORE
// HA ROSSZ SORRENDBEN VANNAK, AKKOR CSERE
// HA CSERE ÁLTAL ROSSZ SORREND KELETKEZIK, AZ CSAK A CSERE ELOTT LEHETETT, EZERT VISSZAFELE KELL LEPNI EGYET

#include <stdio.h>

void torperendez (int* t, int db) {
    int i = 0;
    while (i < db) {
        
        if (i == 0 || t [i - 1] <= t [i]) {
        //SORREND ELLENORZESE
            i++;
        }
        else {
        //CSERE
            double temp = t [i];
            t [i] = t [i - 1];
            t [i - 1] = temp;
            //VISSZAFELE LEPTETES
            i--;
        }
    }
}

int main() {

    //DECLARATION
    int db = 10;
    int t [] = {12, 33, 2, 54, 34, 66, 22, 65, 11, 10}; 

    //FUGGVENY HIVASA

    torperendez(t, db);

    //RENDEZETT TOMB KIIRATASA
    for (int i = 0; i < db; ++i) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}