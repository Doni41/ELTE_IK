//  KESZITETTE : HEGYESI AKOS
//  OBJEKTUMELVU PROGRAMOZAS : ELSO HAZI FELADAT
//  GYAKORLATVEZETO : VESZPREMI ANNA
//  main.cpp
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 02..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  VALOSITSA MEG AZ EGESZ SZAMOKAT TARTALMAZO HALMAZ TIPUST!
//  ABRAZOLJA A HALMAZ ELEMEIT EGY SOROZATBAN!
//  IMPLEMENTALJA A SZOKAOS MUVELETEKET (ADOTT ELEM BETEVESE, KIVETELE, EGY ADOTT ELEM BENNE VAN.E A HALMAZBAN), VALAMINT A HALMAZ LEGNAGYOBB ELEMENEK KIVALASZTASAT
//  (EHHEZ CELSZERU A HALMAZT REPREZENTALO SOROZAT MELLETT KULON ELTAROLNI A LEGNAGYOB ELEMET, ES AZT KARBANTARTANI)
//  TOVABBA EGY HALMAZ KIIRAST!

//  KONZULTALVA : 2020.03.04

#include <iostream>
#include "menu.h"
#include "Integer.h"


using namespace std;

//  AZ ALABBI MODON LEHET A NORMAL MOD, VALALAMINT A UNIT TESZT MOD KOZOTT VALTANI
#define NORMAL_MODE
#ifdef NORMAL_MODE

