//
//  Integer.cpp
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 02..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include "Integer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//  ADATTAGOK LETREHOZASA

//  KONSTRUKTOR UNIT-TESZTEKHEZ, AHOL ESETLEGESEN ELÕRE LÉTREHOZOK 1 ELEMÛ HALMAZT 0 ÉRTÉKKEL
Integers::Integers (int m) : _integers(m, 0), _max(0) {
    if (m < 0) {
        throw NOTNATURALNUMBER;
    }
}
//Integers::Integers (int m) {_integers.resize(m + 1); Erease();}

//  SEGEDFUGGVENYEK

//  INTEGEREK BEOLVASASA FAJLBOL - FOPROGRAMHOZ
void Integers::readIntegers (Integers& integers, std::ifstream& _inp, std::string& _fileName) {
    _inp >> _fileName;
    _inp.open (_fileName.c_str());
    if (_inp.fail()) {
        throw WRONGFILE;
    }
    /*  HA OLYAN INPUTFAJLTBOL SZERETNENK VEOLVASNI, AHOL A HALMAZ MERETE IS MEG VAN ADVA, KI KELL KOMMENTEZNI AZ ALABBI RESZT
    int m;
    _inp >> m;
    if (m < 0) {
        throw Integers::NOTNATURALNUMBER;
    }
    Integers integer (m);
     */
    int e;
    while (_inp >> e) {
        putIn (e);
    }
}

//  ELDONTI, HOGY AZ ADOTT ELEM MAR BENNE VAN-E A HALMAZBAN
bool Integers::isPart (int& _m) {
    for (int i = 0; i < (int)_integers.size(); ++i)
        if (_m == _integers [i]) {
            return true;
        }
    return false;
}


//  MAXELEM KIVALASZTASA
int Integers::maxElement() {
    if (!isEmpty()) {
        int _maxInd = 0;
        _max = _integers [0];
        for (int i = 1; i < (int)_integers.size(); ++i) {
            if (_integers [i] > _max) {
                _max = _integers [i];
                _maxInd = i;
            }
        }
        return _max;
    }
    else {
        isEmpty();
        throw EMPTYSET;
        return _max = -1;
    }
}

// ADOTT ELEM BETEVESE A HALMAZBA
void Integers::putIn (int& _m) {
    //  ELDONTES, HOGY BENNE VAN-E MAR, HA MÁR SZEREPET THROW
    if (!isPart(_m)) {
        _integers.push_back(_m);
        maxElement();
    }
    else {
        throw DUPLICATE;
    }
}

//  MEGNEZI, HOGY URES-E A HALMAZ
bool Integers::isEmpty() const  {
       if (_integers.size() == 0) {
           return true;
       }
       else {
           return false;
       }
}

//  HALMAZ MERETENEK NULLARA ALLITASA
void Integers::Erease () {
    _integers.clear();
}

//  HALMAZ MERETENEK VISSZAADASA
int Integers::setSize () {
    return (int)_integers.size();
}

//  HALMAZBA UTOLJARA BERAKOTT ELEM TORLESE
void Integers::popBack () {
    if ((int)_integers.size() == 0) {
        throw EMPTYSET;
    }
    _integers.pop_back();
    if ((int)_integers.size() != 0) {
        maxElement();
    }
}

//  ADOTT ELEM KERESESE A HALMAZBAN
bool Integers::binSearch (int& _m) {
    if (!isEmpty()) {
        std::sort (_integers.begin(), _integers.end());
        /*  JAVITOTT BUBOREKOS RENDEZES, ESETLEGESSEN AZ std::sort() HELYETT
         for (int i = (int)_integers.sitze(); i > 0; --i) {
         bool voltcsere = false;
         for (int j = 0; j < i; ++j) {
                if (_integers [j] > _integers [j + 1]) {
                    int temp = _integers [j];
                    _integers [j] = _integers [j + 1];
                    _integers [j + 1] = temp;
                    voltcsere = true;
                }
         }
         if (!voltcsere) {
                break;
         }
         }
         */
        /*  BINARY SEARCH IMPLEMENTACIOJA, ESETLEGESEN AZ std::ninary_search() HELYETT
         int min = 0;
         int max = (int)_integers_size() - 1;
         int kozep = (min+max)/2;

         while (min < max && _integers [kozep] != mit)    {
         if (_integers [kozep < mit]) {
                min = kozep + 1;
         }
         else    {
                max = kozep - 1;
         }
         kozep = (min + max)/2;
         }
         if (_integers [kozep] == mit) {
            _m = kozep;
         }
         else
            _m = -1;
         */

        if (std::binary_search (_integers.begin(), _integers.end(), _m)) {
            //cout << "\nAz adott egesz szam : " << _m << " eleme a halmaznak!" << endl;
            return true;
        }
        else {
            //cout << "\n Az adott egesz szam : " << _m << " NEM eleme a halmaznak!" << endl;
            return false;
        }

    }
    else {
        throw EMPTYSET;
    }
}

//  UNIT TESZTEKHEZ BEOLVASO FUGGVENY - NEM DOB DUPLICATE EXCEPTION-T
void Integers::readFile (Integers& integers, std::ifstream& _inp, std::string& _fileName) {
    _inp >> _fileName;
    _inp.open (_fileName.c_str());
    if (_inp.fail()) {
        throw WRONGFILE;
    }
    int e;
    while (_inp >> e) {
        if (!isPart(e)) {
            _integers.push_back(e);
        }
    }
}

//  KIIRO OPERATOR
ostream& operator << (ostream & os, const class Integers& Integers)   {
    os << "A halmaz merete : " << Integers._integers.size() << endl;
    os << "A halmaz elemei : ";
     for (int i = 0; i < (int)Integers._integers.size(); ++i) {
         os << Integers._integers [i] << " ";
     }
    return os;
}

// BEOLVASAS FAJLBOL
//ifstream& operator >> (ifstream& _inp, class Integers& Integers) {
//    if (_inp.fail ()) {
//        throw Integers::WRONGFILE;
//    }
//    int e;
//    while (_inp >> e) {
//        Integers.putIn(e);
//    }
//    return _inp;
//}

//  TESZTELESHEZ
vector <int> Integers::getVector() const {
    vector <int> test;
    for (int i = 0; i < (int)_integers.size(); ++i) {
        test.push_back(_integers [i]);
    }
    return test;
}
