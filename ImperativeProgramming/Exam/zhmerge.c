void merge (int* s, int* z, int* sz, int n1, int n2) {
    int i = 0;
    int j = 0;
    for (int k = 0; k < n1 + n2; ++k) {
        if (i < n1 && (j >= n2 || s [i] <= z [j])) {
            sz [k] = s [i];
            i++;
        }
        else {
            sz [k] = z [j];
            j++;
        }
    }
}