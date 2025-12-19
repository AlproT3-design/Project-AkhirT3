// Done by Farrel

void resetData() {
    jumlahBuah = 0;
    jumlahRiwayat = 0;
    totalTransaksi = 0;

    FILE *fp = fopen("data.bin", "wb");
    if (fp != NULL) fclose(fp);

    printf("SEMUA DATA BERHASIL DIRESET.\n");
}


    printf("Sesudah reset: %s stok %d\n", fruits[0].name, fruits[0].stock);

    return 0;
}
