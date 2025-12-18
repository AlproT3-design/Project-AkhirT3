void tugasBilqhis2() {
    if (jumlahBuah == 0) {
        printf("Belum ada data buah.\n");
        return;
    }

    for (int i = 0; i < jumlahBuah; i++) {
        printf("%d. [%s] %s | Stok: %d | Harga: %.2f\n",
               i+1,
               daftarBuah[i].kode,
               daftarBuah[i].nama,
               daftarBuah[i].stok,
               daftarBuah[i].harga);
    }
}


//agar data terimpan

int main() {
    int pilihan;
    loadData();
    printf("\nDATA YANG TERSIMPAN:\n");
    tugasBilqhis2();
    getchar();
