//
//  main.cpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include <iostream>
#include "driver.hpp"
#include "gas_station.hpp"



int main(int argc, const char * argv[]) {

    try {
        Driver a ;
        
        int gasprice;
        
        std::cout << "Kerem adja meg, hogy mennyi jelenleg a benzin egysegara : ";
        std::cin >> gasprice;
        
        GasStation p (gasprice);
        
        int szamla = a.refuel( &p, 3, 50);
        
        std::cout << "A tankolt osszeg : " << szamla << std::endl;
    }
    catch (const std::exception& err) {
        std::cout << "Hiba tortent : " << err.what () << std::endl;
    }
    
    return 0;
}
