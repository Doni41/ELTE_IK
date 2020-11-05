// MEMORIAKEZELES ATTEKINTESE

// A HAROM MEMORIATERULET (STORAGE CLASS) : GLOBALIS - VEREM - KUPAC
// GLOBALIS VALTOZOK MEM.TER = DATA SEGMENT
// LOKALIS VALTOZOK MEM.TER = STACK SEGMENT
// DINAMIKUSAN FOGLALT MEM.TER = HEAP, FREE STORE

// HAROM MEMORIATERULET MERETE IS VALTOZIK
// GLOBALIS ADATTERULET - MINDIG UGYANANNYI ADAT VAN
// VEREM - MENNYISEGE FUGGVENYHIVASKOR NO, VISSZATERESKOR CSOKKEN
// KUPAC - LEFOGLALT-FELSZABADITOTT TERULETEK NAGYSAGATOL FUGG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Error 1
#define NoError 0

// GLOBALIS MEMORIA TERULET

// ITT VANNAK A GLOBALIS VALTOZOK
// ITT VANNAK A NEVTELEN STRING KONSTANSOK IS
// GLOBALIS VALTOZOK A PROGRAM LEFUTASA ALATT MINDVEGIG LETEZNEK
// FUGGVENYEK static KULCSSZOVAL JELZETT VALTOZOI IS OROKELETUEK
// FGV-EK static VALTOZOI LÁTHATÓSÁGBAN MINT A LOK.VALTOZOK, ELETTARTAMBAN, MINT A GLOB.VALTOZOK



int x = 7;
char sz [15] = "szöveg";
char* p;

// PELDA A VEREMRE : FGV A LOKALIS VALTOZOIVAL
void fv(void) {
    char sz [10] = "HELLO";
    char* p = "hello";
}

int main () {

    char* str [] = "szia, ez itt egy proba. Futtass le!";
    char* pch;

    pch = strtok(str, " ,.!");
    while (och != NULL) {
        printf ("%s\n", pch);
        pch = strtok(NULL, " ,.!");
    }

    p = sz;
    printf ("Hello World!\n");

    return NoError;
} 

// strtok() FGV EGY SZOVEGET BIZONYOS HATAROLO KARAKTEREK MENTEN FELDARABOL
// ELSO HIVASKOR MEGADJUK A FELDOLGOZANDO STRINGET, DE A KESOBBIEKBEN MAR NULL POINTERREL HIVJUK


// AUTOMATIKUS MEMORIAKEZELES = A VEREM (STACK)

// LEGTETEJEN JONNEK LETRE A LOKALIS VALTOZOK, ES SZUNNEK MEG A FGV VISSZATERESSEL
// FV FGV VISSZATER - A FGV VALTOZOI ELTUNNEK
// VEREMBEN LEVO ADATOK MENNYISEGE IGY FOLYAMATOSAN VALTOZIK
// CSAK A FGV ELETTARTAMA ALATT ELNEK A VALTOZOK - FGV UJRA HIVASAVAL ISMET LETREJONNEK ES INICIALIZALODNAK
// FV-BEN "hello" GLOBALIS VALTOZO, MIVEL char* p EGY NEVTELEN STRINGRE MUTAT
// FV-BEN "HELLO" VEREMBEN EGY LOKALIS VALTOZO - TOMB

// A KUPAC = HEAP

// INNEN FOGLALODIK LE A MEMORIATERULET, AMIT A malloc () TOL KAPUNK
// int* t és char* p LOKALIS VALTOZOI A FGV-NEK - VEREMBEN FOGNAK LETREJONNI
// strlen () FGV EGY ADOTT STRING HOSSZAT MUTATJA MEG NEKUNK
// sizeof () A TOMB MERETET MUTATJA MEG NEKUNK

/*
int main (void) {
    int* t;
    char* p;

    t = (int*) malloc(100 * sizeof(int));
    t [0] = 3;
    t [1] = 6;

    p = (char*) malloc (20 * sizeof(char));
    strcpy(p, "hello");
}
*/

// HIBALEHETOSEGEK !! 

// 1. STRING MERETE - STRLEN ÉS SIZEOF

// 2. ERVENYTELEN POINTEREK
//      A POINTEREK MAR MEGSZUNT VALTOZORA MUTATNAK
/*
int* p = (int*) malloc (100 * sizeof(int)); - HEAP-EN JON LETRE
p [2] = 12;
free (p);
printf("%d\n", p[2]); - A HIVATKOZOTT MEMORIA CIM MAR NEM LETEZIK
*/

//      MUTATO LOKALIS VALTOZORA
/*
    int* fv (void) {
        int i = 7;
        return &i; - A FGV EGY LOKALIS VALTOZO CIMET PROBALJA VISSZAADNI
        // A TOMB A VEREMBEN VAN, MINT LOKALIS VALTOZO, NEM LEHET VELE VISSZATERNI, HIVAS UTAN MEGSZUNIK
    }
    int* ptr = fv();
*/

// VISSZATERHETUNK DINAMIKUSAN FOGLALT TERULETTEL IS
// FGV FOGLAL DINAMUKIS TERULETET A HEAP-BEN, AMIT UTANA A HIVO FELSZABADIT
// ATVESSZUK A MEMORIA KEZELESET, DE A FELSZABADITASA A MI DOLGUNK LESZ!
