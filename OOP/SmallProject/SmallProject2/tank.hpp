//
//  tank.hpp
//  HarmadikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 19..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#ifndef tank_hpp
#define tank_hpp

#include <stdio.h>
#include <string>
#include <vector>


//  TOLTOHELY OSZTALYA
class Tank {
    
private:
    //  TOLTOHELY AZONOSITOJA - 1 ES 6 KOZOTT
    //int _tank_id;
    //  MEGMUTATJA, HOGY MENNYIT TANKOLTAK
    double _display;
    
public:
    //  GETTER, HOGY LATNI LEHESSEN, HOGY MENNYIT TANKOLTAK
    double getDisplay () const { return _display ; }
    //  SETTER - TANKOL
    void fill (double b ) { _display = b ; }

};

#endif /* tank_hpp */
