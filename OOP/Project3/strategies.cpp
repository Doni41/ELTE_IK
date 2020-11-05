//
//  strategies.cpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#include "strategies.hpp"

//  STEPPE OSZTALY METODUSAI
void Steppe::Change (const Weather& weather, int& amountWater) {
    if (weather.GetWeatherType() == sunny) {
        if (amountWater - 3 >= 0) {
            amountWater += -3;
        }
        else {
            amountWater = 0;
        }
        
    }
    else if (weather.GetWeatherType() == cloudy) {
        amountWater += 1;
    }
    else {
        amountWater += 5;
    }
}

bool Steppe::NeedToChange (int amountWater) {
        return amountWater > 15;
}

/*------------------------------------------------------------*/

//  MEADOW OSZTALY METODUSAI
void Meadow::Change (const Weather& weather, int& amountWater) {
    if (weather.GetWeatherType() == sunny) {
        amountWater += -6;
    }
    else if (weather.GetWeatherType() == cloudy) {
        amountWater += 2;
    }
    else {
        amountWater += 10;
    }
}

bool Meadow::NeedToChange (int amountWater) {
        return amountWater > 50 || amountWater < 16;
}

/*------------------------------------------------------------*/

//  LAKE OSZTALY METODUSAI
void Lake::Change (const Weather& weather, int& amountWater) {
    if (weather.GetWeatherType() == sunny) {
        amountWater += -10;
    }
    else if (weather.GetWeatherType() == cloudy) {
        amountWater += 3;
    }
    else {
        amountWater += 15;
    }
}

bool Lake::NeedToChange (int amountWater) {
        return amountWater < 51;
}

