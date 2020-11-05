//
//  main.cpp
//  HarmadikNagyBeadandoFeladat
//
//  Created by Hegyesi Ákos on 2020. 06. 04..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A JOBB OLVASHATOSAG MIATT A KOMMENTEK INKABB MELLE KERULTEK

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "land.hpp"
#include "strategychanger.hpp"
#include "strategies.hpp"
#include "weather.hpp"


//  BEOLVASAS FUGGVENYE
void ReadFile (std::ifstream& _f, std::string& _fileName, int& _number_of_lands, std::string& _temp_name, char& _temp_type, int& _init_water, int& _init_humidity, std::vector <Land*>& _lands) {
        
    //std::vector <Land*> _init_lands;
    std::string temp;

    _f.open (_fileName);
    if (_f.fail()) {
        //throw Land::WRONGFILE;
    }
    
    _f >> _number_of_lands;
    
    _lands.resize(_number_of_lands);
    
    for (int i = 0; i < (int)_lands.size(); ++i) {
        _f >> _temp_name >> _temp_type >> _init_water;
        
        switch (_temp_type) {
            case 'p':
                _lands [i] = new Land (_temp_name, new Steppe(), "puszta" , _init_water);
                
                break;
                
            case 'z':
                _lands [i] = new Land (_temp_name, new Meadow(), "zold" , _init_water);
            break;
                
            case 't':
                _lands [i] = new Land (_temp_name, new Lake(), "tavas" , _init_water);
            break;
        }
    }
    
    _f >> _init_humidity;
}

//  KIIRATAS FUGGVENYE
void PrintLands (std::vector <Land*>& _lands, Weather& _weather) {
    for (int i = 0; i < _lands.size(); ++i) {
        std::cout << "Nev : " << _lands[i]->getName() << " , Tipus : "<< _lands[i]->getType()  << " , Terulet : " << _lands[i]->getAmountWater() << std::endl;
        
    }
    std::cout << "A paratartalom : " << _weather.GetHumidity() << std::endl;
    std::cout << "Az idojaras tipusa : " << _weather.GetPrintWeather() << std::endl;
    std::cout << std::endl;
}

//  EGYMAST KOVETO CIKLUSOK FUGGVENYE
void Cycle (Weather& _weather, std::vector<Land*>& _lands) {
    std::cout << "A kiidnulasi adatok : " << std::endl;
    PrintLands(_lands, _weather);
    for ( int i = 0; i < 10; ++i) {
        _weather.ChangeWeather(rand() % 101);
        for (int j = 0; j < (int)_lands.size(); ++j) {
            _lands[j]->Change(_weather);
            _weather.SetHumidity(_lands[j]->getAmountWater());
        }
        PrintLands(_lands, _weather);
    }
}

//  EGYMAST KOVETO CIKLUSOK FUGGVENYE - UNIT TESTELESHEZ, KIRATAS NELKUL
void CycleUnitTests (Weather& _weather, std::vector<Land*>& _lands, int z, int random) {
    for (int i = 0; i < z; ++i) {
        _weather.ChangeWeather(random);
        for (int j = 0; j < (int)_lands.size(); ++j) {
            _lands[j]->Change(_weather);
            _weather.SetHumidity(_lands[j]->getAmountWater());
        }
    }
}

