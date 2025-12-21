void tugasBilqhis1() {
    char kodeInput[20];
    int found = -1;

    printf("\n=== Tambah Buah Baru ===\n");
    printf("Kode  : ");
    scanf("%s", kodeInput);

    // cek apakah kode sudah ada
    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kodeInput) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Buah dengan kode '%s' sudah ada. Tidak ada perubahan stok.\n", kodeInput);
        return;
    }

    // Buah baru → input data
    strcpy(daftarBuah[jumlahBuah].kode, kodeInput);

    getchar(); // bersihkan sisa newline dari scanf
    printf("Nama  : ");
    fgets(daftarBuah[jumlahBuah].nama,
           sizeof(daftarBuah[jumlahBuah].nama),
           stdin);

    // hapus karakter newline
    daftarBuah[jumlahBuah].nama[
        strcspn(daftarBuah[jumlahBuah].nama, "\n")
    ] = '\0';

    int stokInput;
    do {
        printf("Stok  : ");
        scanf("%d", &stokInput);
        if (stokInput < 0) {
            printf("Stok tidak boleh negatif!\n");
        }
    } while (stokInput < 0);
    daftarBuah[jumlahBuah].stok = stokInput;

    float hargaInput;
    do {
        printf("Harga : ");
        scanf("%f", &hargaInput);
        if (hargaInput < 0) {
            printf("Harga tidak boleh negatif!\n");
        }
    } while (hargaInput < 0);
    daftarBuah[jumlahBuah].harga = hargaInput;

    jumlahBuah++;
    printf("Buah baru berhasil ditambahkan!\n");
    saveData();
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



