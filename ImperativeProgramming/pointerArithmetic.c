// FGV KAP EGY POINTERT, AMI INTEKRE MUTAT, ES KIIRJA AZ ERTEKEIT FORDITVA
#include <stdio.h>


void ptr (int* arr, int meret) {
    printf ("Tomb kiir a rendes sorrendben\n");
    for (int* p = arr; p != arr + meret - 1; ++p) {
        printf ("%d ", *p);
    }

    printf ("\n");

    printf ("Tomb kiir forditott sorrendben\n");
    for (int* p = arr; p != arr + meret - 1; --p) {
        printf ("%d ", *p);
    }

    printf ("\n");
}

int main () {

    int arr [] = {1, 2 , 3 , 4 , 5 , 6};

    void ptr(arr, 6);

    return 0;
}