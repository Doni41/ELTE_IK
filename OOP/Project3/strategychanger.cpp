//
//  strategychanger.cpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#include "strategychanger.hpp"

void StrategyChanger::Accept (const Steppe&) {
    result = new Meadow/*(*weather)*/;
}

void StrategyChanger::Accept (const Meadow&) {
    if (_water > 50) {
        result = new Lake/*(*weather)*/;
    }
    else if (_water < 16) {
        result = new Steppe/*(*weather)*/;
    }
}

void StrategyChanger::Accept (const Lake&) {
    result = new Meadow/*(*weather)*/;
}

ILandStrategy* StrategyChanger::GetNewStrategy (const ILandStrategy& strategy, Weather& _weather) {
    weather = &_weather;
    
    strategy.Visit(*this);
    
    return result;
}
