//
//  menu.c
//  OpreElsoHaziFeladat
//
//  Created by Hegyesi Ákos on 2021. 03. 25..
//

#include "menu.h"
#include "struct.h"
#include <string.h>

/* funtion to run the application */
void run()
{
    int b;
    PersonHandler p;
    char fileName[255] = {};
    
    printf("Please, give a name to the output file (eg.: xyz.txt, xyz.dat): ");
    scanf("%s", fileName);
    
    readDataFromFile(&p, fileName);
    
    do {
        b = menuPrint();
        switch (b) {
            case 2:
                readNew(&p);
                writeOutPut(&p, fileName);
                break;
            case 3:
                deleteP(&p);
                writeOutPut(&p, fileName);
                break;
            case 4:
                modifyP(&p);
                writeOutPut(&p, fileName);
                break;
            case 5:
                printP(&p);
                writeOutPut(&p, fileName);
                break;
            default:
                printf("Goodbye!\n");
        }
    } while(b != 1);
    
    freePersonHandler(&p);
}

/* function to print menu */
int menuPrint()
{
    char read[100];
    int answer = -1;
    
    printf("\n************************************************************\n");
    printf("1. End program\n");
    printf("2. Add new Person\n");
    printf("3. Remove Person\n");
    printf("4. Modify Person\n");
    printf("5. Print the database\n");
    printf("\n************************************************************\n");
    

    do
    {
        printf("The number should be between 1 and 5: ");
        scanf("%s", read);
        answer = atoi(read);
        printf("Nummber: %d\n" ,answer);
    } while ((answer < 1 || answer > 5));
    
    return answer;
}

/* Reads data from fiels */
void readDataFromFile (PersonHandler* p, char* fileName)
{
    FILE *reads;
    reads = fopen(fileName, "r");
    initPersonHandler(p);
    
    if (reads == NULL) {
        printf("\n %s does not contains any data!\n", fileName);
        return;
    } else {
        while(!feof(reads)) {
            Person person;

            char wp[4] = {};
            fscanf(reads, "Fist name: %s , Last name: %s , Birth year: %d , Phone number: %s , Paid: %s \n", person.firstName, person.lastName, &person.birthYear, person.phoneNumber, wp);
            
            if (strcmp(wp, "Yes")) {
                person.isWillingToPay = 0;
            } else {
                person.isWillingToPay = 1;
            }
            
            addUser (p, person);
        }
    }
    
    fclose(reads);
}

/* void function to add new person */
void readNew(PersonHandler* p)
{
    Person newp = readPerson(0, 0, p);
    addUser(p, newp);
}

/* void function to remove a person */
void deleteP (PersonHandler* p)
{
    Person newp = readPerson(1, 1, p);
    deletePerson(p, newp.lastName, newp.phoneNumber, newp.birthYear);
}

/* void function to modify a person */
void modifyP (PersonHandler* p)
{
    Person oldp = readPerson(1 , 1, p);
    Person newp = readPerson(1, 0, p);
    
    modifyPerson(p, oldp.lastName, oldp.phoneNumber, oldp.birthYear, newp.firstName, newp.lastName, newp.birthYear, newp.phoneNumber, newp.isWillingToPay);
}

/* void to print the persons */
void printP (PersonHandler* p)
{
    printUsers(p);
}

/* read a person from console */
struct Person readPerson (int number, int mod, PersonHandler* p) {
    char fs[50] = {};
    char ls[50] = {};
    int by = -1;
    char pn[25] = {};
    int pa = -1;
    
    if (number == 0)
    {
        if (mod == 0) {
            readWhole(fs, ls, &by, pn, &pa);
            if (!(checkDetails(fs, ls, by, pn, pa)))
            {
                while(!(checkDetails(fs, ls, by, pn, pa)))
                {
                    printf("Wrong datas! Please give the correct personal informations again!\n");
                    readWhole(fs, ls, &by, pn, &pa);
                }
            }
        }
    }
    else
    {
        if (p->size > 0)
        {
            if (mod == 1) {
                printf("Please give some information about the person!\n");
                readPart(ls, &by, pn);
                int ind = linearSearch(p, ls, pn, by);
                
                if (ind == -1) {
                    while (linearSearch(p, ls, pn, by) == -1) {
                        printf("Wrong personal informations! Please give the correct personal informations!\n");
                        readPart(ls, &by, pn);
                    }
                    ind = linearSearch(p, ls, pn, by);
                }
                return (p->persons[ind]);
            }
            else {
                printf("Please give the modified informations!\n");
                readNewWhole(fs, ls, &by, pn, &pa);
                
                if (!(checkDetails(fs, ls, by, pn, pa)))
                {
                    while(!(checkDetails(fs, ls, by, pn, pa)))
                    {
                        printf("Invalid formats or values! Please give the new corrent personal informations again!\n");
                        readNewWhole(fs, ls, &by, pn, &pa);
                    }
                }
            }
        }
        else
        {
//            printf("Person list is empty!\n");
        }
    }
        
    
    Person person;
    strcpy(person.firstName, fs);
    strcpy(person.lastName, ls);
    person.birthYear = by;
    strcpy(person.phoneNumber, pn);
    person.isWillingToPay = pa;
    
    return person;
}

/* checking the datas from user */
bool checkDetails (char* fs, char* ls, int by, char* pn, int pa)
{
    bool isValid = strlen(fs) != 0
                    && strlen(ls) != 0
                    && (by > 1900 && by < 2022)
                    && (strlen(pn) < 13 && strlen(pn) > 9)
                    && (pa >= 0 && pa <= 1);
    return isValid;
}

/* read to an output file */
void writeOutPut (PersonHandler* p, char* fileName)
{
    FILE *outfile = fopen (fileName, "w");
    
    if (outfile == NULL)
    {
        printf("Please give me a valid file name: ");
        return;
    }
    
    for (int i = 0; i < p -> size; i++) {
        char tmp[500];
        int size = snprintf(tmp, sizeof tmp, "Fist name: %s , Last name: %s , Birth year: %d , Phone number: %s , Paid: %s \n",
                 p->persons[i].firstName,
                 p->persons[i].lastName,
                 p->persons[i].birthYear,
                 p->persons[i].phoneNumber,
                 p->persons[i].isWillingToPay == 0 ? "No" : "Yes");
        
        fwrite(tmp, size, 1, outfile);
    }
    
    fclose(outfile);
}

/* Reading the whole infos */
void readWhole (char* fs, char* ls, int* by, char* pn, int* pa)
{
    printf("First name: ");
    scanf("%s", fs);
    printf("Last name: ");
    scanf("%s", ls);
    printf("Birth year: ");
    scanf("%d", by);
    printf("Phone number: ");
    scanf("%s", pn);
    printf("Free(0) or Paid(1): ");
    scanf("%d", pa);
}

/* Read just for the modification */
void readPart (char* ls, int* by, char* pn)
{
    printf("Old last name: ");
    scanf("%s", ls);
    printf("Old birth year: ");
    scanf("%d", by);
    printf("Old phone number: ");
    scanf("%s", pn);
}

/* Read the new infos */
void readNewWhole (char* fs, char* ls, int* by, char* pn, int* pa)
{
    printf("New first name: ");
    scanf("%s", fs);
    printf("New last name: ");
    scanf("%s", ls);
    printf("New birth year: ");
    scanf("%d", by);
    printf("New phone number: ");
    scanf("%s", pn);
    printf("New Free(0) or Paid(1): ");
    scanf("%d", pa);
}
