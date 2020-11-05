// EGY GYARBAN FEMRUDAKAT GYARTANAK 
// MEGMUNKALAS PONTATLANSAGA MIATT ELTEROEK - HOSSZUK 999 ES 1001 KOZOTT VAN

// DEFINIALJ TIPUST, AMELY EGY RUD MINIMALIS ES MAXIMALIS HOSSZAT TAROLJA

// IRJ EGY FGV-T, AMELY PARAMETERKENT KAPJA KET RUD ADATAIT, ES VISSZATERESI ERTEKE EGY RUD, AMELY EZEK OSSZEGE

// IRJ EGY FGV-T AMELY VISSZAADJA EGY PARAMETERKENT KAPOTT RUD ATLAGOSS HOSSZAT

// EGESZITSD KI EGY TELJES PROGARMMA, AMELYBEN LETREHOZOL EGY 991-1001 ES EGY 498-502 TUDAT
// SZAMOLJA KI A PROGRAM A FGV-EKKEL, HOGY MEKKORA EZEK OSSZEGE MINIMALISAN, ES MAXIMALISAN, ES ATLAGOSAN

#include <stdio.h>
#include <math.h>

typedef struct Rud {
    double min;
    double max;
} Rud;

double Atlag (Rud i) {
    double hossz = (i.min + i.max) / 2; 
    return hossz;
}

Rud Osszeg (Rud i1, Rud i2) {
    Rud uj;
    uj.min = i1.min + i2.min;
    uj.max = i1.max + i2.max;

    return uj;
}

int main () {

    Rud i1 = {999 , 1001};
    Rud i2 = {498 , 502};
    Rud o;

    o = Osszeg (i1, i2);

    printf ("min = %2.f , max = %2.f , atleg = %2.f \n", o.min, o.max, Atlag (o));


    return 0;
}

