//
//  main.cpp
//  OtodikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 05. 09..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  Egy felhasználó által megadott intervallumból gyűjtsük ki egy vektorba a k-val osztható számokat (k-t is a felhasználó adja meg, de megadása ne legyen kötelező, ha nem adjuk meg, akkor k=3 az alapértelmezett érték), majd a vektor elemeit írjuk bele egy output fájlba, végül az output fájlhoz fűzzük hozzá a vektorban található páros számokat.  (Három egymás után fűzött ciklust kell megvalósítani a tételek segítségével.)

//  A FELADAT AZ ORAI FELADATOK FELHASZNALASAVAL, ILLETVE A GT LIB SEGITSEGEVEL KESZULT

#include <iostream>
#include "Classes.hpp"

//  MAIN FGV
int main() {

    try {
        //  MEGKERDEZI, HOGY SZERETNENK-E MI MEGADNI K ERTEKET
        std::string answer;
        std::cout << "Kerem adja meg, hogy kivanja-e megadni, hogy mely szammal valo oszthatosagot vizsgaljuk (i/n) : ";
        std::cin >> answer;
        
        //  K ERTEKENEK BEKERESE, HA i A VALASZ, K ERTEKENEK MEGFELELTETESE 3-MAL, HA n a valasz
        int k;
        if (answer == "i" ) {
            std::cout << "Kerem adja meg, hogy mely szammal valo oszhatosagot kivanja vizsgalni : ";
            std:: cin >> k;
            if (k == 0) {
                throw VectorAssortment::WRONGNUMBER;
            }
        }
        else {
            k = 3;
        }
        
        //  FAJL NEVENEK BEOLVASASA
        std::cout << "Adja meg a fajl nevet : ";
        std::string fname;
        std::cin >> fname;
        
        //  PELDANYOOSITAS
        SeqInFileEnumerator<int> enor(fname);
        VectorAssortment pr;
        //  ELJARASOK
        pr.getNumber(k);
        pr.addEnumerator(&enor);
        pr.run();
        std::vector<int> x=pr.result();

        //  CSAK A KOVETHETOSEG MIATT KESZULT KIIRATAS - 1
        std::cout << fname << " fajbol a " << k << " val oszthato szamok:\n";
        for(int e : x)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        
        //  PELDANYOSITAS 2 - VEKTORT DOLGOZZA FEL
        VectorAdd pr2;
        pr2.getVector(x);
        ArrayEnumerator <int> enor2 (&pr.result());
        
        pr2.addEnumerator (&enor2);
        pr2.run();
        std::vector <int> result = pr2.result();
        
        //  CSAK A KOVETHETOSEG MIATT KESZULT ELJARAS - 2
        std::cout << "\nA paros szamok a vektorbol:\n";
        for(int e : result)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        
        //  FAJLBA VALO KIIRATAS
        std::ofstream f ("output.txt");
        WriteVector pr3 (&f);
        //  ELSO VEKTOR EREDMENYE
        ArrayEnumerator <int> enor3 (&x);
        pr3.addEnumerator(&enor3);
        pr3.run();
        //  MASODIK VEKTOR EREDMENYE
        ArrayEnumerator <int> enor4 (&pr2.result());
        pr3.addEnumerator(&enor4);
        pr3.run();

    }
    catch (...) {
        std::cout << "\nHiba tortent a fajl megnyitasa kozben, esetleg 0-t probalt megadni, mint oszto!\n";
    }
        
    return 0;
}
