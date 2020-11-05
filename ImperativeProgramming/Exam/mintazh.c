// ESTIS MINTA ZH FELADATSOR 

// IRJ EGY FGV-T, AMELY KET 100 ELEMU RENDEZETT TOMBOT VAR PARAMETERKENT, ES EGY HARMADIK PARAMETERKENT MEGKAPOTT 200 ELEMU TOMBBE MASOLJA A KET TOMB ELEMEIT RENDEZETTEN
// (ADOTT ALGORITMUS : STUKTOGRAMON)
// A Main () - BEN HOZD LETRE A HAROM TOMBOT, AMELYEKKEL MEGHIVOD A FGV-T

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zhheader.h"
#define Error 1
#define NoError 0


int main () {

    // ALVELETLENSZAMOK ELKERULESE MIATT RANDOM FGV NULLAZASA
    srand(time(0));
    // DEKLARACIOK
    int n1, n2;
    
    printf ("Adja meg az elso tomb nagysagat: ");
    scanf ("%d", &n1);

    printf ("Adja meg a masodik tomb nagysagat: ");
    scanf ("%d", &n2);

    // DINAMIKUSAN FOGLALT TÖMB, PARAMÉTEREZHETŐ
    int* s = (int*) malloc (n1* sizeof(int));
    int* z = (int*) malloc (n2* sizeof(int));

    for (int i = 0; i < n1; ++i) {
        // RANDOM SZAMOKKAL VALO FELTOLTESE A TOMBNEK
        s [i] = rand() % 100;
    }
    
    for (int i = 0; i < n2; ++i) {
        // RANDOM SZAMOKKAL VALO FELTOLTESE A TOMBNEK
        z [i] = rand() % 100;
    }
    
    // OSSZEFESULENDO TOMB
    int* sz = (int*) malloc ((n1+n2)* sizeof(int));

    // KIIRATASA AZ EREDETI TOMBNEK
    for (int i = 0; i < n1; ++i) {
        printf ("%d ", *(s + i));
    }
    printf("\n");

    for (int i = 0; i < n2; ++i) {
        printf ("%d ", *(z + i));
    }
    printf("\n");
    printf("\n");

    // RENDEZES MEGHIVASA
    Sort_S (s, n1);
    Sort_Z (z, n2);

    printf ("A rendezett tombok:\n");
    for (int i = 0; i < n1; ++i) {
        printf ("%d ", s [i]);
    }
    printf("\n");

    for (int i = 0; i < n2; ++i) {
        printf ("%d ", z[i]);
    }
    printf("\n");

    // OSSZEFESULO RENDEZES (MERGE SORT)

    merge (s, z, sz, n1, n2);

    // VEGLEGES TOMB ELEMEINEK A KIIRATASA

    for (int i = 0; i < (n1+n2); ++i) {
        printf ("%d ", sz[i]);
    }
    printf("\n");

    free(s);
    free(z);
    free(sz);


    return NoError;

}