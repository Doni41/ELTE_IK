void jobbshift (int* arr, int meret) {
    int temp = arr [9];
    for (int i = meret; i >= 0; --i) {
        arr [i + 1] = arr [i];
    }
    arr [0] = temp;
}