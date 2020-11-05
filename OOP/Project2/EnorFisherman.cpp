//
//  EnorFisherman.cpp
//  MasodikBeadando
//
//  Created by Hegyesi Ákos on 2020. 04. 13..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//
//  A FELADAT MEGOLDASA SORAN A A GYAKORLATOK, ILLETVE A MINTAFELADAT MEGOLDASA ADOTT KIINDULASI ALAPOT

#include "EnorFisherman.hpp"

void FishermanEnor::next() {
    //  ADDIG TART A FELSOROLAS, AMIG AZ UTOLSO SOR VEGERE NEM ERTUNK
    _end_fisherman = _tt.end();
    
    if (!_end_fisherman) {
        _curr._id = _tt.current()._fisherman_id;
        //  ELDONTES
        _curr._only_carp = true;
        
        for ( ; !_tt.end() && _curr._id == _tt.current()._fisherman_id; _tt.next()) {
            //  OSSZE ESELEM, HOGY IGAZ, HOGY CSAK PONTYOT FOGOTT, ES A NEM PONTYOKAT FOGOTT ERTEK 0 - VALTOZO ERTEKENEK MUKODESE AZ EnorCompetition.cpp-BEN LATHATO
            _curr._only_carp = _curr._only_carp && (_tt.current()._have_nocarp == 0);
        }
    }
}
