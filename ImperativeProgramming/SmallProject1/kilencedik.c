// KILENCEDIK ESIT HAZI FELADAT 

// A STANDARD OUTOUTROL KERJ BE EGY EGESZ SZAMOT, AMI MEGADJA, HOGY MENNIY EGESZ SZAM FOG UTANA KERULNI EGY TOMBBE
// EZEKET OLVASD BE EGY DINAMIKUSAN ALLOKALT TOMBBE, MAJD FORDITOTT SORRENDBE IRD KI

#include <stdio.h>
#include <stdlib.h>

int main () {

    // ELSO SZAM BEKERESE
    int meret;
    printf ("Add meg a tomb meretet : ");
    scanf ("%d", &meret);

    // TOMBRE MUTATO POINTER DEKLARALASA + MEMORIA ALLOKALASA
    int* arr = (int*)malloc (meret* sizeof(int));
    if (arr = NULL) {
        return NULL;
    }

    // ELEMEK BEKERESE
    printf ("Adja meg a tomb elemeit!\n");
    for (int i = 0; i < meret; ++i) {
        scanf("%d", &arr[i]);
    }

    // ELEMEK KIIRATASA FORDITOTT SORRENDBEN

    



    return 0;
}