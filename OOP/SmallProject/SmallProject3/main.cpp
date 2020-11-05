//
//  main.cpp
//  NegyedikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 28..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include <iostream>
#include "hunter.hpp"
#include "animals.hpp"


int main(int argc, const char * argv[]) {

    //  PELDANYOSITAS
    Hunter hunter ("James" , 35);
    
    //  ELEFANTOK BEOLVASASASA
    std::cout << "Adja meg, hogy hany darab elefantot szeretne letrehozni: ";
    int n_elephant;
    std::cin >> n_elephant;
    if (n_elephant > 0) {
        std:: cout << "Adja meg az elefantok elejtesenek helyet, idejet, az elefantok sulyat, valamint bal es jobb oldali szarvuknak hosszat: " << std::endl;
        std::string place, time;
        int  mass, tuskleft, tuskright;
        for (int i = 0; i != n_elephant ; i++) {
            std::cin >> place >> time >> mass >> tuskleft >> tuskright;
            hunter.addTrophie(new Elephant (place, time , mass ,tuskleft, tuskright));
        }
    }
    
    //  ORRSZARRVUAK BEOLVASASA
    std::cout << "Adja meg, hogy hany darab orrszarvut szeretne letrehozni: ";
    int n_rhino;
    std::cin >> n_rhino;
    if (n_rhino > 0) {
        std:: cout << "Adja meg az orrszarvuk elejtesenek helyet, idejet, az orszarvuk sulyat, valamint az orrszarvanak sulyat: " << std::endl;
        std::string place_rhino, time_rhino;
        int  mass_rhino, horn_mass;
        for (int i = 0; i != n_rhino ; i++) {
            std::cin >> place_rhino >> time_rhino >> mass_rhino >> horn_mass;
            hunter.addTrophie(new Rhino (place_rhino, time_rhino , mass_rhino ,horn_mass));
        }
    }
    
    //  OROSZLANOK BEOLVASASA
    std::cout << "Adja meg, hogy hany darab oroszlant szeretne letrehozni: ";
    int n_lion;
    std::cin >> n_lion;
    if (n_lion > 0) {
        std:: cout << "Adja meg az oroszlanok elejtesenek helyet, idejet, az oroszlanok sulyat, valamint a nemuket (female/male): " << std::endl;
        std::string place_lion, time_lion, _gender;
        int  mass_lion = 0;
        for (int i = 0; i != n_lion ; i++) {
            std::cin >> place_lion >> time_lion >> mass_lion >> _gender;
            if (_gender == "male") {
                            hunter.addTrophie(new Lion (place_lion, time_lion , mass_lion , Lion::male));
            }
            else if (_gender == "female") {
                hunter.addTrophie(new Lion (place_lion, time_lion , mass_lion , Lion::female));
            }
        }
    }
    
    //  EGY EGESZ SZAM TIPUSU PARAMETER MEGKAPJA A HUNTER METORUSAT
    int sum = hunter.sumLion();
    
    //  KIIRATAS
    std::cout << "\nA vadaszatokon fogott himoroszlanok szama : " << sum << " db!\n";
    
    return 0;
}
