//
//  hunter.hpp
//  NegyedikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 28..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef hunter_hpp
#define hunter_hpp

#include <string>
#include <vector>
#include "trophy.hpp"

class Hunter {
private:
    //  VADASZ NEVE
    std::string _name;
    //  VADASZ ELETKORA
    int _age;
    //  TROFEAK VEKTORA
    std::vector <const Trophy*> _trophies;
    
public:
    //  KONSTRUKTOR
    Hunter (std::string name , int age) { _name = name ; _age = age ; }
    //  DESTRUKTOR
    ~Hunter () { for (const Trophy* t : _trophies ) { delete t; } }
    //  GETTER A NEVEKRE
    std::string getName () { return _name ;}
    //  GETTER AZ ELETKORRA
    int getAge () { return _age ;}
    //  HIM OROSZLANOK OSSZEGZOJE
    int sumLion ();
    //  TROFEA HOZZAADASA A VEKTORHOZ
    void addTrophie (const Trophy* t) { _trophies.push_back(t); }

};

#endif /* hunter_hpp */
