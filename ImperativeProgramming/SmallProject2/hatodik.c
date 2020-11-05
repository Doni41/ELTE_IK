// HATODIK ESTIS HAZI FELADAT

// IRJ FGV-T, AMI PARAMETERKENT MEGKAPOTT INT TOMB ELEMEI KOZUL VISSZAADJA AZT, AMELYIK A LEGTOBBSZOR SZEREPEL A TOMBBEN
// HIVD MEG A FGV-T, AZ EREDMENYT IRD KI A STANDARD OUTPUT-RA

#include <stdio.h>
#include <stdlib.h>
#include "hatodikheader.h"

int main () {

    // DEKLARACIOK
    int arr [] = {12, 31, 1, 54, 34, 22, 0, 56, 37, 78, 12, 98, 33};
    int meret = 13;

    BoubleSort(arr, meret);


    for (int i = 0; i < meret; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("A leggyakrabban elofordulo szam : %d\n", MostFrequent(arr, meret));

    int leggyakoribb = MostFrequent(arr, meret);
    printf("Maskeppen megadva a leggyakoribb elem : %d\n", leggyakoribb);

    return 0;
}