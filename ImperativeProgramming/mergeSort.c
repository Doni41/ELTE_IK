#include <stdio.h>

// MERGE SORT = OSSZEFESULO RENDEZES BEMUTATASA
// KET RENDEZETT TOMBBOL INDUL KI, ES AZOK ELEMEIT EGY HARMADIK TOMBBE RENDEZI
// REKURZIV ALGORITMUS
// UJ TOMB IS RENDEZETT LESZ
// KET TOMB ELEJEROL MINDIG A KISEBB ELEMET VESSZUK, ES AZT MASOLJUK A CELTOMBBE
// MINDEN LEPESBEN EGY ELEM ROGTON A HELYERE KERUL

// HAROM INDEXSZEL FOGUNK ITT DOLGOZNI

void merge (int* t1, int* t2, int n1, int n2, int* cel) {
    int i = 0;
    int j = 0;
    for (int c = 0; c < n1 + n2; c++) {
        if (i < n1 && (j >= n2 || t1 [i] <= t2 [j])) {
            cel [c] = t1 [i];
            i++;
        }
        else {
            cel [c] = t2 [j];
            j++;
        }
    }
}

int main () {

    //DECLARATION
    int t1 [] = {10, 12, 13, 22, 45, 78};
    int n1 = 6;

    int t2 [] = {5, 11, 14, 23, 25, 56, 68, 99};
    int n2 = 8;

    int cel[14];

    merge(t1, t2, n1, n2, cel);

    for(int i = 0; i < 14; ++i) {
        printf("%d ",  *(cel + i));
    }
    printf("\n");

    return 0;
}