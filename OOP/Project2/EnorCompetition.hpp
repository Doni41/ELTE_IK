//
//  EnorCompetition.hpp
//  MasodikBeadando
//
//  Created by Hegyesi Ákos on 2020. 04. 13..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A FELADAT MEGOLDASA SORAN A A GYAKORLATOK, ILLETVE A MINTAFELADAT MEGOLDASA ADOTT KIINDULASI ALAPOT

#ifndef EnorCompetition_hpp
#define EnorCompetition_hpp

#include <fstream>

//  HORGASZ VERSENY OSZTALY MEGVALOSITASA EGYEDI FELSOROLOHOZ

//  ADATSTRUKTURA

struct Competition {
    //  HORGASZ AZONOSITO
    std::string _fisherman_id;
    //  VERSENY AZONOSITO
    std::string _competition_id;
    //  FOGOTT PONTYOK SULYA OSSZESEN
    double _carp_amount;
    //  FOGOTT PONTYOK SZAMLALOJA - OSZTASNAL CAST-OLVA LESZ DOUBLE-RA, HOGY AZ OSZTAS JO EREDMENYT ADJON
    int _carp_counter;
    //  FOGOTT-E PONTYOT VIZSGALATA - MASODIK FELADATHOZ SEGITSEG, HA A HAL AMI JON A SORBAN NEM PONTY, AKKOR AZ ERTEKE 1 LESZ
    int _have_nocarp;
};

//  A SORONKENT KAPOTT OSSZEGEKET SZUMMAZZA
struct Sum {
    //  SZUMMAZZA A SORONKENT KAPOTT FOGOTT PONTYOK SULYAT
    double _sum_amount;
    //  SZUMMAZZA A SORONKENT KAPOTT FOGOTT PONTYOK DARABSZAMAT
    int _sum_counter;
};

class CompetitionEnor {

//  A VERSENYEK OSZTALY PRIVAT ADATTAGJAI
private:
    //  ADATFOLYAM
    std::ifstream _inp;
    //  AKTUALIS ELEM
    Competition _curr;
    //  FAJL VEGE
    bool _competition_end;

//  A VERSENYEK OSZTALY PUBLIKUS ADATTAGJAI
public:
    //  HIBAKEZELES ENUM
    enum Error {WRONGLIFE , NOTPOSITIVE};
    //  KONSTRUKTOR
    CompetitionEnor (const std::string& _filename);
    //  FELSOROLO ELSO ELEME
    void first () { next () ; }
    //  FELSOROLO KOVETKEZO ELEME
    void next ();
    //  FAJL EPPEN VIZSGALT ELEMET ADJA VISSZA
    Competition current () const { return _curr ; }
    //  AZT VIZSGALJA, HOGY FAJL VEGE VAN-E
    bool end () { return _competition_end ; }
};

#endif /* EnorCompetition_hpp */
