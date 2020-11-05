//
//  Classes.hpp
//  OtodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 05. 10..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef Classes_h
#define Classes_h
#include "arrayenumerator.hpp"
#include "enumerator.hpp"
#include "seqinfileenumerator.hpp"
#include "summation.hpp"
#include <vector>
#include <ostream>

//  ELOSZOR A K-VAL OSZTHATO SZAMOKAT KIVALOGATJUK EGY VEKTORBA
class VectorAssortment : public Summation <int, std::vector <int> > {
    
private:
    
    //  AZ OSZTO SZAM - HA NEM ADJUK MEG AZ ERTEKET, AKKOR 3--MAL EGYENLŐ
    int _k;


public:
    //  KONSTRUKTOROK
    VectorAssortment (std::vector<int>& x) : Summation<int, std::vector<int> >::Summation (x) {}
    
    VectorAssortment () : Summation<int , std::vector<int> > :: Summation () {}
    //  A MAIN.BEN KAPOTT K-T MEGKAPJA
    void getNumber (int& k) { _k = k; }
    //  0-S BEOLVASASHOZ EXCEPTION
    enum Errors {WRONGNUMBER};
    
protected:
    //  INT-EKET VESZ
    int func (const int &e) const override { return e; }
    //  AZ INPUTFAJL ADOTT ELEME OSZTHATO-E K-VAL
    bool cond (const int &e) const override { return e % _k == 0; }
};

class VectorAdd : public Summation <int, std::vector <int> > {
    
private:
    //  CSINALOK EGY VECTORT AZ OSZTALYNAK, AMI TARTALMAZZA ASSORTMENT OSZTALY VEKTORAT, ES HOZZAFUZI ANNAK PAROS ELEMEIT
    std::vector <int> _fullVector;
    
public:
    //  ELKEREM A VECTORASSORTMENT OSZTALYTOL AZ EREEDMENY VEKTORAT
    void getVector (std::vector <int>& x) { _fullVector = x; }
    //  VEKTOROKAT UNIOZOM
    //void vectorConcatenate (std::vector <int>& x) { x.push_back(e); }
    //  KONSTRUKTOR
    VectorAdd (std::vector <int>& y) : Summation <int, std::vector <int> >::Summation (y) {}
    //  KONSTRUKTOR
    VectorAdd () : Summation<int , std::vector<int> > :: Summation () {}
    
protected:
    
    int func (const int& e) const override { return e; }
    
    bool cond (const int& e) const override { return e % 2 == 0; }
};

class WriteVector : public Summation <int, std::ostream> {
public:
    WriteVector (std::ostream* o) : Summation <int, std::ostream> :: Summation (o) {}
protected:
    std::string func (const int& e) const override {
        std::ostringstream os;
        os << e << " ";
        return os.str();
    }
    
};


#endif /* Classes_h */
