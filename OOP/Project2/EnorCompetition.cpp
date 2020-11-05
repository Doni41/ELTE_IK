//
//  EnorCompetition.cpp
//  MasodikBeadando
//
//  Created by Hegyesi Ákos on 2020. 04. 13..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A FELADAT MEGOLDASA SORAN A A GYAKORLATOK, ILLETVE A MINTAFELADAT MEGOLDASA ADOTT KIINDULASI ALAPOT

#include "EnorCompetition.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//  COMPETITION OSZTALY ELJARASAINAK DEFINIALASA

//  KONSTRUKTOR - ADATFOLYAM MEGNYITASA UTAN BEOLVASSA AZ ADOTT FAJLT, HA NEM SIKERULT, HIBAT DOB
CompetitionEnor::CompetitionEnor (const std::string& _fileName) {
    _inp.open(_fileName.c_str());
    if (_inp.fail()) {
        throw WRONGLIFE;
    }
}

void CompetitionEnor::next () {
    // SEGED STRINGEK LETREHOZASA - SOR BEOLVASASA - getline ()
    std::string line;
    getline (_inp, line);
    
    if (!(_competition_end = (_inp.fail() || line == ""  ) ) ) {
        istringstream istr (line);
        //  HALASZ AZONOSITOT BEOLVASSUK
        istr >> _curr._fisherman_id;
        //  VERSENY AZONOSITOT BEOLVASSUK
        istr >> _curr._competition_id;
        //  TOVABBI SEGEDVALTOZOK LETREHOZASA
        //  HAL NEVE
        std::string _fishname;
        //  FOGOTT MENNYISEG SZAMA AZ ADOTT HALBOL
        double _fish_amount;
        //  NULLAZOM AZ OSSZSULY, ILLETVE A FOGOTT ALKALMAK SZAMAT
        _curr._carp_amount = 0;
        _curr._carp_counter = 0;
        _curr._have_nocarp = 0;
        
        Competition f;
        
        //  OSSZEGZES ES MEGSZAMLALAS PARHUZAMOSAN UGYAN AZON FELTETELLEL
        for ( istr >> _fishname >> _fish_amount ; !istr.fail() ; istr >> _fishname >> _fish_amount ) {
            if (_fish_amount >= 0) {
                if ( _fishname == "Ponty" && _fish_amount != 0) {
                    _curr._carp_amount = _curr._carp_amount + _fish_amount;
                    _curr._carp_counter += 1;
                }
                else if (_fishname == "Ponty" && _fish_amount == 0) {
                    //  HA NEM PONTY JON A SORBAN, AKKOR 1-RE ALLITJA A VALTOZO ERTEKET, EZ A MASODIK FELADATRESZNEL LESZ FONTOS
                    _curr._have_nocarp = 1;
                }
                else if (_fishname != "Ponty" && _fish_amount == 0) {
                    _curr._have_nocarp = 0;
                }
                else {
                    //  HA NEM PONTY JON A SORBAN, AKKOR 1-RE ALLITJA A VALTOZO ERTEKET, EZ A MASODIK FELADATRESZNEL LESZ FONTOS
                    _curr._have_nocarp = 1;
                }
            }
            else {
                throw NOTPOSITIVE;
            }
        }
    }
}



