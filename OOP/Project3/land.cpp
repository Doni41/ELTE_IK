//
//  land.cpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#include "land.hpp"

void Land::Change (Weather& weather) {
    _strategy -> Change(weather, _amountWater);
    
    if (_strategy->NeedToChange(_amountWater)) {
        StrategyChanger strategy(_amountWater);
        ILandStrategy* newStrategy = strategy.GetNewStrategy(*_strategy, weather);
        
        delete _strategy;
        _strategy = newStrategy;
    }
}

std::string Land::getType () {
    if (getAmountWater() <= 15) {
        _type = "puszta";
    }
    else if (getAmountWater() > 15 && getAmountWater() <= 50) {
        _type = "zold";
    }
    else if (getAmountWater() > 50) {
        _type = "tavas";
    }
    return _type;

}
