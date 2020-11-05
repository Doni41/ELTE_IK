//
//  hunter.cpp
//  NegyedikKotelezoHazi
//
//  Created by Hegyesi Ákos on 2020. 04. 28..
//  Copyright © 2020. Hegyesi Ákos. All rights reserved.
//

#include "hunter.hpp"
#include "animals.hpp"


//  OSSZEGZES
int Hunter::sumLion () {
    //  SEGED REKORD SZARMAZTATASA
    struct Visitor : public AnimalVisitorBase {
        int sum = 0;
        virtual void Accept (const Lion& lion) override {
            if (lion.isMale()) {
                ++sum;
            }
        }
    };
    
    Visitor visitor;
    
    for (const Trophy* t : _trophies) {
        t->Visit(visitor);
    }
    
    
    return visitor.sum;
}
