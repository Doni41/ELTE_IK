//
//  struct.c
//  OpreElsoHaziFeladat
//
//  Created by Hegyesi Ákos on 2021. 03. 25..
//

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <stdbool.h>
#include <string.h>

/* Creating new PersonHandler */
void initPersonHandler (PersonHandler* p)
{
    p -> size = 0;
    p -> persons = NULL;
}

/*  */
void freePersonHandler (PersonHandler* p)
{
    initPersonHandler(p);
}

/* Add new Person */
void addUser (PersonHandler* p, Person person)
{
    Person* persons = (Person*)malloc((p->size + 1) * sizeof(Person));
    for (int i = 0; i < p -> size; ++i) {
        persons[i] = p->persons[i];
    }
    persons[p->size] = person;
    free(p->persons);
    p->persons = persons;
    p -> size += 1;
}

/* Printing all person */
void printUsers (PersonHandler* p)
{
    for (int i = 0; i < p -> size; i++)
    {
            printf("First name: %s, Last name: %s, Birt year: %d, Phone number: %s, Paid: %s\n", p -> persons[i].firstName, p -> persons[i].lastName, p -> persons[i].birthYear, p -> persons[i].phoneNumber, p -> persons[i].isWillingToPay == 0 ? "No" : "Yes");
    }
}

/* Printing a person */
void printPerson (Person* p)
{
    printf("First name: %s, Last name: %s, Birt year: %d, Phone number: %s, Paid: %s\n", p -> firstName, p -> lastName, p -> birthYear, p -> phoneNumber, p -> isWillingToPay == 0 ? "No" : "Yes");
}

/* Linear searching for a person */
int linearSearch (PersonHandler* p, char* lastName, char* phoneNumber, int birthYear)
{
    
    for (int i = 0; i < p -> size; i++)
    {
        if (strcmp(p -> persons[i].lastName,lastName) == 0
            && p -> persons[i].birthYear == birthYear
            && strcmp(p -> persons[i].phoneNumber,phoneNumber) == 0)
        {
            return i;
        }
    }
    
    //printf("User with last name: %s, phone number: %s, birth year: %d does not exists!\n", lastName, phoneNumber, birthYear);
    return -1;
}

/* Deleting a person */
void deletePerson(PersonHandler* p, char* lastName, char* phoneNumber, int birthYear) {
    if (p->size > 0)
    {
        int ind = linearSearch(p, lastName, phoneNumber, birthYear);
        if (ind != -1)
        {
            for (int j = ind; j < p -> size; j++)
            {
                p -> persons[j] = p -> persons[j + 1];
            }
            p -> size -= 1;
        }
        else {
            printf("User with last name: %s, phone number: %s, birth year: %d does not exists!\n", lastName, phoneNumber, birthYear);
        }
        
        if (p->size == 0)
        {
            free(p->persons);
            p->persons = NULL;
            
        }
    }
    else
    {
        printf("Person list is empty!\n");
    }

}

/* Modifying a person */
void modifyPerson(PersonHandler* p, char* oldName, char* oldPhone, int oldYear, char* firstName, char* lastName, int birthYear, char* phoneNumber, int paid) {
    if (p->size > 0)
    {
        int ind = linearSearch(p, oldName, oldPhone, oldYear);
        if (ind != -1)
        {
            strcpy(p -> persons[ind].firstName,firstName);
            strcpy(p -> persons[ind].lastName, lastName);
            p -> persons[ind].birthYear = birthYear;
            strcpy(p -> persons[ind].phoneNumber,phoneNumber);
            p -> persons[ind].isWillingToPay = paid;
            
            printf("Person modified successfully!\n");
        }
        else
        {
            printf("User with last name: %s, phone number: %s, birth year: %d does not exists!\n", lastName, phoneNumber, birthYear);
        }
    }
    else
    {
        printf("Person list is empty!\n");
    }
    
}
