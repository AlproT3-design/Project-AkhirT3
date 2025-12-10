#include <stdio.h>

typedef struct {
    int id;
    char nama[32];
    int stok;
    int minStok;
} Buah;

void cekStok(const Buah *daftar, size_t n) {
    printf("=== Laporan Stok Buah ===\n");
    for (size_t i = 0; i < n; i++) {
        if (daftar[i].stok == 0) {
            printf("%s | Stok: %d | Status: HABIS\n", daftar[i].nama, daftar[i].stok);
        } else if (daftar[i].stok < daftar[i].minStok) {
            printf("%s | Stok: %d | Status: RENDAH (ambang %d)\n",
                   daftar[i].nama, daftar[i].stok, daftar[i].minStok);
        } else {
            printf("%s | Stok: %d | Status: AMAN\n", daftar[i].nama, daftar[i].stok);
        }
    }
}

int main() {
    Buah stok[] = {
        {1, "Apel", 0, 10},
        {2, "Pisang", 5, 10},
        {3, "Jeruk", 20, 10}
    };
    size_t n = sizeof(stok)/sizeof(stok[0]);

    cekStok(stok, n);
    return 0;
}
