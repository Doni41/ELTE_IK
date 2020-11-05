int MostFrequent (int* arr, int meret) {
    int max_szamlalo = 1;
    int elso = arr [0];
    int aktual_szamlalo = 1;

    for (int i = 1; i < meret; ++i) {
        if (arr [i] == arr [i -1]) {
            aktual_szamlalo++;
        }
        else {
            if ( aktual_szamlalo > max_szamlalo) {
                max_szamlalo = aktual_szamlalo;
                elso = arr [i -1];
            }
            aktual_szamlalo = 1;
        }
        // HA AZ UTOLSO ELEM A LEGGYAKRABBAN ELOFORDULO
        if (aktual_szamlalo > max_szamlalo) {
            max_szamlalo = aktual_szamlalo;
            elso = arr [meret - 1];
        }
    }
    return elso;      
}