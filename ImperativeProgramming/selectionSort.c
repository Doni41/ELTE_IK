#include <stdio.h>

//SELECTION SORT - KOZVETLEN KIVALASZTASSAL CSERE

//MEGKERESI A RENDETETLEN TOMBRESZLET LEGKISEBB ELEMET, ES AZ ELEJERE RAKJA
//MASNEVEN MINIMUM KERESOS RENDEZES

void selection(int* t, int db) {
    for (int i = 0; i < db - 1; ++i) {
        int minindex = i;
        for (int j = i + 1; j < db; ++j) {
            if (t [j] < t [minindex]) {
                minindex = j;
            }
        }
        if (minindex != i) {
            double temp = t [minindex];
            t [minindex] = t [i];
            t [i] = temp;
        }
    }
}

int main() {

    //DECLARATION
    int db = 10;
    int t [] = {12, 33, 2, 54, 34, 66, 22, 65, 11, 10}; 

    //FUGGVENY HIVASA

    selection(t, db);

    //RENDEZETT TOMB KIIRATASA
    for (int i = 0; i < db; ++i) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}

