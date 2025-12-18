void ghiyatsSortirNama() {
    if (fruitCount < 2) {
        printf("\nTidak perlu diurutkan.\n");
        return;
    }

    for (int i = 0; i < fruitCount - 1; i++) {
        for (int j = 0; j < fruitCount - i - 1; j++) {
            if (strcmp(fruits[j].name, fruits[j + 1].name) > 0) {
                Fruit temp = fruits[j];
                fruits[j] = fruits[j + 1];
                fruits[j + 1] = temp;
            }
        }
    }

    printf("\nData buah diurutkan berdasarkan nama (A → Z).\n");
}
