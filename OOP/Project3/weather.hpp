//
//  weather.hpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#ifndef weather_hpp
#define weather_hpp

#include <string>


enum WeatherType {sunny , rainy , cloudy};  //  IDOJARAS TIPUSOK

//  WEATHER OSZTALY
class Weather {
private:
    int _humidity;  //  PARATARTALOM
    WeatherType _type;  //  IDOJARAS TIPUSA
    std::string _typePrint;  //  IDOJARAS TIPUSA KIIRATASHOZ MAGYARUL
    
public:
    Weather (int humidity, int random) {
        _humidity = humidity;
        ChangeWeather(random);
        
    }
    int GetHumidity () const { return _humidity; }    //  GETTER - PARATARTALMAT ADJA VISSZA
    WeatherType GetWeatherType () const { return _type; }   //  GETTER - IDOJARAS TIPUSA
    std::string  GetPrintWeather ();
    void IncreaseHumidity (int increment);  //  MEGNOVELI A PARATARTALOM ERTEKET
    void ChangeWeather (int random);
    void SetHumidity(int fromLands);
};

#endif /* weather_hpp */
