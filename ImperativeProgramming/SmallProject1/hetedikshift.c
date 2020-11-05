void shift (int* arr, int meret) {
    int temp = arr [0];
    // BALRA SHIFTELI A TOMBOT 
    for (int i = 0; i < meret; ++i) {
        arr [i] = arr [i + 1];
    }
    arr [9] = temp; 
}