void Sort_S (int* s, int meret2) {
    // s TOMB RENDEZESE
    for (int i = meret2 - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (s [j] > s [j + 1]) {
                int temp = s [j];
                s [j] = s [j + 1];
                s [j + 1] = temp;
            }
        }
    }
}
