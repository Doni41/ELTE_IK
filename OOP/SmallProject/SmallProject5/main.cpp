//
//  main.cpp
//  HatodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 05. 15..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

//  A FELADATHOZ A GT LIB-ET HASZNÁLTAM FEL, VALAMINT AZ ÓRAI GYAKORLATOK ANYAGÁT

#include <iostream>
#include "Classes.hpp"


int main() {
    
    try {
        //  FAJL BEKERESE
        std::cout << "Adja meg a fajl nevet : ";
        std::string _fileName;
        std::cin >> _fileName;
        //  PELDANYOSITAS
        PopularName pr;
        PersonEnumerator enor (_fileName);
        pr.addEnumerator (&enor);
        
        pr.run();
        //  EREDMENY KIIRATASA
        if (pr.opt() != 0) {
            std::cout << pr.optElem()._mostpopular_name << " a leggyakrabban elofodulo nev, " << pr.opt() <<  " alkalommal fordul elo!" << std::endl;
        }
        else {
            std::cout << "\nA fajl ures volt!\n";
        }
    }
    //  HIBAKEZELES
    catch (...) {
        std::cout << "\nProblema volt a fajl beolvasasa kozben!!\n";
    }
    
    
    return 0;
}
