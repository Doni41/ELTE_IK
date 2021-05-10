//
//  menu.c
//  OpreElsoHaziFeladat
//
//  Created by Hegyesi Ákos on 2021. 03. 25..
//

#include "menu.h"
#include "struct.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* global declaration */
SignalPersons signal_person_list;

/* pipe[0] - readable */
/* pipe[1] - writeable */
int pipefd1[2];
int pipefd2[2];
int pipefd3[2];
int pipefd4[2];
int pipefd5[2];
int pipefd6[2];

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
            case 6:
                startTheBuses(&p);
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
    printf("6. Start vakcinacio\n");
    printf("\n************************************************************\n");
    

    do
    {
        printf("The number should be between 1 and 6: ");
        scanf("%s", read);
        answer = atoi(read);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("Nummber: %d\n" ,answer);
    } while ((answer < 1 || answer > 6));
    
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
            char vc[4] = {};
            fscanf(reads, "Fist name: %s , Last name: %s , Birth year: %d , Phone number: %s , Paid: %s , Vaccinated: %s \n", person.firstName, person.lastName, &person.birthYear, person.phoneNumber, wp, vc);
            
            if (strcmp(wp, "Yes") == 0) {
                person.isWillingToPay = 1;
            } else {
                person.isWillingToPay = 0;
            }
            
            if (strcmp(vc, "Yes") == 0) {
                person.vaccinated = 1;
            } else {
                person.vaccinated = 0;
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
    person.vaccinated = 0;
    
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
        int size = snprintf(tmp, sizeof tmp, "Fist name: %s , Last name: %s , Birth year: %d , Phone number: %s , Paid: %s , Vaccinated: %s \n",
                 p->persons[i].firstName,
                 p->persons[i].lastName,
                 p->persons[i].birthYear,
                 p->persons[i].phoneNumber,
                 p->persons[i].isWillingToPay == 0 ? "No" : "Yes",
                 p->persons[i].vaccinated == 0 ? "No" : "Yes");
        
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

void signalhandler(int signumber)
{
    printf("Megerkezett a 'HARCRA FEL!' jelzes!\n");
    printf("A kovetkezo emberek indulnak vakcinalodni a mai napon:!\n");
    for (int i = 0; i < signal_person_list.counter; i++)
    {
        printPerson(&signal_person_list.persons_to_vaccinated[i]);
    }
    printf("Szulo elkezdi kuldeni az adatokat a vakcinaciohoz!\n");
    write(pipefd1[1], (&signal_person_list.persons_to_vaccinated), signal_person_list.counter * sizeof(Person));
    close(pipefd1[1]);
}

void signalhandler2(int signumber)
{
    printf("Megerkezett a 'HARCRA FEL!' jelzes!\n");
    
    int person_number_1 = signal_person_list.counter / 2;
    int person_number_2 = signal_person_list.counter - (signal_person_list.counter / 2);
    Person tmp1 [person_number_1];
    Person tmp2 [person_number_2];
    int tmp = 0;
    for (int i = 0; i < signal_person_list.counter; ++i)
    {
        if (i < person_number_1)
        {
            tmp1[i] = signal_person_list.persons_to_vaccinated[i];
        }
        if (i >= person_number_1)
        {
            tmp2[tmp] = signal_person_list.persons_to_vaccinated[i];
            ++tmp;
        }
    }
        
    printf("Szulo elkezdi kuldeni az adatokat a vakcinaciohoz az elso gyereknek!\n");
    int number1 = 1;
    int number2 = 2;
    write(pipefd4[1], &tmp1, person_number_1 * sizeof(Person));
    close(pipefd4[1]);

    printf("Szulo elkezdi kuldeni az adatokat a vakcinaciohoz a masodik gyereknek!\n");
    write(pipefd6[1], &tmp2, person_number_2 * sizeof(Person));
    close(pipefd6[1]);
}


/* Start the vakcinacio process */
void startTheBuses (PersonHandler* p){
    
    signal_person_list.counter = 0;
    signal_person_list.vaccinatedCounter = 0;
    
    signal(SIGUSR1,signalhandler);
    signal(SIGUSR2,signalhandler2);

    
    if(pipe(pipefd1) == -1 || pipe(pipefd2) == -1 || pipe(pipefd3) == -1 || pipe(pipefd4) == -1 || pipe(pipefd5) == -1 || pipe(pipefd6) == -1) {
        printf("Hiba a pipe nyitasa kozben!\n");
        return;
    }
    
    
    for (int i = 0; i < p->size; ++i)
    {
        if (p->persons[i].vaccinated == 0)
        {
            signal_person_list.persons_to_vaccinated[signal_person_list.counter] = p->persons[i];
            ++signal_person_list.counter;
        }
    }
    

    
    /* 1 bus starts */
    if(signal_person_list.counter >= 4 && signal_person_list.counter < 10)
    {
        pid_t child = fork();
        if (child < 0)
        {
            printf("The fork calling wasn't succesful!\n");
        }
        
        if (child > 0)
        {
            pause();

            close(pipefd1[0]);
            close(pipefd2[1]);

            int status;
            waitpid(child,&status,0);
            Person vaccinated_persons [signal_person_list.counter];
            int db = read(pipefd2[0], &vaccinated_persons, signal_person_list.counter * sizeof(Person));
            close(pipefd2[0]);

            printf("A szulo a kovetkezo embereknek jegyzi be, hogy oltva:\n");
            for(int i = 0; i < signal_person_list.counter; ++i)
            {
                if (vaccinated_persons[i].birthYear)
                {
                    for(int j = 0; j < p->size; ++j)
                    {
                        if (
                                strcmp(vaccinated_persons[i].lastName, p->persons[j].lastName) == 0
                                && strcmp(vaccinated_persons[i].phoneNumber, p->persons[j].phoneNumber) == 0
                                && vaccinated_persons[i].birthYear == p->persons[j].birthYear
                        )
                        {
                            p->persons[j].vaccinated = 1;
                            printPerson(&p->persons[j]);
                        }
                    }
                }
            }
        }
        else
        {
            srand(time(NULL));
            sleep(1);
            kill(getppid(), SIGUSR1);
            close(pipefd1[1]);
            close(pipefd2[0]);

            printf("Gyerek elkezdi kiolvasni az adatokat, hogy nyugtazza!\n");
            Person persons_to_read [signal_person_list.counter];
            Person vaccinated_persons [signal_person_list.counter];

            read(pipefd1[0], &persons_to_read, signal_person_list.counter * sizeof(Person));
            close(pipefd1[0]);
            printf("Nyugtázva:\n");

            for (int i = 0; i < signal_person_list.counter; ++i)
            {
                printPerson(&persons_to_read[i]);;
            }
            
            for (int i = 0; i < signal_person_list.counter; ++i) {
                int r = rand() % 11;
                if (r < 9)
                {
                    printf("Beoltasra kerult:\n");
                    printPerson(&persons_to_read[i]);
                    vaccinated_persons[i] = persons_to_read[i];
                    ++signal_person_list.vaccinatedCounter;
                }
                else
                {
                    printf("Sajnos nem kerult beoltasra:\n");
                    printPerson(&persons_to_read[i]);
                }
            }
            write(pipefd2[1], &vaccinated_persons, signal_person_list.counter * sizeof(Person));
            printf("Osszesen %d ember kerult ma beoltasra!\n", signal_person_list.vaccinatedCounter);
            close(pipefd2[1]);
            exit(0);
        }
    }
    
    /* 2 buses start */
    if (signal_person_list.counter > 9)
    {
        pid_t child1 = fork();
        if (child1 < 0)
        {
            printf("The first fork calling wasn't succesful!\n");
        }
        if (child1 > 0)
        {
            pid_t child2 = fork();
            if (child2 < 0)
            {
                printf("The second fork calling wasn't succesful!\n");
            }
            if (child2 > 0)
            {
                pause();
                close(pipefd3[1]);
                close(pipefd4[0]);
                close(pipefd5[1]);
                close(pipefd6[0]);

                int status_1;
                int status_2;
                
                sleep(3);
                
                printf("A szulo elkezdi visszaolvasni az adatokat a gyerekektol!\n");
                int person_number_1 = signal_person_list.counter / 2;
                int person_number_2 = signal_person_list.counter - (signal_person_list.counter / 2);
                Person tmp1 [person_number_1];
                Person tmp2 [person_number_2];
                
                read(pipefd3[0], &tmp1, person_number_1 * sizeof(Person));
                close(pipefd3[0]);
                read(pipefd5[0], &tmp2, person_number_2 * sizeof(Person));
                close(pipefd5[0]);
                
                printf("A szulo a kovetkezo embereknek jegyzi be, hogy oltva, az elso gyerektol:\n");
                for(int i = 0; i < person_number_1; ++i)
                {
                    if (tmp1[i].birthYear)
                    {
                        for (int j = 0; j < p->size; ++j)
                        {
                            if (
                                strcmp(tmp1[i].lastName, p->persons[j].lastName) == 0
                                && strcmp(tmp1[i].phoneNumber, p->persons[j].phoneNumber) == 0
                                && tmp1[i].birthYear == p->persons[j].birthYear
                                )
                            {
                                p->persons[j].vaccinated = 1;
                                printPerson(&p->persons[j]);
                            }
                        }
                    }
                }
                
                printf("A szulo a kovetkezo embereknek jegyzi be, hogy oltva, a masodik gyerektol:\n");
                for(int i = 0; i < person_number_2; ++i)
                {
                    if (tmp2[i].birthYear)
                    {
                        for(int j = 0; j < p->size; ++j)
                        {
                            if (
                                strcmp(tmp2[i].lastName, p->persons[j].lastName) == 0
                                && strcmp(tmp2[i].phoneNumber, p->persons[j].phoneNumber) == 0
                                && tmp2[i].birthYear == p->persons[j].birthYear
                                )
                            {
                                p->persons[j].vaccinated = 1;
                                printPerson(&p->persons[j]);
                            }
                        }
                    }
                }

            }
            else if (child2 == 0)
            {
                int status_1;
                srand(time(NULL));
                close(pipefd5[0]);
                close(pipefd6[1]);
                
                sleep(1);
                printf("A masodik gyerek elkezdi kiolvasni a szulotol kapott adatokat, hogy nyugtazza:\n");
                int person_number_2 = signal_person_list.counter - (signal_person_list.counter / 2);
                Person tmp2 [person_number_2];
                read(pipefd6[0], &tmp2, person_number_2 * sizeof(Person));
                close(pipefd6[0]);
                
                sleep(2);
                printf("A masodik gyerek befejezte az olvasast, es a kovetkezo embereket kapta:\n");
                for (int i = 0; i < person_number_2; ++i)
                {
                    printPerson(&tmp2[i]);;
                }
                
                Person persons_to_send [person_number_2];
                for(int i = 0; i < person_number_2; ++i)
                {
                    int r = rand() % 11;
                    if (r < 9)
                    {
                        printf("Beoltasra kerult a kettes gyereknel:\n");
                        printPerson(&tmp2[i]);
                        persons_to_send[i] = tmp2[i];
                        ++signal_person_list.vaccinatedCounter;
                    }
                    else
                    {
                        printf("Sajnos nem kerult beoltasra:\n");
                        printPerson(&tmp2[i]);
                    }
                }
                
                printf("Osszesen %d ember kerult ma beoltasra a masodik gyereknel!\n", signal_person_list.vaccinatedCounter);
                printf("A masodik gyerek visszakuldi az adatokat a szulonek!\n");
                write(pipefd5[1], &persons_to_send, person_number_2 * sizeof(Person));
                close(pipefd5[1]);
                exit(0);
            }
        }
        else if (child1 == 0)
        {
            srand(time(NULL));
            printf("SIGUSR1 elkuldve!\n");
            kill(getppid(), SIGUSR2);
            close(pipefd3[0]);
            close(pipefd4[1]);
            
            sleep(1);
            printf("Az elso gyerek elkezdi kiolvasni a szulotol kapott adatokat, hogy nyugtazza:\n");
            int person_number_1 = signal_person_list.counter / 2;
            Person tmp1 [person_number_1];
            read(pipefd4[0], &tmp1, person_number_1 * sizeof(Person));
            close(pipefd4[0]);
            
            printf("Az elso gyerek befejezte az olvasast, es a kovetkezo embereket kapta:\n");
            for (int i = 0; i < person_number_1; ++i)
            {
                printPerson(&tmp1[i]);;
            }
            sleep(1);
            
            Person persons_to_send [person_number_1];
            for(int i = 0; i < person_number_1; ++i)
            {
                int r = rand() % 11;
                if (r < 9)
                {
                    printf("Beoltasra kerult az egyes gyereknel:\n");
                    printPerson(&tmp1[i]);
                    persons_to_send[i] = tmp1[i];
                    ++signal_person_list.vaccinatedCounter;
                }
                else
                {
                    printf("Sajnos nem kerult beoltasra:\n");
                    printPerson(&tmp1[i]);
                }
            }
            
            printf("Osszesen %d ember kerult ma beoltasra az elso gyereknel!\n", signal_person_list.vaccinatedCounter);
            printf("Az elso gyerek visszakuldi az adatokat a szulonek!\n");
            sleep(1);
            write(pipefd3[1], &persons_to_send, person_number_1 * sizeof(Person));
            close(pipefd3[1]);
            exit(0);
        }
    }
    
    if(signal_person_list.counter < 4)
    {
        printf("Nincs elegendo ember a vakcinaciohoz, igy ma nem indul busz!\n");
    }
}
