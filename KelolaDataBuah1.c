void tugasBilqhis1() {
    char kodeInput[20];
    int found = -1;

    printf("\n=== Tambah Buah Baru ===\n");
    printf("Kode  : ");
    scanf("%s", kodeInput);

    // Cek apakah kode sudah ada
    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kodeInput) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        // Jika buah sudah ada
        int tambahStok;
        printf("Buah sudah ada!\n");
        printf("Tambah stok: ");
        scanf("%d", &tambahStok);

        daftarBuah[found].stok += tambahStok;
        printf("Stok berhasil diperbarui!\n");
    } else {
        // Jika buah belum ada
        strcpy(daftarBuah[jumlahBuah].kode, kodeInput);

        printf("Nama  : ");
        scanf("%s", daftarBuah[jumlahBuah].nama);

        printf("Stok  : ");
        scanf("%d", &daftarBuah[jumlahBuah].stok);

        printf("Harga : ");
        scanf("%f", &daftarBuah[jumlahBuah].harga);

        jumlahBuah++;
        printf("Buah baru berhasil ditambahkan!\n");
    }
}

void tugasBilqhis2() {
    printf("\n=== Daftar Buah ===\n");
    if (jumlahBuah == 0) {
        printf("Belum ada data buah.\n");
        return;
    }

    for (int i = 0; i < jumlahBuah; i++) {
        printf("%d. [%s] %s | Stok: %d | Harga: %.2f\n",
               i + 1,
               daftarBuah[i].kode,
               daftarBuah[i].nama,
               daftarBuah[i].stok,
               daftarBuah[i].harga);
    }

}

