//
//  enor.hpp
//  MasodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 05..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  ENOR OSZTALY DEFINIALASA ELJARASOKKAL, ILLETVE A RECEPTEK REKORDJANAK DEFINIALASA
//  AZ OSZTALY MEGIRASAHOZ A GYAKORLATOKON VEGZETT FELADATOK, ILLETVE AZ ELOZO HAZI FELADAT NYUJTOTTAK KIINDULASI ALAPOT

#ifndef enor_hpp
#define enor_hpp

#include <string>
#include <fstream>

enum Status {abnorm, norm};

//  RECEPT STRUKTURAJA
struct Recipes {
    //  EGY RECEPT NEVE
    std::string name;
    //  RECEPT EGY HOZZAVALOJANAK NEVE
    std::string ingredient;
    //  ADOTT HOZZAVALO MENNYISEGE
    int quantity;
    //  ADOTT HOZZAVALO MERTEKEGYSEGE
    std::string unit;
};

//  A LEGTOBB HOZZAVALOT TARTALMAZO REKORD NEVE
struct MaxFood {
    //  A LEGTOBB HOZZAVALOT TARTALMAZO ETEL NEVE
    std::string _max_name;
    //  A LEGTOBB HOZZAVALOT TARTALMAZO ETEL HOZZAVALOINAK SZAMA
    int _max_ing;
};



//  OSZTALY DEFINIALASA
class Enor {
    
//  PRIVAT ADATTAGOK
private:
    //  ADATFOLYAM
    std::ifstream _inp;
    //  RECEPT STRUKTURAJA
    Recipes _dx;
    //  STATUSZ
    Status _sx;
    //
    MaxFood _curr;
    //  VEGE VALTOZO
    bool _end;
    //  FAJLBOL VALO BEOLVASAS FUGGVENYE
    void readFile ();
    
//  PUBLIKUS ADATTAGOK
public:
    enum Errors { WRONGFILE , NOTANATURALNUMBER };
    Enor (const std::string& _fileName);
    void first () { readFile (); next ();}
    void next ();
    MaxFood current () const { return _curr; }
    bool end () const { return _end; }
};
#endif /* enor_hpp */
