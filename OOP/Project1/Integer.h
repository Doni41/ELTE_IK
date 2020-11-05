//
//  Integer.h
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 02..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef Integer_h
#define Integer_h

#include <iostream>
#include <vector>
#include <ostream>

//  INTEGER HALMAz OSZTALY IMPLEMENTALASA
class Integers {
    //  PRIVAT ADATTAGOK DEFINIALASA - VALTOZOK ES
private:
    //  EGESZ SZAMOKAT REPREZENTALO VEKTOR
    std::vector <int> _integers;
    //  A SOROZAT MAXIMUM ELEME
    int _max;

    //  ELDONTES- HOGY BENNE VAN-E MAR
    bool isPart (int& _m);

public:
    //  KONSTRUKTOROK DEFINIALASA

    //  M ITT EGY EGESZ SZAMOT JELENT, AMI A VEKTOR HOSSZAT ADJA MEG ( m >= 0) !!!
    Integers () {};
    Integers (int m);   //  UGYAN TEORETIKAILAG AZ EGESZ SZAMOK HALMAZA VEGTELEN NAGY, MEGIS ERDEMESNEK LATTAM LETREHOZNI EGY KONSTRUKTORT, AMI EGY ADOTT MERETU HALMAZT HOZ LETRE

    //  DESTRUKTOR
    ~Integers() {};

    //  SEGEDFUGGVENYEK

    //  INTEGEREK BEOLVASASA FAJLBOL - FOPROGRAMHOZ
    void readIntegers (Integers& integers, std::ifstream& _inp, std::string& _fileName);

    //  MAXKIVALASZTAS, HA KITOROLJUK A LEGNAGYOBB ELEMET
    int maxElement ();

    // ADOTT ELEM BETEVESE A HALMAZBA
    void putIn (int& _m);

    //  MEGNEZI, HOGY URES-E A VEKTOR
    bool isEmpty () const;

    //  HALMAZ TARTALMANAK TORLESE - REINICIALIZLAS
    void Erease ();

    //  HALMAZ MERETENEK VISSZAADASA
    int setSize ();

    //  HALMAZBA UTOLJARA BERAKOTT ELEM TORLESE
    void popBack ();

    //  ADOTT ELEM KERESESE A HALMAZBAN
    bool binSearch (int& _m);

    //  UNIT TESZTEKHEZ BEOLVASO FUGGVENY
    void readFile (Integers& integers, std::ifstream& _inp, std::string& _fileName);

    // KIVETELKEZELES
    enum Exceptions {EMPTYSET, EMPTYSTREAM, WRONGFILE, DUPLICATE, NOTNATURALNUMBER};

    //  KIIRO OPERATOR
    friend std::ostream& operator << (std::ostream& os, const Integers& integers);

    //  BEOLVASO OPERATOR
    //friend std::ifstream& operator >> (std::ifstream& _fileName, Integers& Integers);

    //  TESZTELESHEZ
    std::vector <int> getVector() const;

};

#endif /* Integer_h */
