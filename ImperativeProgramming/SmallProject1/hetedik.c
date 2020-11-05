// HETEDIK ESTIS HAZI FELADAT

// IRJAL EGY FGV-T, AMI EGY EGESZEKET TARTALMAZO TOMB ELEMEIT JOBBRA SHIFTELI EGGYEL
// AZ UTOLSO ELEM LEGYEN AZ ELSO
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hetedikseged.h"

int main () {
    // VALTOZOK DEKLARALASA
    int meret = 10;
    int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // EREDETI TÖMB KIIRATÁSA
    for (int i = 0; i < meret; ++i) {
        printf ("%d ", *(arr + i));
    }
    printf ("\n");

    // ELÁGAZÁSBA RAKNI, HOGY MELYIK IRÁNYBA SHIFTELJEN

    printf ("Jobbra vagy balra shifteljek? (j/b)\n");
    char valasz;
    // VALASZ BEOLVASASA
    scanf ("%c", &valasz);

    if (valasz == 'b') {
        // SHIFTELO FGV MEGHIVASA
        shift (arr, meret);
        // A SHIFTELÉS UTÁNI TÖMB KIIRATASA
        for (int i = 0; i < meret; ++i) {
        printf ("%d ", *(arr + i));
        }
        printf ("\n");
    }

    else {
        jobbshift (arr, meret);
        // A SHIFTELÉS UTÁNI TÖMB KIIRATASA
        for (int i = 0; i < meret; ++i) {
        printf ("%d ", *(arr + i));
        }
        printf ("\n");
    }

    return 0;
}