//  MAXIMUM KIVALASZTAS FUGGVENYE
Land* MaxWateredLand (std::vector <Land*>& lands) {
    int max = -1;
    Land* maxLand;
    
    for (int i = 0; i < (int)lands.size(); ++i) {
        if (lands[i] -> getAmountWater() > max) {
            max = lands [i] -> getAmountWater();
            maxLand = lands [i];
        }
    }
    
    return maxLand;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

//  MAIN FUGGVENY
int main(int argc, const char * argv[]) {

    //srand(0); //  MINDIG UGYAN AZOKAT A SZAMOKAT ADJA
    try {
        
        //  SEGEDVALTOZOK
        int _number_of_lands;
        std::string _temp_name;
        char _temp_type;
        int _init_water;
        int _init_humidity;
        
        int random = rand() % 101;  //  RANDOM SZAM LETREHOZASA
        
        std::string _fileName;  //  FAJL NEVE A BEOLVASASHOZ
        std::ifstream _f;    //  FSTREAM A BEOLVASASHOZ
        
        std::cout << "Kerem adja meg a fajl nevet : ";
        std::cin >> _fileName;
        
        std::vector <Land*> _lands; //  PELDANYOSITAS
        ReadFile(_f, _fileName, _number_of_lands, _temp_name, _temp_type, _init_water, _init_humidity, _lands);
        
        Weather _weather(_init_humidity, random);   //  PELDANYOSITAS
        
        
        Cycle(_weather, _lands);    //  A KORFORGAST SZIMULALU CIKLUS
        
        Land* max = MaxWateredLand(_lands); //  MAXIMUM KIVALASZTAS FUGGVENYE
        
        std::cout << "A legvizesebb foldterulet tulajdonosa : " << max->getName() << " , a tarolt viz mennyisege : " << max->getAmountWater() << std::endl;
        
        
    }
    catch (...) {
        std::cout << "Hibas a megadott fajl, vagy rossz fajlnevet adott meg!" << std::endl;
    }
    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//  ALGORITMUS KIPROBALASA EGY TESZTESETTE
TEST_CASE ("A tesztfajl egy elemet tartalmaz, az algoritmus tesztelese egy kor alatt" , "inp5.txt") {
    
    //  SEGEDVALTOZOK
    int number_of_lands_1;
    std::string temp_name_1;
    char temp_type_1;
    int init_water_1;
    int init_humidity_1;
    int random_1 = 20;  //  A RANDOM SZAMOT KEZZEL ADOM MEG EBBEN AZ ESETBEN
    std::string fileName_1 = "inp5.txt";  //  FAJL NEVE A BEOLVASASHOZ
    std::ifstream f_1;    //  FSTREAM A BEOLVASASHOZ
    
    std::vector <Land*> lands_1; //  PELDANYOSITAS
    ReadFile(f_1, fileName_1, number_of_lands_1, temp_name_1, temp_type_1, init_water_1, init_humidity_1, lands_1);
    Weather weather_1(init_humidity_1, random_1);   //  PELDANYOSITAS
    
    CHECK (lands_1[0]->getAmountWater() == 16); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getName() == "Bean"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getType() == "zold"); //  BEOLVASAS ELLENORZESE
    
    //  EREDMENYEK EGY CIKLUS UTÁN - 1.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    Land* max = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max->getName() == "Bean");
    CHECK (max->getType() == "puszta"); //  A VIZMENNYISEGE 15 ALA CSOKKENT, IGY ZOLD-BOL PUSZTA LETT
    CHECK (max->getAmountWater() == 10); //  AZ EREDETI TERULET ZOLD VOLT, AMINEK A TERULETE NAPOS IDO HATASARA 6-TAL CSOKKENT
    CHECK (weather_1.GetHumidity() == 23);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 2.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_2 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK KET KOR ELTELTEVEL
    
    CHECK (max_2->getName() == "Bean");
    CHECK (max_2->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_2->getAmountWater() == 7); //  A TERULET 3-MAL CSOKKENT
    CHECK (weather_1.GetHumidity() == 26);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 3.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_3 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HAROM KOR ELTELTEVEL
    
    CHECK (max_3->getName() == "Bean");
    CHECK (max_3->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_3->getAmountWater() == 4); //  A TERULET 3-MAL CSOKKENT
    CHECK (weather_1.GetHumidity() == 29);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 4.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_4 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK NEGY KOR ELTELTEVEL
    
    CHECK (max_4->getName() == "Bean");
    CHECK (max_4->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_4->getAmountWater() == 1); //  A TERULET 3-MAL CSOKKENT
    CHECK (weather_1.GetHumidity() == 32);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 5.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_5 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK OT KOR ELTELTEVEL
    
    CHECK (max_5->getName() == "Bean");
    CHECK (max_5->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_5->getAmountWater() == 0); //  A TERULET ERTEKE NEM LEHET NEGATIV SZAM, IGY 0 LESZ
    CHECK (weather_1.GetHumidity() == 35);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 6.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_6 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HAT KOR ELTELTEVEL
    
    CHECK (max_6->getName() == "Bean");
    CHECK (max_6->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_6->getAmountWater() == 0); //  A TERULET ERTEKE NEM LEHET NEGATIV, IGY 0 MARAD
    CHECK (weather_1.GetHumidity() == 38);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 7.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_7 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HET KOR ELTELTEVEL
    
    CHECK (max_7->getName() == "Bean");
    CHECK (max_7->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_7->getAmountWater() == 0); //  A TERULET ERTEKE NEM LEHET NEGATIV, IGY 0 MARAD
    CHECK (weather_1.GetHumidity() == 41);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == sunny);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 8.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_8 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK NYOLC KOR ELTELTEVEL
    
    CHECK (max_8->getName() == "Bean");
    CHECK (max_8->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_8->getAmountWater() == 1); //  A TERULET 1 LETT, MERT FELHOS LETT AZ IDO
    CHECK (weather_1.GetHumidity() == 44);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == cloudy);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 9.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_9 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK KILENC KOR ELTELTEVEL
    
    CHECK (max_9->getName() == "Bean");
    CHECK (max_9->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_9->getAmountWater() ==2); //  A TERULET 1-GYEL NOTT, A FELHOS IDO IMATT
    CHECK (weather_1.GetHumidity() == 47);  //  A PUSZTA A PARATARTALOM ERTEKET 3-MAL NOVELI
    CHECK (weather_1.GetWeatherType() == cloudy);
    
    //  EREDMENYEK EGY KOVETKEZO CIKLUS UTAN - 10.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //
    Land* max_10 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK TIZ KOR ELTELTEVEL
    
    CHECK (max_10->getName() == "Bean");
    CHECK (max_10->getType() == "puszta"); //  PUSZTA MARADT
    CHECK (max_10->getAmountWater() == 7); //  A TERULET 5TEL NOTT, MIVEL A (PARATARTALOM-40)*3,3 > 20 IGAZ LETT, IGY ESOS LETT AZ IDO, ES A PARATARTALOM 30-RA CSOKKENT
    CHECK (weather_1.GetHumidity() == 33);  //  AZ ESOS IDO UTAN 30-RA CSOKKENT A PARATARTALOM, AMIT A PUSZTA 3-MAL MEGNOVELT
    CHECK (weather_1.GetWeatherType() == rainy);
}


