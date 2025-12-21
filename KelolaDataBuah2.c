void tugasWulan1() {
    char kode[10];
    printf("Kode buah: ");
    scanf("%s", kode);

    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kode) == 0) {

            getchar(); // bersihkan buffer newline
            printf("Nama baru  : ");
            fgets(daftarBuah[i].nama,
                   sizeof(daftarBuah[i].nama),
                   stdin);

            // hapus newline
            daftarBuah[i].nama[
                strcspn(daftarBuah[i].nama, "\n")
            ] = '\0';

            printf("Stok baru  : ");
            scanf("%d", &daftarBuah[i].stok);

            printf("Harga baru : ");
            scanf("%f", &daftarBuah[i].harga);

            printf("Data diperbarui.\n");
            saveData();
            return;
        }
    }

    printf("Buah tidak ditemukan.\n");
}


void tugasWulan2() {
    char kodeHapus[10];
    int found = -1;

    printf("\n=== Hapus Buah ===\n");
    printf("Masukkan kode buah yang akan dihapus: ");
    scanf("%s", kodeHapus);

    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kodeHapus) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Buah tidak ditemukan!\n");
        return;
    }

    for (int i = found; i < jumlahBuah - 1; i++) {
        daftarBuah[i] = daftarBuah[i + 1];
    }

    jumlahBuah--;
    printf("Buah berhasil dihapus!\n");
}

