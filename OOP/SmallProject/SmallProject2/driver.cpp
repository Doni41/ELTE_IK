//
//  driver.cpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include "driver.hpp"
#include "cash_register.hpp"
#include <iostream>

using namespace std;

int Driver::refuel(GasStation* p , int i , int l) {
    //  TANKOLASERT FIZETETT OSSZEG
    
    std::cout << "A " << _driver_plate << " rendszamu autos tankolni fog." << std::endl;
    
    std::cout << "Adja meg a tankolni kivant mennyiseget : ";
    std::cin >> l;
    std::cout << "A tankolni kivant mennyiseg : " << l << " liter." << std::endl;
    
    std::cout << "Adja meg, hogy melyik kutat valasztja : ";
    std::cin >> i;
    if (i >= 6) {
        throw std::runtime_error ("Nem letezo toltohyel! Maximalis ertek : 5" );
    }
    std::cout << "A tankolashoz a " << i << ". szamu toltohelyet valasztotta." << std::endl;
    
    Tank* tank = p -> getTank(i);
    
    tank -> fill (l);
    
    CashRegister* cashregister = p -> getCashRegister(0);
    
    return cashregister -> payment (i) ;
}