//  A TESZTESETEK KOZUL MINDEGYIK FOLDTERULETNEK EGYENLO A VIZMENNYISEGE
TEST_CASE ("A tesztfajl negy elemet tartalmaz, egyenlo vizmennyiseggel" , "inp4.txt") {
    
    //  SEGEDVALTOZOK
    int number_of_lands_1;
    std::string temp_name_1;
    char temp_type_1;
    int init_water_1;
    int init_humidity_1;
    int random_1 = 20;  //  A RANDOM SZAMOT KEZZEL ADOM MEG EBBEN AZ ESETBEN
    std::string fileName_1 = "inp4.txt";  //  FAJL NEVE A BEOLVASASHOZ
    std::ifstream f_1;    //  FSTREAM A BEOLVASASHOZ
    
    std::vector <Land*> lands_1; //  PELDANYOSITAS
    ReadFile(f_1, fileName_1, number_of_lands_1, temp_name_1, temp_type_1, init_water_1, init_humidity_1, lands_1);
    Weather weather_1(init_humidity_1, random_1);   //  PELDANYOSITAS
    
    CHECK (lands_1[0]->getAmountWater() == 100); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getName() == "Bean"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[1]->getAmountWater() == 100); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[1]->getName() == "Green"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[1]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[2]->getAmountWater() == 100); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[2]->getName() == "Dean"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[2]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[3]->getAmountWater() == 100); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[3]->getName() == "Teen"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[3]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    //  MAXIMUM ERTEKNEL MINDIG AZ ELSO TERULET LESZ A MAXIMUM, MERT MINDEGYIKK TERULET VIZMENNYISEGE EGYENLO
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 1.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    Land* max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MERT A VIZMENNYISEG NAGYOBB, MINT 70
    CHECK (max_1->getAmountWater() == 90); //  MIVEL AZ IDOJARAS KEZDETBEN NAPOS VOLT, IGY 10-ZEL CSOKKENT AZ ERTEKE
    CHECK (weather_1.GetHumidity() == 50);  //  MINDEGYIK TAVAS TERULET 10-ZEL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == sunny);    //  A BEOLVASAS UTAN ELOSZOR NAPOS IDO VOLT, AMI A KOVETKEZO KORBEN MEG FOG VALTOZNI
    
    //  EREDMENYEK AZ OTODIK CIKLUS UTAN - 5.CIKLUS
    CycleUnitTests(weather_1, lands_1, 4, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK OT KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  PUSZTA MARADT
    CHECK (max_1->getAmountWater() == 150); //  MIVEL A (PARATARTALOM-40)*3.3 ERTEK MOSTANTOL MINDIG NAGYOBB LESZ, MINT A 20-AS ERTEK, IGY AZ IDOJARAS MINDIG ESOS LESZ, EZ KORONKENT +15 A VIZMENNYISEGHEZ
    CHECK (weather_1.GetHumidity() == 70);  //  MINDEGYIK TAVAS TERULET 10-ZEL NOVELI A PARATARTALMAT
    CHECK (weather_1.GetWeatherType() == rainy);    //  ESOS IDO UTAN A PARATARTALOM 30-RA CSOKKEN, AMIT MINDEGYIK TERULET UTANA 10-ZEL NOVEL
    
    //  EREDMENYEK AZ OTODIK CIKLUS UTAN - 10.CIKLUS
    CycleUnitTests(weather_1, lands_1, 5, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK TIZ KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  PUSZTA MARADT
    CHECK (max_1->getAmountWater() == 225); //  MIVEL A (PARATARTALOM-40)*3.3 ERTEK MOSTANTOL MINDIG NAGYOBB LESZ, MINT A 20-AS ERTEK, IGY AZ IDOJARAS MINDIG ESOS LESZ, EZ KORONKENT +15 A VIZMENNYISEGHEZ
    CHECK (weather_1.GetHumidity() == 70);  //  MINDEGYIK TAVAS TERULET 10-ZEL NOVELI A PARATARTALMAT
    CHECK (weather_1.GetWeatherType() == rainy);    //  ESOS IDO UTAN A PARATARTALOM 30-RA CSOKKEN, AMIT MINDEGYIK TERULET UTANA 10-ZEL NOVEL
}

//  EGY TESZTESET, TAVAS TERULET, MAGAS KEZDETI PARATARTALOMMAL, MAGAS RADNOM ERTEKKEL
TEST_CASE ("A tesztfajl egy elemet tartalmaz, tavas terulet, magas kezdeti paratartalom" , "inp3.txt") {
    
    //  SEGEDVALTOZOK
    int number_of_lands_1;
    std::string temp_name_1;
    char temp_type_1;
    int init_water_1;
    int init_humidity_1;
    int random_1 = 56;  //  A RANDOM SZAMOT KEZZEL ADOM MEG EBBEN AZ ESETBEN
    std::string fileName_1 = "inp3.txt";  //  FAJL NEVE A BEOLVASASHOZ
    std::ifstream f_1;    //  FSTREAM A BEOLVASASHOZ
    
    std::vector <Land*> lands_1; //  PELDANYOSITAS
    ReadFile(f_1, fileName_1, number_of_lands_1, temp_name_1, temp_type_1, init_water_1, init_humidity_1, lands_1);
    Weather weather_1(init_humidity_1, random_1);   //  PELDANYOSITAS
    
    CHECK (lands_1[0]->getAmountWater() == 86); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getName() == "High"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 1.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    Land* max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "High");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MERT A VIZMENNYISEG NAGYOBB, MINT 70
    CHECK (max_1->getAmountWater() == 76); //  MIVEL AZ IDOJARAS KEZDETBEN NAPOS VOLT, IGY 10-ZEL CSOKKENT AZ ERTEKE
    CHECK (weather_1.GetHumidity() == 40);  //  A TAVAS TERULET 10-ZEL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == sunny);    //  A BEOLVASAS UTAN ELOSZOR NAPOS IDO VOLT, AMI A KOVETKEZO KORBEN MEG FOG VALTOZNI
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 2.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK KET KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "High");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MERT A VIZMENNYISEG NAGYOBB, MINT 70
    CHECK (max_1->getAmountWater() == 79); //  A PARATARTALOM 40 VOLT, ES A RANDOM ERTEK NAGYOBB VOLT, MINT A (PARATARTALOM-40)*3,3, IGY AZ IDOJARAS FELHOS, AMI TAVAS ESETEBEN 3-MAL NOVELI AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 50);  //  A TAVAS TERULET 10-ZEL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == cloudy);    //  AZ IDO FELHOS LETT, MIVEL A RANDOM SZAM NAGYOBB VOLT

    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 5.CIKLUS
    CycleUnitTests(weather_1, lands_1, 3, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK OT KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "High");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MERT A VIZMENNYISEG NAGYOBB, MINT 70
    CHECK (max_1->getAmountWater() == 100); //  A VIZMENNYISEG OSSZESEN 21-GYEL NOTT, MIVEL A 3. CIKLUSBAN A (PARATARTALOM-40)*3,3 NAGYOBB LETT, MINT A RANDOM SZAM ERTEKE, IGY AZ IDO ESOS LETT, AMI 15-TEL NOVELI AZ ERTEKET, EZT KOVETTE KET FELHOS IDO, IGY MEGKAOTUK A 21-ET
    CHECK (weather_1.GetHumidity() == 50);  //  A TAVAS TERULET 10-ZEL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == cloudy);    //  AZ IDO FELHOS LETT, MIVEL A RANDOM SZAM NAGYOBB VOLT
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 10.CIKLUS
    CycleUnitTests(weather_1, lands_1, 5, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK TIZ KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "High");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MERT A VIZMENNYISEG NAGYOBB, MINT 70
    CHECK (max_1->getAmountWater() == 139); //  A PARATARTALOM 30, ILLETVE 60 KOZOTT VALTOZOTT, IGY A KET ESOS IDO MIATT AZ ERTEKE 2*15, ILLETVE A 3 FELHOS IDO MIATT 3*3-MAL NOVEKEDETT
    CHECK (weather_1.GetHumidity() == 40);  //  A TAVAS TERULET 10-ZEL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == rainy);    //  AZ IDO ESOS VOLT, INNEN VALTOZOTT MEG 10-ZEL A PARATARTALOM ERTEKE, MERT AZ ESOT KOVETOEN LEESETT 30-RA
}

