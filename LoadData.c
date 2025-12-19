// Done by Farrel

void loadData() {
    FILE *fp = fopen("data.bin", "rb");
    if (fp == NULL) return;

    fread(&jumlahBuah, sizeof(int), 1, fp);
    fread(daftarBuah, sizeof(Buah), jumlahBuah, fp);

    fread(&jumlahRiwayat, sizeof(int), 1, fp);
    fread(riwayat, sizeof(Transaksi), jumlahRiwayat, fp);

    fread(&totalTransaksi, sizeof(int), 1, fp);

    fclose(fp);
}
