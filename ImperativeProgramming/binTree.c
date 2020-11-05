#include <stdio.h>

int binTree (int* t, int db, int mit) {
    int min = 0;
    int max = db - 1;
    int kozep = (min+max)/2;

    while (min < max && t[kozep] != mit)    {
        if (t [kozep < mit]) {
            min = kozep + 1;
        }
        else    {
            max = kozep - 1; 
        }
        kozep = (min + max)/2;
    }
    if (t[kozep] == mit) {
        return kozep;
    }
    else
        return -1;

    //return min <= max ? kozep : -1;
}

int main()  {
    int t [] = {12, 33, 45, 66, 78, 98, 100, 101, 112, 234};
    int db = 10;
    int mit = 33;

    int egyiktalalat = binTree (t, db, mit);
    printf ("A keresett szám  : %d \n", egyiktalalat);

    return 0;
}
