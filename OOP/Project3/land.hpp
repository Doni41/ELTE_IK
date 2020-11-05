//
//  land.hpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#ifndef land_hpp
#define land_hpp

#include <string>
#include <iostream>
#include "strategies.hpp"
#include "strategychanger.hpp"

class Weather;


//  FOLDTERULET OSOSZTALY
class Land {
private:
    
    std::string _name;  //  FOLDTERULET TULAJDONOSA
    ILandStrategy* _strategy;   //  STRATEGY-RE MUTATO POINTER
    std::string _type;  //  KIIRATASHOZ A TIPUS
    int _amountWater;   //  KEZDETI VIZMENNYISEG
    
    
public:
    //  KONSTRUKTOR
    Land (const std::string& name, ILandStrategy* strategy , std::string type , int amountWater)
    {
        _name = name;
        _strategy = strategy;
        _type = type;
        _amountWater = amountWater;
        
    }
    
    Land(); //  DESTRUKTOR
    std::string getName () { return _name; }    //  GETTER - TULAJDONOS
    int getAmountWater () { return _amountWater; }  //  GETTER - VIZMENNYISEG
    std::string getType (); //  GETTER - TIPUS
    void Change (Weather& weather);   //  CHANGE FUGGVENY
};

#endif /* land_hpp */