//  EGY TESZTESET, PUSZTA TERULET 0 VIZMENNYISEGGEL, PARATARTALOM 0
TEST_CASE ("A tesztfajl egy elemet tartalmaz, puszta terulet, 0 kezdeti paratartalom" , "inp2.txt") {
    
    //  SEGEDVALTOZOK
    int number_of_lands_1;
    std::string temp_name_1;
    char temp_type_1;
    int init_water_1;
    int init_humidity_1;
    int random_1 = 56;  //  A RANDOM SZAMOT KEZZEL ADOM MEG EBBEN AZ ESETBEN
    std::string fileName_1 = "inp2.txt";  //  FAJL NEVE A BEOLVASASHOZ
    std::ifstream f_1;    //  FSTREAM A BEOLVASASHOZ
    
    std::vector <Land*> lands_1; //  PELDANYOSITAS
    ReadFile(f_1, fileName_1, number_of_lands_1, temp_name_1, temp_type_1, init_water_1, init_humidity_1, lands_1);
    Weather weather_1(init_humidity_1, random_1);   //  PELDANYOSITAS
    
    CHECK (lands_1[0]->getAmountWater() == 0); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getName() == "SubZero"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getType() == "puszta"); //  BEOLVASAS ELLENORZESE
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 1.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    Land* max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "SubZero");
    CHECK (max_1->getType() == "puszta"); //  PUSZTA, MERT A VIZMENNYISEG 0
    CHECK (max_1->getAmountWater() == 0); //  MIVEL AZ IDOJARAS KEZDETBEN NAPOS VOLT, 3-MAL CSOKKENNE AZ ERTEKE, DE NEM LEHET NEGATIV SZAM
    CHECK (weather_1.GetHumidity() == 3);  //  A PUSZTA 3-MAL NOVELI A PARATARTALOM ERTEKET
    CHECK (weather_1.GetWeatherType() == sunny);    //  A BEOLVASAS UTAN ELOSZOR NAPOS IDO VOLT, AMI A 10. CIKLUS VEGEIG MARADNI FOG
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 10.CIKLUS
    CycleUnitTests(weather_1, lands_1, 9, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "SubZero");
    CHECK (max_1->getType() == "puszta"); //  PUSZTA, MERT A VIZMENNYISEG 0
    CHECK (max_1->getAmountWater() == 0); //  MIVEL AZ IDOJARAS NAPOS VOLT, 3-MAL CSOKKENNE AZ ERTEKE, DE NEM LEHET NEGATIV SZAM
    CHECK (weather_1.GetHumidity() == 30);  //  A PUSZTA 3-MAL NOVELI A PARATARTALOM ERTEKET, TIZ KORON KERESZTUL IGY 30 LESZ AZ ERTEKE
    CHECK (weather_1.GetWeatherType() == sunny);    //  A BEOLVASAS UTAN ELOSZOR NAPOS IDO VOLT, AMI A 10. CIKLUS VEGEIG MARADNI FOG
    
}

