//
//  trophy.hpp
//  NegyedikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 28..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef trophy_h
#define trophy_h
#include <string>

class Elephant;
class Rhino;
class Lion;

class AnimalVisitorBase {
    
public:
    //
    virtual void Accept (const Elephant&) {}
    //
    virtual void Accept (const Rhino&) {}
    //
    virtual void Accept (const Lion&) {}
};


//  TROFEA OSZTALYA
class Trophy {
private:
    //  ELEJTES HELYE
    std::string _place;
    //  ELEJTES IDEJE
    std::string _time;
    //  ELEJTETT ALLAT SULYA
    int _mass;
    
public:
    //  KONSTURKTOR
    Trophy (const std::string& place , const std::string& time , int mass)
        { _place = place ; _time = time ; _mass = mass ; }
    //  DESTRUKTOR
    virtual ~Trophy () {};
    //  GETTER AZ ELEJTES HELYEHEZ
    std::string getPlace () { return _place ; }
    //  GETTER AZ ELEJTES IDEJEHEZ
    std::string getTime () { return _time ; }
    //  GETTER A SULYHOZ
    int getMass () { return _mass ; }
    //  VIRTUALIS SEGED METODUS
    virtual void Visit (AnimalVisitorBase& visitor) const = 0;
};


#endif /* trophy_h */
