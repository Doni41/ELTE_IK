void Sort_Z (int* z, int meret1) { 
    // z TOMB RENDEZESE
   for (int i = meret1 - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (z [j] > z [j + 1]) {
                int temp = z [j];
                z [j] = z [j + 1];
                z [j + 1] = temp;
            }
        }
    }
}