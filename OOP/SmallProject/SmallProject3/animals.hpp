//
//  animals.hpp
//  NegyedikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 28..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include "trophy.hpp"

#ifndef animals_h
#define animals_h





//  ELEFANT OSZTALYA
class Elephant : public Trophy {
private:
    //  BAL OLDALI SZARV HOSSZA
    int _tusk_left;
    //  JOBB OLDALI SZARV HOSSZA
    int _tusk_right;
    
public:
    //  ELEFANT KONSTRUKTOR
    Elephant (const std::string& place , const std::string& time , int mass , int tuskleft , int tuskright)
    : Trophy (place , time , mass)
    { _tusk_left = tuskleft ; _tusk_right = tuskright ; }
    //  VIRTUALIS FGV OVERRIDEHOZ
    virtual void Visit  (AnimalVisitorBase& visitor) const override { visitor.Accept(* this); }
    
    
};

//  ORRSZARVU OSZTALYA
class Rhino : public Trophy {
private:
    //  ORRSZARV SULYA
    int _horn_mass;
    
public:
    //  KONSTRUKTOR
    Rhino (const std::string& place , const std::string& time , int mass , int hornmass)
    : Trophy (place , time , mass)
    { _horn_mass = hornmass ; }
    //  VIRTUALIS FGV OVERRIDEHOZ
    virtual void Visit (AnimalVisitorBase& visitor) const override { visitor.Accept(* this); }
    
};

//  OROSZLAN OSZTALYA
class Lion : public Trophy {
public:
    //  ELEJTETT ALLAT NEME
    enum Gender {female , male};
    
private:

    //  OROSZLAN NEMENEK ENUM-JA
    Gender _gender;
    
public:
    //  OROSZLAN KONSTRUKTOR
    Lion (const std::string& place , const std::string& time , int mass , Gender gender)
    : Trophy (place , time , mass)
    { _gender = gender ; }
    //  ELDONTI, HOGY FIU-E AZ OROSZLAN
    bool isMale () const { return _gender == male; }
    //  VIRTUALIS FGV OVVERIDE-HOZ
    virtual void Visit (AnimalVisitorBase& visitor) const override { visitor.Accept(* this); }
};




#endif /* animals_h */
