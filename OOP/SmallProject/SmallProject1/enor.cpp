//
//  enor.cpp
//  MasodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 05..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include "enor.hpp"

using namespace std;

Enor::Enor (const string& _fileName) {
    _inp.open (_fileName.c_str());
    if (_inp.fail ()) {
        throw WRONGFILE;
    }
}

//  FELTETELEZZUK, HOGY EGY HOZZAVALO CSAK EGYSZER SZEREPEL EGY RECEPTBEN
void Enor::next () {
    //  HA NEM A FAJL VEGE KOVETKEZIK
    if (! (_end  = (abnorm == _sx))) {
        //  MEGSZAMLALAS TETELE AZ ADOTT NEVU ETELEK KOZOTT
        _curr._max_name = _dx.name;
        //  A HOZZAVALOK SZAMAT NULLAZOM
        _curr._max_ing = 0;
        for ( ; norm == _sx && _dx.name == _curr._max_name ; readFile ()) {
            //  HA BE TUDTAM OLVASNI, AKKOR A HOZZAVALOK SZAMAT MEGNOVELEM EGGYEL - AMENNYIBEN NEM EGYELŐ NULLÁVAL (NEM KELL > 0, MERT 0-NÁL KISEBB SZÁMOT ELVE NEM OLVASHATUNK BE)
            if (_dx.quantity != 0) {
                _curr._max_ing += 1;
            }
        }
    }
}

void Enor::readFile () {
    //  BEOLVASOM EGYMAS UTAN AZ ELEMEKET
    _inp >> _dx.name >> _dx.ingredient >> _dx.quantity >> _dx.unit;
    //  A HOZZAVALO MENNYISEGE CSAK TERMESZETES SZAM LEHET
    if (_dx.quantity < 0) {
        throw NOTANATURALNUMBER;
    }
    //  FAJL VEGE
    _sx = _inp.fail() ? abnorm : norm;
}






