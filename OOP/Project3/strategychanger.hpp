//
//  strategychanger.hpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#ifndef strategychanger_hpp
#define strategychanger_hpp

#include "strategies.hpp"

class StrategyChanger : public LandStrategyVisitor {
private:
    int _water;
    
    ILandStrategy* result;
    
    Weather* weather;
    
    virtual void Accept (const Steppe&) override;
    virtual void Accept (const Meadow&) override;
    virtual void Accept (const Lake&) override;
    
public:
    StrategyChanger (int water) {
        _water = water;
    }
    
    ILandStrategy* GetNewStrategy (const ILandStrategy&, Weather& weather);   //  MILYEN TIPUS VOLT, HA VALTOZTATNI KELL, AKKOR KELL UJ

};

#endif /* strategychanger_hpp */
