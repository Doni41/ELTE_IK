//
//  menu.cpp
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 14..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  MENU LETREHOZASA - MENU HEADER SEGITSEGEVEL + MENU FUNKCIOK IMPLEMENTALASA
//  GYAKORLATON ELKESZITETT MENU HASZNALATA


#include <iostream>
#include <sstream>
#include <fstream>
#include "menu.h"
#include "read.hpp"
//  DEFINIALJUK, HOGY HANY DB MENUPONTRA LESZ SZUKSEGUNK
#define MenuDb 10

using namespace std;

//  MEGVIZSGALJA, HOGY 0 ES MenuDb KOZOTTI ELEM KOZOTTI SZAMOT VALASZTOTTUNK-E
bool Check (int a) {
    return (a >= 0 && a <= MenuDb);
}

void Menu::Run() {

    int b;
    do {
        b = MenuPrint();
        switch (b) {
            case 1:
                integerRead ();
                integerPrint ();
                break;
            case 2 :
                integerAdd ();
                integerPrint ();
                break;

            case 3 :
                integerPop ();
                integerPrint ();
                break;

            case 4 :
                integerEmpty ();
                //integerPrint ();
                break;

            case 5 :
                integerErease ();
                //integerPrint ();
                break;

            case 6 :
                integerSize ();
                //integerPrint ();
                break;

            case 7 :
                integerMax ();
                //integerPrint ();
                break;

            case 8 :
                integerIsPart ();
                integerPrint ();
                break;

            case 9 :
                integerPrint ();
                break;

            case 10 :
                stressTest ();
                break;

            default:
                cout << "\nViszontlatasra! \n";
                break;
        }
    } while (b != 0);
}

//  MENUSOR KIIRASA
int Menu::MenuPrint () {

    int answer;
    //  MENU MEGJELENESE
    cout << "\n**************************************************\n";

    cout << "0.  Kilepes" << endl;
    cout << "1.  Halmaz feltoltese fajlbol" << endl;
    cout << "2.  Elem berakasa a halmazba" << endl;
    cout << "3.  Utoljara berakott elem kivetele a halmazbol" << endl;
    cout << "4.  Megvizsgalja, hogy ures-e a halmaz" << endl;
    cout << "5.  Torli a halmaz tartalmat" << endl;
    cout << "6.  Megadja, hogy hany darab elemet tartalmaz a halmaz" << endl;
    cout << "7.  Halmaz legnagyobb elemenek meghatarozasa" << endl;
    cout << "8.  Mergvizsgalja, hogy az adott elem mar eleme a halmaznak" << endl;
    cout << "9.  Kiirja a halmaz tartalmat" << endl;
    cout << "10. Terheleses teszt - Mennyi elemet tudunk a halmazba tenni" << endl;

    cout << "**************************************************\n";

    //  HIBAUZENET
    ostringstream _err;
    _err << "A szam 0, es " << MenuDb << " kozotti egesz szam legyen!" << endl;
    string errmsg = _err.str ();

    //  BEOLVASAS read.hpp SEGITSEGEVEL

    answer = read <int> ("\nValasztas : ", errmsg , Check);

    return answer;
}

//  EGESZ SZAMOKAT TARTALMAZO ELEM OLVASASA FAJLBOL
void Menu::integerRead () {

    bool error = false;
    try {
        cout << "\nAdja meg a fajl nevet, amibol a fajlokat kivanja beolvasni. Figyelem, a korabban a halmazba rakott elemeket torolje!\n";
        string _fileName;
        cin >> _fileName;
        ifstream _inp;

        Integers integer_file (0);
        integers.readIntegers (integer_file, _inp, _fileName);
        _inp.close();
    }
    catch (Integers::Exceptions err) {
        error = true;
        if (err == Integers::WRONGFILE) {
            cout << "\nRossz a megadott fajlnev, vagy hibas fajl!\n";
        }
        else if (err == Integers::NOTNATURALNUMBER) {
            cout << "\nA halmaz merete nem lehet 0-nal kisebb!\n";
        }
        else if (err == Integers::DUPLICATE) {
            cout << "\nA halmaz duplikatumokat tartalmaz, kerem ellenorizze a fajlt!\n";
        }
        else {
            cout << "\nIsmeretlen programhiba! Valoszinuleg ugyanazt az elemet tobbszor is megprobalta a halmazba rakni, kerem ellenorizze az inputfajlt!\n";
            cout << "\nA duplikalt elemek kozul az elsot beraktam a halmazba, amennyiben meg nem szerepelt benne!\n";
        }
    }
}

