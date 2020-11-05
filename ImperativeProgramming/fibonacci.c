// FIBONACCI SOROZAT MEGOLDASA ITERATIV ES REKURZIV MODON IS

// BEBIZONYITHATO, HOGY MINDEN REKURZIV PROBLEMA MEGOLDHATO ITERATIVAN IS, ES FORDITVA
// NEMELY REKURZIV FGV EGYSZERUEN ATIRHATO CIKLUSRA

// FIBONACCI ITERATIV

#include <stdio.h>

int fibo_1 (int n) {
    int eloz = 1;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        int kov = f + eloz;
        eloz = f;
        f = kov;
    }
    return f;
}

// FIBONACCI REKURZIV

int fibo_2 (int n) {
    if (n < 2) {
        return n;
    }
    else {
        return fibo_2(n -2) + fibo_2 (n - 1);
    }
}

int main () {

    int n = 10;

    int alma = fibo_1(10);
    int korte = fibo_2(10);

    printf( "fibo_1 = %d \t fibo_2 = %d \n", alma, korte); 

    return 0;
}