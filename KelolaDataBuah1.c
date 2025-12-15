void tugasBilqhis1() {
    printf("\n=== Tambah Buah Baru ===\n");
    printf("Kode  : ");
    scanf("%s", daftarBuah[jumlahBuah].kode);

    printf("Nama  : ");
    scanf("%s", daftarBuah[jumlahBuah].nama);

    printf("Stok  : ");
    scanf("%d", &daftarBuah[jumlahBuah].stok);

    printf("Harga : ");
    scanf("%f", &daftarBuah[jumlahBuah].harga);

    jumlahBuah++;
    printf("Buah berhasil ditambahkan!\n");
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
