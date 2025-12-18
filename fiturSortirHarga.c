void ghiyatsSortirHarga() {
    if (fruitCount < 2) {
        printf("\nTidak perlu diurutkan.\n");
        return;
    }

    for (int i = 0; i < fruitCount - 1; i++) {
        for (int j = 0; j < fruitCount - i - 1; j++) {
            if (fruits[j].price_per_kg > fruits[j+1].price_per_kg) {
                Fruit temp = fruits[j];
                fruits[j] = fruits[j+1];
                fruits[j+1] = temp;
            }
        }
    }

    printf("\nData buah diurutkan berdasarkan harga (termurah → termahal).\n");
}
