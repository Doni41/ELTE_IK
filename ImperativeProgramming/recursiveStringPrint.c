#include <stdio.h>
#include <stdlib.h>

// STRING KIIRATASA REKURZIV MODON
// ELORE - HATRA KIIRATASA EGY STRINGNEK

// ELORE KIIRATAS

void elore (char* sztring) {
    if (*sztring == '\0') {
        return;
    }
    putchar (*sztring);
    elore(sztring + 1);
}

void hatra (char* sztring) {
    if (*sztring == '\0') {
        return;
    }
    hatra(sztring + 1);
    putchar(*sztring);
}

int main () {
    char* sztring = "HEGYESI AKOS";

    elore(sztring);
    printf("\n");
    printf("%s\n", sztring);

    hatra(sztring);
    printf("\n");
    printf("%s\n", sztring);

    return 0;
}