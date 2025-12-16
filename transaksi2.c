void sellFruit() {
    char kodeTransaksi[10];
    int found = -1;
    int jumlah;
    int lanjut = 1;

    float totalSemua = 0;

    printf("\n=== Transaksi Jual Buah ===\n");

    while (lanjut == 1) {
        printf("\nMasukkan kode buah: ");
        scanf("%s", kodeTransaksi);

        // cari buah
        for (int i = 0; i < jumlahBuah; i++) {
            if (strcmp(daftarBuah[i].kode, kodeTransaksi) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("Buah tidak ditemukan!\n");
            return;
        }

        printf("Nama buah : %s\n", daftarBuah[found].nama);
        printf("Stok tersedia : %d\n", daftarBuah[found].stok);

        printf("Jumlah yang ingin dibeli: ");
        scanf("%d", &jumlah);

        if (jumlah > daftarBuah[found].stok) {
            printf("Stok tidak mencukupi!\n");
            return;
        }

        // hitung subtotal
        float subtotal = jumlah * daftarBuah[found].harga;

        // kurangi stok
        daftarBuah[found].stok -= jumlah;

        // tambahkan ke total transaksi
        totalSemua += subtotal;

        printf("\n--- Detail Pembelian ---\n");
        printf("Buah     : %s\n", daftarBuah[found].nama);
        printf("Jumlah   : %d\n", jumlah);
        printf("Subtotal : %.2f\n", subtotal);

        // reset found untuk transaksi berikutnya
        found = -1;

        printf("\nTambah buah lain? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);
    }

    printf("\nTotal pembayaran: Rp %.2f\n", totalSemua);
    printf("Terima kasih!\n");
} 