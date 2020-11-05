//
//  Classes.hpp
//  HatodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 05. 15..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef Classes_h
#define Classes_h
#include "seqinfileenumerator.hpp"
#include "counting.hpp"
#include <iostream>
#include "maxsearch.hpp"

//  REKORD AZ ADATOK BEOLVASASAHOZ
struct Person {
    //  KERESZTNEV
    std::string _first_name;
    //  VEZETEKNEV
    std::string _last_name;
};


struct MostPopular {
    //  A LEGTOBBET ELOFORDULO NEV
    std::string _mostpopular_name;
    //
    int _sum;
};


std::istream& operator >> (std::istream& inp, Person &p) {
    inp >> p._last_name >> p._first_name;
    return inp;
}


//  EMBEREKET FELSOROLO OSZTALY
class PersonEnumerator : public Enumerator <MostPopular> {

private:
    //  EMBEREKET FAJLBOL FELSOROLO
    SeqInFileEnumerator <Person> _f;
    //  EMBEREKET TARJA SZAMON
    MostPopular _most;
    //  FELSOROLO VEGE
    bool _end;

public:
    //  KONSTRUKTOR
    PersonEnumerator (const std::string& _fileName): _f(_fileName) {}
    //  FIRST FGV
    void first () override
    {
        _f.first(); next();
    }
    //  NEXT FGV
    void next () override;
    //  CURRENT ELEMET ADJA VISSZA
    MostPopular current () const override
    {
        return _most;
        
    }
    //  MEGVIZSGALJA, HOGY A FELSOROLAS A VEGERE ERT-E
    bool end () const override
    {
        return _end;
        
    }
};


//  KERESZTNEVEKET MEGSZAMLALO OSZTALY
class NameCounter : public Counting <Person>{
private:
    //
    std::string _name;
public:
    //
    NameCounter (const std::string& name) : _name(name) {}
protected:
    //
    bool cond (const Person& e) const override
    {
        return e._first_name == _name;
    }
    //
    bool whileCond(const Person &e) const override
    {
        return cond(e);
    }
};


// LEGGYAKRABBAN ELOFORDULO NEVET KIVALASZTO OSZTALY
class PopularName : public MaxSearch <MostPopular, int> {
protected:
    int func (const MostPopular& e) const override {return e._sum ; }
};


    //  NEXT FGV KIDOLGOZASA
    void PersonEnumerator::next () {
        if ((_end = _f.end ())) {
            return;
        }
    
        _most._mostpopular_name = _f.current()._first_name;
        NameCounter pr (_f.current()._first_name);
        pr.addEnumerator (&_f);
        
        pr.run ();
        //  EGY SORT MAR FELDOLGOZTUNK, IGY AZ EREDMENYHEZ HOZZA ADTUNK EGYET
        _most._sum = pr.result() + 1;
        //  IDEIGLENES KIIRATAS
        std::cout << _most._sum << " : " << _most._mostpopular_name << std::endl;
    }
    
#endif /* Classes_h */
