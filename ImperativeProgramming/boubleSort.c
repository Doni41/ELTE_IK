#include <stdio.h>
#include <stdlib.h>

void bouble(int* tomb, int db)  {
    //hátulról indítjuk a keresést, ha a legutolsó elem a végére került, azt békén hagyjuk
    for(int i = db - 1; i > 0; --i )   {
        for(int j = 0; j < i; ++j)   {
            if (tomb[j] > tomb [j + 1])   {
                double temp = tomb [j];
                tomb [j] = tomb [j + 1];
                tomb [j + 1] = temp;
            }
        }
    }
}

int main () {
    int tomb [10] = {12, 22, 5, 7, 2, 34, 33, 1, 24, 4};
    int db = 10;

    for(int i = 0; i < 10; ++i) {
        printf("%d, ", tomb[i]);
    }

    printf("\n");
    bouble(tomb, db);
    for(int i = 0; i < 10; ++i) {
        printf("%d, ", tomb[i]);
    }
    printf("\n");

    return 0;
}