//  EGY TESZTESET, PUSZTA TERULET 0 VIZMENNYISEGGEL, PARATARTALOM 0
TEST_CASE ("Minta bemenet lejátszása" , "inp1.txt") {
        
    //  SEGEDVALTOZOK
    int number_of_lands_1;
    std::string temp_name_1;
    char temp_type_1;
    int init_water_1;
    int init_humidity_1;
    int random_1 = 58;  //  A RANDOM SZAMOT KEZZEL ADOM MEG EBBEN AZ ESETBEN
    std::string fileName_1 = "inp1.txt";  //  FAJL NEVE A BEOLVASASHOZ
    std::ifstream f_1;    //  FSTREAM A BEOLVASASHOZ
        
    std::vector <Land*> lands_1; //  PELDANYOSITAS
    ReadFile(f_1, fileName_1, number_of_lands_1, temp_name_1, temp_type_1, init_water_1, init_humidity_1, lands_1);
    Weather weather_1(init_humidity_1, random_1);   //  PELDANYOSITAS
        
    CHECK (lands_1[0]->getAmountWater() == 86); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getName() == "Bean"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[0]->getType() == "tavas"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[1]->getAmountWater() == 26); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[1]->getName() == "Green"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[1]->getType() == "zold"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[2]->getAmountWater() == 12); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[2]->getName() == "Dean"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[2]->getType() == "puszta"); //  BEOLVASAS ELLENORZESE
    
    CHECK (lands_1[3]->getAmountWater() == 35); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[3]->getName() == "Teen"); //  BEOLVASAS ELLENORZESE
    CHECK (lands_1[3]->getType() == "zold"); //  BEOLVASAS ELLENORZESE
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 1.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    Land* max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK EGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 76); //  MIVEL AZ IDOJARAS KEZDETBEN NAPOS VOLT, 10-ZEL CSOKKENNE AZ ERTEKE
    CHECK (weather_1.GetHumidity() == 57);  //  A KEZDETBEN LECSOKKENT 30-AS ERTEKET A PUSZTA 3-MAL, A KET ZOLD TERULET 7-TEL, A TAVAS PEDIG 10-ZEL NOVELTE
    CHECK (weather_1.GetWeatherType() == sunny);    //  A BEOLVASAS UTAN ELOSZOR NAPOS IDO VOLT, MIVEL A MAGAS KEZDTI PARATARTALOM MIATT LECSOKKENT MAR 30-RA

    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 2.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK KET KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 79); //  AZ IDOJARAS FELHOS LETT, IGY 3-MAL NOTT AZ ERTEKE
    CHECK (weather_1.GetHumidity() == 84);  //  A PUSZTA 3-MAL, A KET ZOLD TERULET 7-TEL, A TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT
    CHECK (weather_1.GetWeatherType() == cloudy);    //  A (PARATARTALOM-40)*3.3 ERTEK KISEBB VOLT, MINT A RANDOM SZAM 58-AS ERTEKE, IGY FELHOS LETT AZ IDO
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 3.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HAROM KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 94); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOTT AZ ERTEKE
    CHECK (weather_1.GetHumidity() == 57);  //  A PUSZTA 3-MAL, A KET ZOLD TERULET 7-TEL, A TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A PARTARTALOM MEGHALADTA A 70-ES ERTEKET, IGY AZ IDOJARAS ESOS LETT
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 4.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK NEGY KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 97); //  AZ IDOJARAS FELHOS LETT, IGY 3-MAL NOTT AZ ERTEKE
    CHECK (lands_1[2]->getName() == "Dean");    //  A KEZDETBEN PUSZTA TERULET ATVALTOZOTT ZOLD TERULETTE, MIVEL 12-3+1+5+1 = 16
    CHECK (lands_1[2]->getType() == "zold");
    CHECK (lands_1[2]->getAmountWater() == 16); //  12-3+1+5+1 = 16
    CHECK (weather_1.GetHumidity() == 88);  //  A PUSZTA-BOL ZOLD LETT, IGY A HAROM ZOLD TERULET 7-TEL, A TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == cloudy);    //  A (PARATARTALOM-40)*3.3 ERTEK KISEBB VOLT, MINT A RANDOM SZAM 58-AS ERTEKE, IGY FELHOS LETT AZ IDO
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 5.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK OT KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (lands_1[3]->getName() == "Teen");    //  A KEZDETBEN PUSZTA TERULET ATVALTOZOTT ZOLD TERULETTE, MIVEL 12-3+1+5+1 = 16
    CHECK (lands_1[3]->getType() == "tavas");   //  AZ IDOJARAS ZOLD-BOL TAVAS LETT, MIVEL A VIZMENNYISEGE MEGHALADTA AZ 50-ET
    CHECK (lands_1[3]->getAmountWater() == 53); //  35-6+2+10+2+10 = 53
    CHECK (max_1->getAmountWater() == 112); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 64);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A KET ZOLD TERULET 7-TEL, A KET TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A PARATARTALOM NAGYOBB VOLT, MINT 70
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 6.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HAT KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (lands_1[1]->getName() == "Green");    //  A KEZDETBEN PUSZTA TERULET ATVALTOZOTT ZOLD TERULETTE, MIVEL 12-3+1+5+1 = 16
    CHECK (lands_1[1]->getType() == "tavas");   //  AZ IDOJARAS ZOLD-BOL TAVAS LETT, MIVEL A VIZMENNYISEGE MEGHALADTA AZ 50-ET
    CHECK (lands_1[1]->getAmountWater() == 54); //  26-6+2+10+2+10+10 = 54
    CHECK (max_1->getAmountWater() == 127); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 67);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A EGY ZOLD TERULET 7-TEL, A HAROM TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A (PARATARTALOM-40)*3.3 NAGYOBB VOLT, MINT 70
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 7.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK HET KOR ELTELTEVEL
    
    random_1 = 90;  // A RANDOM SZAMOT MEGNOVELEM, HOGY NE MINDIG ESOS LEGYEN AZ IDOJARAS
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 142); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 67);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A EGY ZOLD TERULET 7-TEL, A HAROM TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A (PARATARTALOM-40)*3.3 NAGYOBB VOLT, MINT 70
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 8.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK NYOLC KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 145); //  AZ IDOJARAS FELHOS LETT, IGY 3-MAL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 100);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A EGY ZOLD TERULET 7-TEL, A HAROM TAVAS PEDIG 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == cloudy);    //  A (PARATARTALOM-40)*3.3 KISEBB VOLT, MINT 90
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 9.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK KILENC KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (lands_1[2]->getName() == "Dean");    //  A KEZDETBEN PUSZTA TERULET ATVALTOZOTT ZOLD TERULETTE, MIVEL 12-3+1+5+1 = 16
    CHECK (lands_1[2]->getType() == "tavas");   //  AZ IDOJARAS ZOLD-BOL TAVAS LETT, MIVEL A VIZMENNYISEGE MEGHALADTA AZ 50-ET
    CHECK (lands_1[2]->getAmountWater() == 58); //  12-3+1+5+1 = 16     16++10+10+10+2+10=58
    CHECK (max_1->getAmountWater() == 160); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 70);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A NEGY TAVAS 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A PARATARTALOM 100 VOLT
    
    //  EREDMENYEK AZ ELSO CIKLUS UTAN - 10.CIKLUS
    CycleUnitTests(weather_1, lands_1, 1, random_1);    //  ELSO KORBEN CSAK EGY KORRE NEZZUK MEG AZ ALGORITMUST
    max_1 = MaxWateredLand(lands_1);    //  MAXIMUM ERTEK TIZ KOR ELTELTEVEL
    
    CHECK (max_1->getName() == "Bean");
    CHECK (max_1->getType() == "tavas"); //  TAVAS, MIVEL A VIZMENNYISEG 70 FOLOTT VAN
    CHECK (max_1->getAmountWater() == 175); //  AZ IDOJARAS ESOS LETT, IGY 15-TEL NOVELTE AZ ERTEKET
    CHECK (weather_1.GetHumidity() == 70);  //  AZ EGYIK ZOLD-BOL TAVAS LETT, IGY A NEGY TAVAS 10-ZEL NOVELI A PARATARTALMAT, AMI 30-RA LECSOKKENT
    CHECK (weather_1.GetWeatherType() == rainy);    //  A PARATARTALOM 100 VOLT
}


#endif
