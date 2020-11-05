#include <stdio.h>
#include <stdbool.h>

    //NEM JAVITOTT BOUBLE SORT

    void bouble (int* t, int db) {
        for (int i = db -1; i > 0; --i) {
            for(int j = 0; j < i; ++j) {
                if(t[j] > t [j + 1]) {
                    int temp = t [j];
                    t [j] = t [j + 1];
                    t [j + 1] = temp;
                }
            }
        }
    }

    //JAVITOTT BOUBLE SORT - megnézzók, hogy történt-r csere, feltételezve, hogy akkor nem kell, hogy tovább fusson a ciklus

    void javbouble(int* t, int db)  {
        //egyre rövidebb tömb ciklusa
        for (int i = db - 1; i > 0; --i) {
            bool voltcsere = false;
            for (int j = 0; j < i; ++j) {
                if (t [j] > t [j + 1]) {
                    int temp = t [j];
                    t [j] = t [j + 1];
                    t [j + 1] = temp;
                    voltcsere = true;
                }
            }
            if (!voltcsere) { 
                break;
            }
        }
    }

int main() {

    int db = 10;
    int t [] = {12, 33, 2, 54, 34, 66, 22, 65, 11, 10}; 


    
    javbouble(t, db);
    //bouble (t, db);

    for (int i = 0; i < db; ++i) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}

