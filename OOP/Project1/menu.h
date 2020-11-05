//
//  menu.h
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 14..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  MENURENDSZER HEADER FAJLJA
//  OSZTALY LETREHOZASA A BILLENTYUZETROL VEZERELHETO MENUHOZ

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Integer.h"

class Menu {
private:
    //
    Integers integers;
    //  MENUPONT - MENU KIIRASA
    int MenuPrint ();
    //  MENUPONT - FAJLBOL OLVASAS
    void integerRead ();
    //  MENUPONT - ELEM BERAKASA
    void integerAdd ();
    //  MENUPONT - HALAMZBA UTOLJARA BEKERULT ELEM TORLESE
    void integerPop ();
    //  MENUPONT - URES-E A HALMAZ
    void integerEmpty ();
    //  MENUPONT - HALMAZ ELEMEINEK TORLESE
    void integerErease ();
    //  MENUPONT - HALMAZ MERETENEK VISSZAADASA
    void integerSize ();
    //  MENUPONT - HALMAZ MAXIMALIS ELEMENEK VISSZAADASA
    void integerMax ();
    //  MENUPONT - ADOTT ELEM ELEME-E A HALMAZNAK
    void integerIsPart ();
    //  MENUPONT - HALMAZ ELEMEINEK KIIRASA
    void integerPrint ();
    //  MENUPONT - TERHELESES TESZT
    void stressTest ();

public:
    Menu () {};
    void Run ();
};


#endif // MENU_H_INCLUDED
