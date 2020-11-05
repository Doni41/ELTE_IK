//
//  driver.hpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef driver_hpp
#define driver_hpp

#include <stdio.h>
#include <string>
#include "gas_station.hpp"

//  AUTOS OSZTALYA
class Driver {
    
private:
    //  AUTOS NEVE
    std::string _driver_plate;
    //  AUTOS PENZE
    int _money;
    
public:
    //  KONSTRUKTOR
    Driver () { _driver_plate = "ABC123" ; _money = 20000 ; }
    //  TANKOLAS ELJARASA
    int refuel (GasStation* p , int i , int l);
    //  GETTER MONEY
    int getMoney () const { return _money ; }
};

#endif /* driver_hpp */