int main () {
    Menu Menu;
    Menu.Run ();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Integer.h"

//  TESZTESETEK MEGVALOSITASA

TEST_CASE ("isEmpty ()" , "[Integers]") {

    //  URES HALMAZ (VECTOR) LETREHOZASA - CHECK
    Integers A;
    CHECK (A.isEmpty () == TRUE);
    //  EGY ELEMU HALMAZ LETREHOZASA - CHECK
    Integers B (1);
    CHECK (B.isEmpty () == FALSE);
    //  1 ELEMU HALMAZ ELEMENEK TORLESE - CHECK
    B.popBack ();
    CHECK (B.isEmpty () == TRUE);
    //  1 ELEMU HALMAZ LETREHOZASA, ES TELJES HALMAZ TORLESE - CHECK
    Integers C (1);
    C.Erease ();
    CHECK (C.isEmpty () == TRUE);
    //  URES HALMAZ LETREHOZASA, ES TELJES HALMAZ TOLESE - CHECK
    Integers D;
    D.Erease ();
    CHECK (D.isEmpty () == TRUE);
    //  10 ELEMU HALMAZ LETREHOZASA, ES TELJES HALMAZ TORLESE - CHECK
    Integers E (10);
    E.Erease ();
    CHECK (E.isEmpty () == TRUE);
    //  URES HALMAZ LETREHOZASA, EGY ELEM HOZZAADASA - CHECK
    Integers F (0);
    int _m = 1;
    F.putIn (_m);
    CHECK (F.isEmpty () == FALSE);
    // URES HALMAZ LETREHOZASA, EGY ELEM LETREHOZASA, TORLESE - CHECK
    Integers G (0);
    int _n = 2;
    G.putIn (_n);
    G.popBack ();
    CHECK (G.isEmpty () == TRUE);

}

TEST_CASE ("putIn ()", "[Integers]") {

    Integers A;
    int _m = 1; int _n = 2; int _o = 1; int _p = 256;   int _r = -1;    int _q = 0;

    {
        A.putIn (_m);
        CHECK (A.setSize () == 1);
        vector <int> test1 = A.getVector ();
        CHECK (test1 [0] == 1);
        //  AZ 1 MAR ELEME A HALMAZNAK, ÍGY HIBAT KELL DOBNIA
        CHECK_THROWS (A.putIn(_o));
    }
    //  UJABB ELEMET ADUNK A HALMAZHOZ
    {
        A.putIn (_n);
        vector <int> test1 = A.getVector ();
        CHECK (A.setSize () == 2);
        CHECK (test1 [1] == 2);
    }
    //  HOZZA ADJUK A MARADEK ELEMEKET IS A HALMAZHOZ, ILLETVE MEGPROBALUNK ISMET EGY DUPLIKATUMOT HOZZA ADNI
    {
        A.putIn (_p);   A.putIn (_r);   A.putIn (_q);
        CHECK_THROWS(A.putIn (_o));
        vector <int> test1 = A.getVector ();
        CHECK (A.setSize () == 5);
        CHECK (test1 [2] == 256);    CHECK (test1 [3] == -1); CHECK (test1 [4] == 0);
    }

    //  LETREHOZOK EGY 5 ELEMU HALMAZT, ES AHHOZ ADOK HOZZA ELEMEKET
    Integers B (1);

    {
        B.putIn (_p);
        //  HIBAT KELL DOBNI, MIVEL KONSTANS 0 ERTEKEKKEL TOLTI FEL A KONSTRUKTOR A HALMAZT
        CHECK_THROWS(B.putIn (_q));
        vector <int> test2 = B.getVector ();
        CHECK (test2 [1] == 256);
        CHECK (B.setSize () == 2);
    }
}

TEST_CASE ("constructor" , "[Integers]") {

    //  URES KONSTRUKTORRAL HOZOK LETRE EGY HALMAZT
    Integers A;
    int a = 0;
    {
        CHECK (A.setSize () == 0);
        vector <int> testA = A.getVector ();
        CHECK (A.isEmpty() == TRUE);
        CHECK_THROWS (A.maxElement ());
        CHECK_THROWS (A.popBack ());
        CHECK_THROWS (A.binSearch (a));
    }

    //  LETREHOZOK KONSTRUKTOR SEGITSEGEVEL EGY 0 ELEMU HALMAZT - MAJD HOZZAADOK ELEMEKET, ES A VALTOZAST NEZEM
    Integers B (0);
    int b = 1;  int c = 2;  int d = 12345678;   int e = 1; int f = -1234567;
    {
        CHECK (B.setSize () == 0);
        CHECK (B.isEmpty () == TRUE);
        CHECK_THROWS (A.maxElement ());
        CHECK_THROWS (A.popBack ());
        CHECK_THROWS (A.binSearch (a));

        //  B HALMAZHOZ ELEMEKET ADOK HOZZA, PROBALOK DUPLIKATUMOT IS HOZZAADNI MAJD, EXCEPTION-T VAROK
        B.putIn (b);    B.putIn (c);    B.putIn (d);    B.putIn (f);
        CHECK_THROWS (B.putIn (e));
        vector <int> testB = B.getVector ();
        CHECK (testB [0] == 1); CHECK (testB [1] == 2); CHECK (testB [2] == 12345678);  CHECK (testB [3] == -1234567);
        CHECK (B.setSize () == 4);
        CHECK (B.isEmpty () == FALSE);
        CHECK (B.maxElement () == 12345678);
    }

    //  FAJLBOL VALO BEOLVASAS UTAN
    {
        string _fileName = "proba_vectormerettel.txt";
        ifstream _inp (_fileName.c_str());
        if (_inp.fail()) {
            cout << "Hibas fajlnev, vagy hibas adatokat tartalmazo fajl!" << endl;
        }
        int m;
        _inp >> m;
        if (m < 0) {
            cout << "A halmaz merete csak termeszetes szam lehet!" << endl;
        }
        Integers C (m);
        C.Erease();
        int e;
        while (_inp >> e) {
            C.putIn(e);
        }
        _inp.close();

        CHECK (C.setSize () == 7);
        CHECK (C.isEmpty () == FALSE);
        CHECK (C.maxElement () == 7);
        //  MAX ELEMET KIVESZEM A HALMAZBOL
        C.popBack ();
        CHECK (C.setSize () == 6);
        CHECK (C.isEmpty () == FALSE);
        CHECK (C.maxElement () == 6);

    }

    //  MEGPROBALOK LETREHOZNI EGY NEGATIV SZAMU KONSTRUKTORT - EXCEPTION KEZELEST VAROK
    {
        CHECK_THROWS (Integers C (-1));
    }

    //  EXTREM MERETU HALMAZ LETREHOZASA - 1000  ELEM
    Integers Big (1000);
    {
        CHECK (Big.setSize () == 1000);
        CHECK (Big.isEmpty () == FALSE);
        //CHECK (Big.maxElement () == 0);
    }

    //  HIBAS FAJLNEV MEGADASAT KOVETOEN EXCEPTION DOBASA
    {
    string _fileName_rossz = "hibasfajlnev.txt";
    ifstream _inp2_rossz;
    Integers rossz (0);
    CHECK_THROWS (rossz.readFile(rossz, _inp2_rossz, _fileName_rossz));
    _inp2_rossz.close();
    }

    //  AZ ADOTT FAJL NEM LETEZIK, MEGIS ABBOL PROBALUNK MEG BEOLVASNI
    {
    string _fileName_nemletezik = "nemletezik.txt";
    ifstream _inp2_nemletezik;
    Integers nemletezik (0);
    CHECK_THROWS (nemletezik.readFile(nemletezik, _inp2_nemletezik, _fileName_nemletezik));
    _inp2_nemletezik.close();
    }

}

TEST_CASE ("maxElement ()" , "[Integers]") {
    //  KULONBOZO ELORE ELKESZITETT TESZTFAJLOK BEOLVASASA, ES MAXIMUMKIVALASZTASA

    //  7 KULONBOZO SZAM BEOLVASASA A HALMAZBA
    {
        string _fileName = "kulonbozo.txt";
        ifstream _inp (_fileName.c_str());
        if (_inp.fail()) {
            cout << "Hibas fajlnev, vagy hibas adatokat tartalmazo fajl!" << endl;
        }
        Integers kulonbozo (0);
        kulonbozo.Erease();
        int e;
        while (_inp >> e) {
            kulonbozo.putIn(e);
        }
        _inp.close();

        CHECK (kulonbozo.setSize () == 7);
        CHECK (kulonbozo.isEmpty () == FALSE);
        CHECK (kulonbozo.maxElement () == 14);
    }

    //  7 AZONOS SZAM BEOLVASASA, AMIBOL CSAK AZ ELSO FOG A HALMAZBA KERULNI, MERT MINDEN ELEM CSAK EGYSZER SZEREPELHET A HALMAZBAN
    {
        string _fileName2 = "egyforma.txt";
        ifstream _inp2;
        Integers egyforma (0);
        egyforma.readFile(egyforma, _inp2, _fileName2);
        _inp2.close();

        CHECK (egyforma.setSize () == 1);
        CHECK (egyforma.isEmpty () == FALSE);
        CHECK (egyforma.maxElement () == 1);
    }

    //  7 DB SZAM BEOLVASASA, A MAX ELEMET TORLOM TOBBSZOR IS, VALTOZAS FIGYELESE
    int keresett = 324;
    int keresett_2 = 987;

    {
        string _fileName3 = "tobbmax.txt";
        ifstream _inp3;
        Integers max_elements (0);
        max_elements.readFile (max_elements, _inp3, _fileName3);
        _inp3.close ();

        vector <int> max_copy = max_elements.getVector ();

        //  AZ UTOLSO ELEM KEZDETBEN A LEGNAGYOBB
        CHECK (max_elements.setSize () == 7);
        CHECK (max_elements.isEmpty () == FALSE);
        CHECK (max_elements.maxElement () == 987);
        CHECK (max_copy [0] == 123);    CHECK (max_copy [1] == 324);    CHECK (max_copy [2] == 225);    CHECK (max_copy [3] == 567);    CHECK (max_copy [4] == 432);    CHECK (max_copy [5] == 987);    CHECK (max_copy [6] == 234);

        //  A HALMAZ UTOLSO ELEMET KIVESZEM, TESZTEK UJRA FUTTATASA
        max_elements.popBack ();
        CHECK (max_elements.setSize () == 6);
        CHECK (max_elements.isEmpty () == FALSE);
        CHECK (max_elements.maxElement () == 987);
        CHECK (max_elements.binSearch (keresett) == TRUE);  CHECK (max_elements.binSearch (keresett_2) == TRUE);

        //  A HALMAZ UTOLSO ELEMET ISMET KIVESZEM, TESZTEK UJRA FUTTATASA - UJ MAX ERTEK
        max_elements.popBack ();
        CHECK (max_elements.setSize () == 5);
        CHECK (max_elements.isEmpty () == FALSE);
        CHECK (max_elements.maxElement () == 567);
        CHECK (max_elements.binSearch (keresett) == TRUE);  CHECK (max_elements.binSearch (keresett_2) == FALSE);
    }
}

#endif
