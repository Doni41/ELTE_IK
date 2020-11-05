//
//  main.cpp
//  MasodikBeadando
//
//  Created by Hegyesi Ákos on 2020. 04. 13..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

//  MASODIK NAGY BEADANDO HAZI FELADAT

//  FELADAT : Az Országos Horgász Bajnokság mindegyik versenyén feljegyezték a versenyzők
//      eredményeit, és egy szöveges állományban rögzítették az adatokat. Ennek minden sora
//      tartalmazza a versenyző horgász és a verseny azonosítóját (szóközök nélküli sztring),
//      majd halfajta-súly párok (szóközök nélküli sztring és valósszám párok) formájában az
//      a dott versenyen elért fogásokat. Az adatok szóközökkel vagy tabulátorjelekkel vannak egy
//      soron belül elválasztva. A szöveges állomány sorait a horgászok szerint rendezték.
//      Feltehetjük, hogy a szöveges állomány helyesen van kitöltve. Példa az állomány egy
//      sorára:
//      JANIBÁ Kiliti0512 Ponty 4.5 Ponty 5.3 Harcsa 9.6
//      (1) Összesen hány pontyot fogtak a versenyzők, és mennyi az átlagos súlyuk? Ha nem
//      fogtak pontyot, nullát írjunk ki átlagos súlynak!
//      (2) Hány olyan horgász vett részt a versenyeken, aki csak pontyot fogott?

//  A FELADAT MEGOLDASA SORAN A A GYAKORLATOK, ILLETVE A MINTAFELADAT MEGOLDASA ADOTT KIINDULASI ALAPOT

#include "EnorCompetition.hpp"
#include "EnorFisherman.hpp"
#include <iostream>


using namespace std;

//  FELADAT 1 MEGOLDASAHOZ KESZULT FUGGVENYEK, MAIN FUGVENY JOBB OLVASHATOSAGA MIATT

    //   OSSZEGZES A CIKLUSBAN
    void sumCompetition (Competition& e, Sum& s) {
        //  AZ AKTUALIS SORBAN TALALHATO PONTYOK SZAMANAK ES SULYANAK OSSZEGES HOZZAADJUK EGY AZ EGESZ LISTAN VEGIG MENO OSSZEGZO ES MEGSZAMLALO ELEMHEZ
        s._sum_amount += e._carp_amount;
        s._sum_counter += e._carp_counter;
    }

   //   MINTA KIIRATAS SORONKENT - PONTYOK ES ATLAGOS SULYUK ADOTT VERSENYZO ADOTT VERSENYEN
    void everyLine (Competition& e) {
        if (e._carp_amount != 0) {
            cout << "A " << e._fisherman_id << " horgasz,  " << (e._carp_amount / (double)e._carp_counter) << " kg pontyot fogott átlagosan a(z) " << e._competition_id << " versenyen!" << endl;
        }
        else {
            e._carp_counter = 1;    //   0-VAL VALO OSZTAS ELKERÜLESE MIATT
            cout << "A " << e._fisherman_id << " horgasz,  " << (e._carp_amount / (double)e._carp_counter) << " kg pontyot fogott a(z) " << e._competition_id << " versenyen!" << endl;
        }
    }

    //  ELSO FELADATBAN KERT OSSZEGZES EGYEDI FELSOROLOJA OSSZEGZES TETELLEL
    void taskOne (CompetitionEnor& _t_first, Competition& e, Sum& s) {
        //  OSSZEGZESHEZ NULLAZAS
        s._sum_amount = 0;
        s._sum_counter = 0;
    
        for ( _t_first.first() ; !_t_first.end () ; _t_first.next() ) {
        
            e = _t_first.current ();
        
            //everyLine(e); - SORONKENTI KIIRATASHOZ KESZULT
        
            //  MEGHIVJA AZ OSSZEGZES FUGGVENYET
            sumCompetition(e, s);
        }
    }

    //  KIIRJA A KAPOTT OSSZEGET, ILLETVE ATLAG SULYT, HA FOGTAK AZ ADOTT VERSENYEN PONTYOT
    void sumCout (Sum& s) {
        if (s._sum_counter != 0 && s._sum_amount != 0) {
            cout << "Az osszes horgaszaton fogott pontyok osszsulya : "<< s._sum_amount << " kg," << " az ossz darabszam : " << s._sum_counter << ", es az atlagos sulyuk : " << (s._sum_amount / (double)s._sum_counter) << " kg!" << endl; ;

        }
        else {
            cout << "Az osszes horgaszversenyen fogott pontyok sulya : 0 kg, es atlagsulyuk is 0 kg, azaz a versenyen nem fogtak pontyot!" << endl;
        }
    }

