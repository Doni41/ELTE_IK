// STACK = VEREM HASZNALATA
// FAKTORIALIS FUGGVENY HASZNALATA
// STACK - IDE KERULNEK FUGGVENY HIVASKOR :PARAMETEREK, VISSZATERESI ADATAI, LOKALIS VALTOZOK
// UGY TELIK MEG, MINT EGY VEREM - 
// AMIT LEGUTOLJARA BETETTUNK, AZT LATJUK LEGFELUL + AZT TUDJUK KIVENNI LEGELOSZOR
// PARAMETEREKET A HIVO FUGGVENY HELYEZI IDE
// VISSZATERESI ERTEK HELYET IS A HIVO FUGGVENY FOGLALJA LE
// FUGGVENY FOGLAL HELYET A SAJAT LOKALIS VALTOZOINAK
// FUGGVENY SZABADITJA FEL EZEKET!!! (PARAMETEREK + VISSZATERESI ERTEKET + LOKALIS VALTOZOK)
// MASNEVEN AUTOMATIKUS KEZELESU VALTOZOK

// STACK FRAME = KERET
// MINDEN FGV HIVASKOR LETREJON EGY RESZ A VEREMBEN, AMI A HIVASHOZ TARTOZIK
// VISSZATERESKOR MEGSZUNIK A FUGGVENY MINDEN VALTOZOJAVAL
// HA EGY FUGGVENYBOL EGY MASIKAT IS MEGHIVUNK, AKKOR EGY AHHOZ TARTOZO KERET IS LETREJON A VEREMBEN - MINDIG LEGFELUL

// STACKBEN LEGALUL - MAIN FVG
// FELETTE : FV HIVAS - VISSZATERESI ERTEK + VISSZATERESI CIM + n
// LEGFELUL fakti() - SZORZAT + i


// FAKTORIALIS FUGGVENY REKURZIO NELKUL
#include <stdio.h>

int fakti(int n) {
    int szorzat = 1;
    for (int i = 2; i < n; ++i) {
        szorzat *= i;
    }
    return szorzat;
}

//int main() {
//   int n = fakti(10);
//    printf("%ld ", n);
//
//    return 0;
//}

// FUGGVENYHIVAS ELOTT : 
//  - HIVO A MAIN FGV BETESZI A PARAMETEREKET A STACK-BE
//  - HELYET CSINÁL A VISSZATERESI ERTEKNEK IS
//  - MEGHIVJA A FUGGVENYT, AMIT ALTAL BEKERUL A VEREM TETEJERE A VISSZATERES CIME 

// FAKTI MUKODESE . 
//  - LETREHOZZA A LOKALIS VALTOZOKAT A VEREMBEN
//  - PARAMETEREIT VEREMBEN TALALJA
//  - VISSZATERESI ERTEKET A VEREMBE TESZI, A MEGFELELO MEMORIATERULET FELULIRASAVAL
//  - AMIKOR VISSZATER, A HIVOHOZ UGRIK VISSZA - CIM A VEREMBEN

// A FUGGVENYHIVAS UTAN A HIVO FGV : 
//  - A VEREMBEN MEGTALALJA A VISSZATERESI ERTEKET
//  - KITORLI A VEREMBOL AZ ALTALA BETETT FGV PARAMETEREKET, AZOKRA MAR NINCS SZUKSEG

// FAKTORIALIS  REKURZIV FGV-VEL - MEGHIVJA SAJAT MAGAT

int fakt (int n) {
    if (n <= 1) {
        return n;
    }
    else {
        //REKURZIV HIVAS - ONMAGAT HIVJA A FGV
        return n * fakt(n - 1);
    }
}

int main () {
    int result = fakt (10);
    //EREDMENY KIIRATASA
    printf("3! = %d\n", result);

    return 0;
}

// LEALLAS FELTETELE = BAZISKRITERIUM
// MINDEN ESETBEN LENNIE KELL EGY BAZISKRITERIUMNAK
// MINDEN LEPESSEL KOZELEDNI KELL - PL.: FIBONACCI