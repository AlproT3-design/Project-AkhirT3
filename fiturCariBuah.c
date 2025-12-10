void searchFruit() {
    int key;
    printf("\nMasukkan ID buah yang dicari: ");
    scanf("%d", &key);

    int idx = sequentialSearchById(key);

    if (idx == -1) {
        printf("Buah tidak ditemukan.\n");
    } else {
        printf("\nBuah ditemukan:\n");
        printf("Nama: %s\nHarga: Rp%.2f/kg\nStok: %.2f kg\n",
               fruits[idx].name,
               fruits[idx].price_per_kg,
               fruits[idx].stock_kg);
    }
}