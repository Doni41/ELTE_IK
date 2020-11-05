//
//  main.cpp
//  MasodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 05..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  FELADAT : Egy szekvenciális inputfájl ételreceptek hozzávalóit tartalmazza. A fájl egy eleme egy recept nevéből (szóköz nélküli sztring), és annak egyik hozzávalójának anyagnevéből (szóköz nélküli sztring), mennyiségéből (természetes szám) és mennyiségi egységéből (szóköz nélküli sztring) áll. A fájl nem üres, és recept nevek szerint rendezett, így ugyanazon recept hozzávalói közvetlenül egymás után helyezkednek el.  Melyik ételrecepthez kell a legtöbb összetevő?

//  A MEGOLDAS AZ ORAI PROJEKT, ILLETVE AZ ELOZO HAZIFELADAT ALAPJAN KESZULT

//  A PROGRAM MEGADJA, HOGY MELYIK ETELHEZ KELL A LEGTOBB HOZZAVALO, HA TOBB MAXIMALIS ELEMU VAN, AKKOR AZ ELSOT ADJA MEG!
//  A PROGRAM SORAN FELTETELEZZUK, HOGY A RECEPTEKBEN MINDEN HOZZAVALO CSAK EGYSZER SZEREPEL, AHOGY AZ A RECEPTEKNEL LENNI SZOKOTT

#include <iostream>
#include "enor.hpp"


using namespace std;

ostream& operator << (ostream& o, const MaxFood& _max);

int main() {
    
    bool error = false;
    try {
        string _fileName;
        cout << "Kerem adja meg a szekvencialis inputfajl nevet : ";
        cin >> _fileName;
        
        //  LETREHOZOM AZ OBJEKTUMOKAT
        Enor _t (_fileName);
        MaxFood _max;
        
        //  KIVALASZTOM, HOGY MELYIK ETELHEZ KELL A LEGTOBB ALAPANYAG - MAXKERESES
        _max._max_name = _t.current ()._max_name;
        _max._max_ing = _t.current()._max_ing;
        
        for ( _t.first () ; !_t.end() ; _t.next() ) {
            if (_t.current()._max_ing > _max._max_ing) {
                _max._max_name = _t.current ()._max_name;
                _max._max_ing = _t.current()._max_ing;
            }
        }
        cout << _max << endl;
    }
    //  KIVETELKEZELES
    catch (Enor::Errors err) {
        error = true;
        if (err == Enor::WRONGFILE) {
            cout << "\nHibas fajl, vagy hibas fajlnev! Kerem ellenorizze a fajlt!\n";
        }
        else if ( err == Enor::NOTANATURALNUMBER) {
            cout << "\nA hozzavalo mertekenek termeszetes szamnak kell lennie, kerem ellenorizze a recepteket!\n";
        }
        else {
            cout << "\nIsmeretlen programhiba!\n";
        }
    }
        
    
    
    return 0;
}

//  KIIRO OPERATOR AZ EREDMENYHEZ
ostream& operator << (ostream& o, const MaxFood& _max) {
    o << _max._max_name << " etelhez kell a legtobb hozzavalo : " << _max._max_ing << " db hozzavalo !";
    
    return o;
}
