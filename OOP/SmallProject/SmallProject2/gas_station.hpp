//
//  gas_station.hpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef gas_station_hpp
#define gas_station_hpp

#include <stdio.h>
#include <string>
#include "tank.hpp"
#include "cash_register.hpp"

//  BENZINKUT OSZTALYA

class GasStation {
    
private:
    //  BENZIN EGYSEGARA
    int _gas_price;
    //  TOLTOHELY FIELD-JE
    std::vector <Tank> _tanks; //  6 db
    //  PENZTAR FIELD-JE
    std::vector <CashRegister> _cash_registers; //  2   db
    
public:
    //  KONSTURKTOR
    GasStation (int gasprice) { _tanks.resize(6) ; _gas_price = gasprice; for (int i = 0 ; i < 2 ; ++i ) { _cash_registers.emplace_back(_tanks , _gas_price) ; } ; }
    //  GETTER id
    Tank* getTank (int i) { return &_tanks [i] ; }
    //  GETTER BENZIN ARA
    int getPrice () const { return _gas_price ; }
    //
    CashRegister* getCashRegister (int i) { return &_cash_registers [i] ; }
};

#endif /* gas_station_hpp */