//  FELADAT 2 MEGOLDASAHOZ KESZULT FUGGVENYEK, MAIN FUGVENY JOBB OLVASHATOSAGA MIATT

    //  MEGSZAMOLJA, HOGY HANY HORGASZ FOGOTT CSAK PONTYOT
    void taskTwo ( const string &_filename , int& counter) {
        bool l = true;
    
        FishermanEnor t (_filename);
        for (t.first() ; !t.end() ; t.next()) {
            l = t.current()._only_carp;
            if (l) {
                counter += 1;
            }
        }
    }

    //  FUGGVENY A MASODIK FELADAT EREDMENYENEK KIIRATASAHOZ
    void twoCout (int& counter) {
        cout << "\nAzon horgaszok szama, akik csak pontyot fogtak : " << counter << endl;
    }

#define NORMAL_MODE
#ifdef NORMAL_MODE

//  MAIN FGV

int main() {
    
    cout << "A ket feladat megoldasahoz kulon szukseges megadni a txt fajlok neveit , inp1-5 -ig kifejezetten az elso feladathoz keszultek, inp6-11 -ig kifejezetten a masodik feladathoz!\n" << endl;
    
    //  ELSO FELADAT MEGOLDASA
    bool error_first = false;
    
    try {
        std::string _filename;
        std::cout << "Kerem adja meg az elso feladathoz, az adatokat tartalmazo fajl nevet : "; // inp1.txt , inp2.txt , inp3.txt , inp4.txt , inp5.txt
        std::cin >> _filename;
        
        CompetitionEnor _t_first (_filename);
        Competition e;
        Sum s;
        
        //  FELADAT MEGOLDASA FUGGVENYBE KISZERVEZVE
        taskOne(_t_first , e , s);
        //  KIIRATAS FUGGVENYBE KISZERVEZVE
        sumCout (s);
    }
    catch (CompetitionEnor::Error err_first) {
        error_first = true;
        if (err_first == CompetitionEnor::NOTPOSITIVE) {
            cout << "\nA hal sulya nem lehet 0-nal kisebb szam, kerem ellenorizze a bemeneti fajlt!\n" << endl;
        }
        else if (err_first == CompetitionEnor::WRONGLIFE) {
            cout << "\nRossz a megadott fajlnev, kerem ellenorizze, es probalja ujra!\n" << endl;
        }
        else {
            cout << "\nIsmeretlen programhiba!\n" << endl;
        }
    }
    
    //  MASODIK FELADAT MEGOLDASA
    
    bool error_second = false;
    try {
        std::string _filename;
        std::cout << "Kerem adja meg a masodik feladathoz, az adatokat tartalmazo fajl nevet : ";   // inp6.txt , inp7.txt , inp8.txt , inp9.txt , inp10.txt , inp11.txt , inp12.txt , inp13.txt , inp14.txt
        std::cin >> _filename;
        
        int counter = 0;
        //  FELADAT MEGOLDASA
        taskTwo(_filename , counter);
        //  EREDMENY KIIRATASA
        twoCout (counter);
    }
    catch (CompetitionEnor::Error err_second) {
        error_second = true;
        if (err_second == CompetitionEnor::NOTPOSITIVE) {
            cout << "\nA hal sulya nem lehet 0-nal kisebb szam, kerem ellenorizze a bemeneti fajlt!\n" << endl;
        }
        else if (err_second == CompetitionEnor::WRONGLIFE) {
            cout << "\nRossz a megadott fajlnev, kerem ellenorizze, es probalja ujra!\n" << endl;
        }
        else {
            cout << "\nIsmeretlen programhiba!\n" << endl;
        }
    }
    
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//  KONSTRUKTOR ES HIBAKEZELESE

TEST_CASE ("HIBAKEZELESEK") {
    
    //  HIBAS FAJLNEV - WRONGFILE
    CHECK_THROWS (CompetitionEnor ("t.txt"));
    //  URES FILE - WRINGFILE
    CHECK_THROWS (CompetitionEnor ("t0.txt"));
    //  NEGATIV SZAMOT TARTALMAZ - NOTPOSITIVE
    CHECK_THROWS (CompetitionEnor ("t5.txt"));
}

//  OSSZEGZES

TEST_CASE ("Egy verseny alatt tobben is fogtak, egy versenyen akar tobbet is" , "inp1.txt" ) {
    CompetitionEnor t_1 ("inp1.txt");
    Competition e_1;
    Sum s_1;
    
    taskOne(t_1, e_1, s_1);
    float test_1 = 197.4;
    double average_1 = s_1._sum_amount / s_1._sum_counter;
    
    CHECK (t_1.current()._fisherman_id == "FERI0136");
    CHECK ((float)s_1._sum_amount == test_1);
    CHECK (s_1._sum_counter == 12);
    CHECK (average_1 == 16.45);
}

TEST_CASE ("Egy versenyzo, egy verseny, ketszer fogott, de egyszer 0 kg" , "inp2.txt" ) {
    CompetitionEnor t_2 ("inp2.txt");
    Competition e_2;
    Sum s_2;
    
    taskOne(t_2, e_2, s_2);
    float test_2 = 4.6;
    double average_2 = s_2._sum_amount / s_2._sum_counter;
    
    CHECK ((float)s_2._sum_amount == test_2);
    CHECK (s_2._sum_counter == 1);
    CHECK (average_2 == 4.6);
    CHECK (t_2.current()._fisherman_id == "JANIBA0122");
}

TEST_CASE ("Tobb versenyzo, de az eredmeny 4.6, mert tele van 0kg-os elemekkel" , "inp3.txt" ) {
    CompetitionEnor t_3 ("inp3.txt");
    Competition e_3;
    Sum s_3;
    
    taskOne(t_3, e_3, s_3);
    float test_3 = 4.6;
    double average_3 = s_3._sum_amount / s_3._sum_counter;
    
    CHECK ((float)s_3._sum_amount == test_3);
    CHECK (s_3._sum_counter == 1);
    CHECK (average_3 == 4.6);
    CHECK (t_3.current()._fisherman_id == "FERI0136");
}

TEST_CASE ("Senki sem fogott pontyot" , "inp4.txt" ) {
    CompetitionEnor t_4 ("inp4.txt");
    Competition e_4;
    Sum s_4;
    
    taskOne(t_4, e_4, s_4);
    int test_4 = 0;
    
    CHECK (s_4._sum_amount == test_4);
    CHECK (s_4._sum_counter == 0);
    CHECK (t_4.current()._fisherman_id == "FERI0136");
}


//  MEGSZAMLALAS


TEST_CASE ("Harom emberbol csak egy fogott csak, es kizarolag pontyot, az utolso" , "inp6.txt") {
    CompetitionEnor t_6 ("inp6.txt");
    FishermanEnor t_6_2 ("inp6.txt");
    Competition e_6;
    Sum s_6;
    
    taskOne(t_6, e_6, s_6);
    int counter_6 = 0;
    taskTwo("inp6.txt" , counter_6);
    float test_6 = 200.4;
    double average_6 = s_6._sum_amount / s_6._sum_counter;
    
    CHECK ((float)s_6._sum_amount == test_6);
    CHECK (s_6._sum_counter == 8);
    CHECK ((float)average_6 == (float)25.05);
    CHECK (t_6.current()._fisherman_id == "MIKI");
    
    CHECK (counter_6 == 1);
}

TEST_CASE ("Harom emberbol csak egy fogott csak, es kizarolag pontyot, az elso" , "inp7.txt") {
    CompetitionEnor t_7 ("inp7.txt");
    FishermanEnor t_7_2 ("inp7.txt");
    Competition e_7;
    Sum s_7;
    
    taskOne(t_7, e_7, s_7);
    int counter_7 = 0;
    taskTwo("inp7.txt" , counter_7);
    float test_7 = 99.6;
    double average_7 = s_7._sum_amount / s_7._sum_counter;
    
    CHECK ((float)s_7._sum_amount == test_7);
    CHECK (s_7._sum_counter == 5);
    CHECK ((float)average_7 == (float)19.92);
    CHECK (t_7.current()._fisherman_id == "MIKI");
    
    CHECK (counter_7 == 1);
}

TEST_CASE ("Harom emberbol csak az utolso fogott csak, es kizarolag pontyot (egy sor, tobb elem)" , "inp8.txt") {
    CompetitionEnor t_8 ("inp8.txt");
    FishermanEnor t_8_2 ("inp8.txt");
    Competition e_8;
    Sum s_8;
    
    taskOne(t_8, e_8, s_8);
    int counter_8 = 0;
    taskTwo("inp8.txt" , counter_8);
    float test_8 = 60.9;
    double average_8 = s_8._sum_amount / s_8._sum_counter;
    
    CHECK ((float)s_8._sum_amount == test_8);
    CHECK (s_8._sum_counter == 5);
    CHECK ((float)average_8 == (float)12.18);
    CHECK (t_8.current()._fisherman_id == "MIKI");
    
    CHECK (counter_8 == 1);
}

TEST_CASE ("Harom emberbol mindenki csak, es kizarolag pontyot fogott" , "inp9.txt") {
    CompetitionEnor t_9 ("inp9.txt");
    FishermanEnor t_9_2 ("inp9.txt");
    Competition e_9;
    Sum s_9;
    
    taskOne(t_9, e_9, s_9);
    int counter_9 = 0;
    taskTwo("inp9.txt" , counter_9);
    float test_9 = 16.6;
    double average_9 = s_9._sum_amount / s_9._sum_counter;
    
    CHECK ((float)s_9._sum_amount == test_9);
    CHECK (s_9._sum_counter == 4);
    CHECK ((float)average_9 == (float)4.15);
    CHECK (t_9.current()._fisherman_id == "MIKI");
    
    CHECK (counter_9 == 3);
}

TEST_CASE ("Harom emberbol csak ketto ember fogott csak, es kizarolag pontyot (a harmadik 0kb pontyot fogott)" , "inp10.txt") {
    CompetitionEnor t_10 ("inp10.txt");
    FishermanEnor t_10_2 ("inp10.txt");
    Competition e_10;
    Sum s_10;
    
    taskOne(t_10, e_10, s_10);
    int counter_10 = 0;
    taskTwo("inp10.txt" , counter_10);
    float test_10 = 12;
    double average_10 = s_10._sum_amount / s_10._sum_counter;
    
    CHECK ((float)s_10._sum_amount == test_10);
    CHECK (s_10._sum_counter == 3);
    CHECK ((float)average_10 == (float)4);
    CHECK (t_10.current()._fisherman_id == "MIKI");
    
    CHECK (counter_10 == 2);
}

TEST_CASE ("Harom emberbol 0 fogott csak, es kizarolag pontyot (mindenki 0 kg-t)" , "inp11.txt") {
    CompetitionEnor t_11 ("inp11.txt");
    FishermanEnor t_11_2 ("inp11.txt");
    Competition e_11;
    Sum s_11;
    
    taskOne(t_11, e_11, s_11);
    int counter_11 = 0;
    taskTwo("inp11.txt" , counter_11);
    float test_11 = 0;
    
    CHECK ((float)s_11._sum_amount == test_11);
    CHECK (s_11._sum_counter == 0);
    CHECK (t_11.current()._fisherman_id == "MIKI");
    
    CHECK (counter_11 == 0);
}

TEST_CASE ("Egy ember, tobb ponty 1 sor osszesen" , "inp12.txt") {
    CompetitionEnor t_12 ("inp12.txt");
    FishermanEnor t_12_2 ("inp12.txt");
    Competition e_12;
    Sum s_12;
    
    taskOne(t_12, e_12, s_12);
    int counter_12 = 0;
    taskTwo("inp12.txt" , counter_12);
    float test_12 = 4.6;
    double average_12 = s_12._sum_amount / s_12._sum_counter;
    
    CHECK ((float)s_12._sum_amount == test_12);
    CHECK (s_12._sum_counter == 1);
    CHECK ((float)average_12 == (float)4.6);
    CHECK (t_12.current()._fisherman_id == "JANIBA");
    
    CHECK (counter_12 == 0);    //  ITT HELYTELEN KITOLTES MIATT LESZ 0 AZ EREDMENY - HA VALAKI FOGOTT MAR EGYSZER 4.6 KG PONTYOT, AKKOR UTANA HELYTELEN KITOLTESNEK SZAMIT, HOGY FOGOTT MEG 0.0KG PONTYOT. AMENNYIBEN UGY SZEREPELNE A SOROKBAN, HOGY HARCSA 3.5 KG ES PONTY 0KG UGY HELYESEN MUKODIK AZ ALGORITMUS, ES A FELADAT MEGFOGALMAZASA SZERINT EZT FELTETELEZHETJUK
}

TEST_CASE ("Egy ember, tobb ponty 2 sor osszesen" , "inp13.txt") {
    CompetitionEnor t_13 ("inp13.txt");
    FishermanEnor t_13_2 ("inp13.txt");
    Competition e_13;
    Sum s_13;
    
    taskOne(t_13, e_13, s_13);
    int counter_13 = 0;
    taskTwo("inp13.txt" , counter_13);
    float test_13 = 21.0;
    double average_13 = s_13._sum_amount / s_13._sum_counter;
    
    CHECK ((float)s_13._sum_amount == test_13);
    CHECK (s_13._sum_counter == 3);
    CHECK (t_13.current()._fisherman_id == "JANIBA");
    CHECK (average_13 == 7);
    
    CHECK (counter_13 == 0);    //  AZ ELOZO TEST_CASE-BEN MEGFOGALMAZOTTAK SZERINT AZ EREDMENY ITT IS NULLA LESZ, MERT HELYTELENUL LETT KITOLTVE A FAJL, HA NEM LENNE BENNE A 0 ELEM, AKKOR HELYESEN 1 LENNE AZ EREDMENY
}

TEST_CASE ("Elozo TEST_CASE, ha helyesen lenne kitoltve" , "inp14.txt") {
    CompetitionEnor t_14 ("inp14.txt");
    FishermanEnor t_14_2 ("inp14.txt");
    Competition e_14;
    Sum s_14;
    
    taskOne(t_14, e_14, s_14);
    int counter_14 = 0;
    taskTwo("inp14.txt" , counter_14);
    float test_14 = 21.0;
    double average_14 = s_14._sum_amount / s_14._sum_counter;
    
    CHECK ((float)s_14._sum_amount == test_14);
    CHECK (s_14._sum_counter == 3);
    CHECK (t_14.current()._fisherman_id == "JANIBA");
    CHECK (average_14 == 7);
    
    CHECK (counter_14 == 1);    //  ITT MAR HELYESEN LETT KITOLTVE, AZAZ EGY SORBAN NEM SZEREPEL PONT 4.6 ES PONTY 0.0 EGYSZERRE, IGY HELYESEN MUKODIK RA AZ ALGORITMUS
}

#endif



