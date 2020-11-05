//
//  strategies.hpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#ifndef strategies_hpp
#define strategies_hpp
#include "weather.hpp"

class Weather;
class Steppe;
class Meadow;
class Lake;

//  LATOGATO TERVEZESI MINTA
class LandStrategyVisitor {
public:
    virtual void Accept (const Steppe&) = 0;
    virtual void Accept (const Meadow&) = 0;
    virtual void Accept (const Lake&) = 0;
    
    virtual ~LandStrategyVisitor() {}
    
};

//  STRATEGIA TERVMINTA
class ILandStrategy {
public:
    virtual ~ILandStrategy() {}
    virtual void Change (const Weather& weather, int& amountWater) = 0;
    virtual void Visit (LandStrategyVisitor&) const = 0;
    virtual bool NeedToChange (int amountWater) = 0;
};


//  PUSZTA
class Steppe : public ILandStrategy {
public:
    //Steppe (Weather& weather) { weather.IncreaseHumidity (3); } //  A PARATARTALMAT MEGNOVELI 3-MAL
    Steppe () {}  //  URES KONSTRUKTOR
    virtual void Change (const Weather& weather, int& amountWater) override;    //  AZ IDOJARAS ALAPJAN FOGJA MEGVALTOZTATNI A VIZMENNYISEGET
    //
    virtual void Visit (LandStrategyVisitor& visitor) const override {
        visitor.Accept(*this);
    }
    virtual bool NeedToChange (int amountWater) override;   //  MEGVIZSGALJA, HOGY A VIZMENNYISEG ALAPJAN SZUKSEGES-E A TIPUSAT MEGVALTOZTATNI
    
};

//  ZOLD
class Meadow : public ILandStrategy {
public:
    //Meadow (Weather& weather) { weather.IncreaseHumidity(7); }  //  A PARATARTALMAT MEGNOVELI 7-TEL
    Meadow () {}  //  URES KONSTRUKTOR
    virtual void Change (const Weather& weather, int& amountWater) override;
    //
    virtual void Visit (LandStrategyVisitor& visitor) const override {
        visitor.Accept(*this);
    }
    virtual bool NeedToChange (int amountWater) override;   //  MEGVIZSGALJA, HOGY A VIZMENNYISEG ALAPJAN SZUKSEGES-E A TIPUSAT MEGVALTOZTATNI
};


//  TAVAS
class Lake : public ILandStrategy {
public:
    //Lake (Weather& weather) { weather.IncreaseHumidity(10); }   //  A PARATARTALMAT MEGNOVELI 10-ZEL
    Lake () {}
    virtual  void Change (const Weather& weather, int& amountWater) override;
    //
    virtual void Visit (LandStrategyVisitor& visitor) const override {
        visitor.Accept(*this);
    }
    virtual bool NeedToChange (int amountWater) override;   //  MEGVIZSGALJA, HOGY A VIZMENNYISEG ALAPJAN SZUKSEGES-E A TIPUSAT MEGVALTOZTATNI
};

#endif /* strategies_hpp */
