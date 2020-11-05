// STRUKTURAK HASZNALATANAK GYAKORLASA

// IDOPONTOK
// IRJUNK PROGRAMOT, AMELY EGY STRUKTURABAN IDOPONTOT TARTOL
// IRJUNK FGV-EKET EHHEZ

#include <stdio.h>

// IDOPONT TAROLASA EGY NAPON BELUL : ORA ÉS PERC

typedef struct Ido {
    int ora;
    int perc;
} Ido;

// KIIRJA A PARAMETERKENT KAPOTT IDOPONTOT ORA:PERC FORMABAN

void ido_kiir (Ido i) {
    printf ("%02d:%02d", i.ora, i.perc);
}

// HOZZAAD A MEGADOTT I IDOPONTHOZ P PERCET, ES VISSZATER AZ IGY KAPOTT IDOPONTTAL
// P-NEK POZITIVNAK KELL LENNIE

Ido ido_hozzaad (Ido i, int p) {
    int ejfeltol = i.ora * 60 + i.perc + p;
    Ido uj;
    uj.perc = ejfeltol % 60;
    uj.ora = ejfeltol / 60 % 24;
    return uj;
}

// KISZAMOLJA HANY PERC TELT EL I1-TOL I2-IG. A PARAMETEREK SORRENDJE A KIVONASNAL MEGSZOKOTT I2-I1
// AZZAL A FELTETELEZESSEL AD HELYES EREDMENYT, HOGY A KET IDOPONT EGY NAPON VAN

int ido_eltelt(Ido i2, Ido i1) {
    return i2.ora*60-i1.ora*60 + i2.perc-i1.perc;
}

// KIVON VALAHANY PERCET A MEGADOTT IDOPONTBOL, ES AZ IGY KELETKEZO UJ IDOPONTTAL TE VISSZA
// NEGATIV P-RE HELYTELENUL MUKODIK

Ido ido_kivon (Ido i, int p) { 
    Ido uj;
    uj.perc = i.perc - p;
    uj.ora = i.ora;
    while (uj.perc < 0) {
        uj.perc += 60;
        uj.ora -= 1;
    }
    while (uj.ora < 0) {
        uj.ora += 24;
    }
    return uj;
}

// MAIN FGV

int main () {
    Ido i1 = {11, 50};
    Ido i2 = {12, 10};
    Ido i3 = {3, 30};

// IDOPONTOK KIIRASA
    printf ("i1 = "); ido_kiir (i1); printf ("\n");
    printf ("i2 = "); ido_kiir (i2); printf ("\n");
    printf ("i3 = "); ido_kiir (i3); printf ("\n");

// HOZZAAD - KIVON
    printf ("i2 - i1 = %d\n", ido_eltelt(i1, i2));

    printf ("i1 + 195 = "); ido_kiir(ido_hozzaad(i1 , 195)); printf ("\n");
    printf ("i2 - 195 = "); ido_kiir(ido_kivon(i2 , 195)); printf ("\n");
    printf ("i3 - 240 = "); ido_kiir(ido_hozzaad(i3 , 240)); printf ("\n");

    return 0;
}