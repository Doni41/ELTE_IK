//
//  cash_register.hpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef cash_register_hpp
#define cash_register_hpp

#include <stdio.h>
#include "tank.hpp"
#include <vector>


class CashRegister {
    
private:
    //  TOLTOHELY ADATTAG
    std::vector <Tank*> _tank;
    //  EGYSEGAR
    double _gasprice;
    
public:
    //  KONSTRUKTOR
    CashRegister ( std::vector <Tank>& tanks , double gasprice ) { for (Tank& t : tanks) { _tank.push_back (&t); } _gasprice = gasprice ; }
    //  FIZET ELJARAS
    int payment (int i) { return _tank [i] -> getDisplay() * _gasprice ; };
    
};

#endif /* cash_register_hpp */