//  EGESZ SZAM HOZZAADASA A HALMAZHOZ
void Menu::integerAdd () {

    int _m;
    cout << "\nAdja meg azt az egesz szamot, amit a halmazba kivan tenni : ";
    cin >> _m;
    //  ELLENORIZZUK, HOGY SIKERULT-E A MUVELET
    bool error = false;
    try {
        integers.putIn(_m);
    }
    catch (Integers::Exceptions err)    {
        error = true;
        if (err == Integers::DUPLICATE) {
            cout << "\nDuplikatum! A halmazba tenni kivant egesz szam mar szerepel a halmazban!\n";
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
    if (!error) {
        cout << "\nA halmazba rakott elem : " << _m << endl;
    }
}

//  UTOLJARA A HALMAZHOZ ADOTT EGESZ SZAM KIVETELE A HALMAZBOL
void Menu::integerPop () {

    bool error = false;
    try {
        integers.popBack ();
    }
    catch (Integers::Exceptions err) {
        error = true;
        if (err == Integers::EMPTYSET) {
            cout << "\nA halmaz ures!\n";
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
}

//  KIIRJA, HOGY URES-E A HALMAZ
void Menu::integerEmpty () {

    int temp;
    temp = integers.isEmpty ();
    if (temp == 1) {
        cout << "\nA halmaz ures!\n";
    }
    else {
        cout << "\nA halmaz nem ures!\n";
    }
}

//  TORLI AZ ADOTT HALMAZ ELEMEIT
void Menu::integerErease () {

    bool error = true;
    try {
        integers.Erease ();
        cout << "\nA halmaz elemei torolve lettek, a halmaz ures!\n";
    }
    catch (Integers::Exceptions err) {
        error = true;
        if (err == Integers::EMPTYSET) {
            cout << "\nA halmaz ures, nem kellett elemeket torolni a halmazbol!" << endl;
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
}

//  KIIRJA A HALMAZ LEGNAGYOBB ELEMET
void Menu::integerMax () {

    bool error = false;
    try {
        integers.maxElement ();
        int temp;
        temp = integers.maxElement ();
        cout << "\nA halmaz maximalis eleme : " << temp << endl;
    }
    catch (Integers::Exceptions err) {
        error = true;
        if (err == Integers::EMPTYSET) {
            cout << "\nA halmaz ures, nincs maximalis eleme!" << endl;
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
}

//  KIIRJA A HALMAZ MERETET
void Menu::integerSize () {

    int temp;
    temp = integers.setSize ();
    cout << "\nA halmaz merete le lett kerve, erteke : " << temp << endl;
}

//  KIIRJA, HOGY AZ ADOTT EGESZ SZAM ELEME-E A HALMAZNAK
void Menu::integerIsPart () {
    bool error = false;
    try {
        cout << "\nKerem adja meg, hogy mely szamrol szeretne megtudni, hogy eleme-e a halmaznak : ";
        int _m;
        cin >> _m;
        int is_true;
        is_true = integers.binSearch(_m);
        if (is_true == 1)
        {
            cout << "\nAz adott egesz szam : " << _m << " eleme a halmaznak!" << endl;
        }
        else {
            cout << "\n Az adott egesz szam : " << _m << " NEM eleme a halmaznak!" << endl;
        }
    }
    catch (Integers::Exceptions err) {
        error = true;
        if (err == Integers::EMPTYSET) {
            cout << "\nA halmaz ures!" << endl;
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
}

//  KIIRJA A HALMAZ TARTALMAT
void Menu::integerPrint () {
    cout << integers;

}

//  STRESSZTESZ
void Menu::stressTest () {
    //const int size=1000000000;
    const int size=1000000;
    Integers integer (size);
    cout << "\nA halmaz pillanatnyi elemszamat kovetheti:\n";
    try{
        for (int i=1; i < size; ++i)
        {
            if((i % 1000) == 0) {
                cout << i << endl;
            }
            integers.putIn(i);
        }
    }catch(...)
    {
        cout << "\nElfogyott a szabad memoria!\n";
        cout << "\nA vector merete: " << integers.setSize () << endl;
    }
}


