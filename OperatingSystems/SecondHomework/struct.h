//
//  struct.h
//  OpreElsoHaziFeladat
//
//  Created by Hegyesi Ákos on 2021. 03. 25..
//

#ifndef struct_h
#define struct_h

typedef struct Person {
    char firstName[50];
    char lastName[50];
    int birthYear;
    char phoneNumber[25];
    int isWillingToPay;
    int vaccinated;
} Person;

typedef struct PersonHandler {
    int size;
    Person* persons;
} PersonHandler;

int menuPrint(void);
void initPersonHandler (PersonHandler* p);
void freePersonHandler (PersonHandler* p);
void addUser (PersonHandler* p, Person person);
void printUsers (PersonHandler* p);
void printPerson (Person* p);
int linearSearch (PersonHandler* p, char* lastName, char* phoneNumber, int birthYear);
void setVaccinatedTrue (char* lastName, char* phoneNumber, int birthYear);
void deletePerson(PersonHandler* p, char* lastName, char* phoneNumber, int birthYear);
void modifyPerson(PersonHandler* p, char* oldName, char* oldPhone, int oldYear, char* firstName, char* lastName, int birthYear, char* phoneNumber, int paid);

typedef struct SignalPersons {
    Person persons_to_vaccinated [100];
    int counter;
    int vaccinatedCounter;
} SignalPersons;


#endif /* struct_h */
