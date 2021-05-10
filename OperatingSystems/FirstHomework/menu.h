//
//  menu.h
//  OpreElsoHaziFeladat
//
//  Created by Hegyesi Ákos on 2021. 03. 25..
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"

bool checkDetails (char* fs, char* ls, int by, char* pn, int pa);
int menuPrint(void);
struct Person readPerson (int number, int mod, PersonHandler* p);
struct Person readToModify(void);
void readDataFromFile (PersonHandler* p, char* fileName);
void readNew(PersonHandler* p);
void deleteP (PersonHandler* p);
void run();
void modifyP (PersonHandler* p);
void printP (PersonHandler* p);
void writeOutPut (PersonHandler* p, char* fileName);
void readWhole (char* fs, char* ls, int* by, char* pn, int* pa);
void readPart (char* ls, int* by, char* pn);
void readNewWhole (char* fs, char* ls, int* by, char* pn, int* pa);

#endif /* menu_h */
