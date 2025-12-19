// Done by Fadil, reconstruct by Farrel. Direkonstruksi kode agar sesuai dengan main code structure. Saya rubah dari txt ke binary untuk alasan keamanan.

void saveData() {
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) return;

    fwrite(&jumlahBuah, sizeof(int), 1, fp);
    fwrite(daftarBuah, sizeof(Buah), jumlahBuah, fp);

    fwrite(&jumlahRiwayat, sizeof(int), 1, fp);
    fwrite(riwayat, sizeof(Transaksi), jumlahRiwayat, fp);

    fwrite(&totalTransaksi, sizeof(int), 1, fp);

    fclose(fp);
}
