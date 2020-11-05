//
//  weather.cpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#include "weather.hpp"

void Weather::IncreaseHumidity (int increment) {
    _humidity += increment;
}

void Weather::ChangeWeather (int random) {
    if(GetHumidity() > 70) {
        _type = rainy;
        _humidity = 30;
    }
    else if(GetHumidity() < 40) {
        _type = sunny;
    }
    else if (GetHumidity() >= 40 && GetHumidity() <= 70) {
        if ((GetHumidity() - 40 )*3.3 > random) {
            _type = rainy;
            _humidity = 30;
        }
        else {
            _type = cloudy;
        }
    }
}

void Weather::SetHumidity(int fromLands) {
    if (fromLands <= 15) {
        if (GetHumidity() + 3 <= 100) {
            _humidity += 3;
        }
        else {
            _humidity = 100;
        }
        
    }
    else if (fromLands > 15 && fromLands <= 50 ) {
        if (GetHumidity() + 7 <= 100) {
            _humidity += 7;
        }
        else {
            _humidity = 100;
        }
        
    }
    else {
        if (GetHumidity() + 10 <= 100) {
            _humidity += 10;
        }
        else {
            _humidity = 100;
        }
    }
}

std::string  Weather::GetPrintWeather () {
    if (GetWeatherType() == sunny) {
        _typePrint = "napos";
    }
    else if (GetWeatherType() == cloudy) {
        _typePrint = "felhos";
    }
    else if (GetWeatherType() == rainy) {
        _typePrint = "esos";
    }
        
    return _typePrint;
}
