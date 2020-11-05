//
//  EnorFisherman.hpp
//  MasodikBeadando
//
//  Created by Hegyesi Ákos on 2020. 04. 13..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A FELADAT MEGOLDASA SORAN A A GYAKORLATOK, ILLETVE A MINTAFELADAT MEGOLDASA ADOTT KIINDULASI ALAPOT

#ifndef EnorFisherman_hpp
#define EnorFisherman_hpp

#include <fstream>
#include "EnorCompetition.hpp"

//  HALASZ OSZTALY MEGVALOSITASA EGYEDI FELSOROLOHOZ - ELSO RESZFELADAT

struct Fisherman {
    //  HALASZ AZONOSITOJA
    std::string _id;
    //  CSAK PONTYOT FOGOTT
    bool _only_carp;
};

//  HALASZ OSZTALY MEGVALOSITASA

class FishermanEnor {
    
//  PRIVAT ADATTAGOK
private:
    //  ELSO RESZFELADATHOZ KESZITETT FELSOROLOHOZ KESZITETT OSZTALY FELHASZNALASA
    CompetitionEnor _tt;
    //  AKTUALIS ELEM
    Fisherman _curr;
    //  FAJL VEGENEK VIZSGALATA
    bool _end_fisherman;
    
//  PUBLIKUS ADATTAGOK LETREHOZASA
public:
    //  KONSTRUKTOR
    FishermanEnor (const std::string& _filename) : _tt(_filename) {};
    //  FELSOROLO ELSO ELEME
    void first () { _tt.first() ;  next () ; }
    //  FELSOROLO KOVETKEZO ELEME
    void next ();
    //  FAJL EPPEN VIZSGALT ELEMET ADJA VISSZA
    Fisherman current () const { return _curr ; }
    //  AZT VIZSGALJA, HOGY FAJL VEGE VAN-E
    bool end () { return _end_fisherman ; }
    
    
};


#endif /* EnorFisherman_hpp */
