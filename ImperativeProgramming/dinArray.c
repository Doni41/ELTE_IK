// DINAMIKUS TOMBOK ES STRUKTURAK HASZNALATA

// TARTSUK NYILVAN, MEKKORA A LEFOGLALT TERULET !
// MERET ES POINTER OSSZETARTOZO ADAT - STRUKTURA

// CALLOC - LEFOGLAL EGY TOMBOT, ES KITOLTI 0 BAJTOKKAL
// REALLOC - UJRAFOGLALJA, ATMERETEZI A PTR ALTAL MUTATOTT DINAMIKUS TOMBOT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Error 1
#define NoError 0

// dt STRUKTURA LETREHOZASAKOR MEG NEM LESZ NEKI TERULET ALLKALVA A MEMORIABAN
// STRUKTURABAN AKKOR MEG CSAK EGY POINTER ES EGY INT VAN
// FUGGVENY A FOGLALASRA, HASZNALATRA, ILLETVE FELSZABADITASRA
// EGYSZERUBB A STRUKTURAT ATADNI, MIVEL AZ TARTALMAZZA A POINTERT ES A MERETET IS
// CIM SZERINT ADJUK AT A STRUKTURAT

bool dintomb_foglal (DinTomb* dt, int meret) {
    dt -> meret = meret;
    // MEMORIA ALLOKALASA
    dt -> adat = (double*) malloc (meret * sizeof(double));
    // SIKERESSEG VIZSGALATA
    /*if (dt -> adat == NULL) {
        return false;
    }
    */
    return dt -> adat != NULL;
}

void dintomb_kiir (DinTomb const* dt) {
    for (int i = 0; i < dt -> meret; ++i) {
        printf("%f ", dt -> adat [i]);
        printf("\n");
    }
}

void dintomb_felszabadit (Dintomb* dt) {
    free (dt -> adat);
}

// ATMERETEZES LEPESEI :
// 1. LEFOGLALJUK AZ UJ MEMORIATERULETET
// 2. ATMASOLJUK AZ ADATOKAT AZ UJ HELYRE
// 3. FELSZABADITJUK A REGI TOMBOT - AZ ADATOK MAR MEGVANNAK AZ UJ HELYEN
// 4. ATALLITJUK A POINTERT AZ UJ TOMBRE


bool dintomb_atmeretez (DinTomb* dt, int ujmeret) {
    // 1.
    double* ujadat = (double*) malloc (ujmeret * sizeof(double));
    if (ujadat = NULL) {
        return false;
    }
    int min = ujmeter < meret ? ujmeret : meret;
    // 2.
    for (int i = 0; i < min; ++i) {
        // MASOLAS AZ UJ TOMBBE
        ujadat [i] = dt -> adat [i];
    }
    // 3.
    free (dt -> adat);
    // 4.
    dt -> adat = ujadat;
    dt -> meret = ujmeret;

    return true;
}

// MINDENHOL CIM SZERINTI PARAMETER ATADAS TORTENT, EZRT & CIMKEPZO OPERATORT KELL HASZNALNI A FGV HIVASOKNAL


int main () {

    // STRUKTURA DEFINIALASA
    typedef struct DinTomb {
    {
        double* adat;
        int meret;
    } DinTomb;

    DinTomb dt;
    // INICIALIZALAS
    dintomb_foglal(&dt, 100);

    // HASZNALAT
    dt.adat [34] = 19;
    dintomb_kiir (&dt);
    dintomb_atmeretez (&dt, 200);
    // FELSZABADITAS   
    dintomb_felszabadit (&dt);
}

