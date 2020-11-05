//
//  read.hpp
//  ElsoHazi
//
//  Created by Hegyesi Ákos on 2020. 03. 14..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  GT ALTALI READ.HPP BEOLVASAS BILLENTYUZETROL

//  CEL - EGY Item TIPUSU ADAT BEOLVASASA BILLENTYUZETROL
//      - ELLENORZI, HOGY AZ ERVENYES FUNKCIONAK MEGFELELO ADATOT OLVASOTT-E, HA AZ ADAT NEM MEGFELELO, MEG EGYSZER MEGPROBALJA BEOLVASNI

#pragma once

#include <iostream>
#include <string>

template <typename Item>
Item read (const std::string& msg, const std::string& err, bool valid (Item)) {
    Item n;
    bool wrong;
    //  BEOLVASAS
    do {
        std::cout << msg;
        std:: cin >> n;
        //  HA NEM SIKERULT A BEOLVASAS, A KEPERNYO TORLESE
        if ((wrong = std::cin.fail())) {
            std::cin.clear();
        }

        std::string tmp = "";
        getline (std::cin , tmp);
        wrong = wrong || tmp.size() != 0 || !valid(n);

        if (wrong) {
            std::cout << err << std::endl;
        }
    } while (wrong);
    return n;
}

