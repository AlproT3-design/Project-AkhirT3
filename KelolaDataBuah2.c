#include <stdio.h>
#include <string.h>

void tugasWulan1() {
    char kodeEdit[10];
    int found = -1;

    printf("\n=== Edit Data Buah ===\n");
    printf("Masukkan kode buah yang ingin diedit: ");
    scanf("%s", kodeEdit);

    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kodeEdit) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Buah dengan kode tersebut tidak ditemukan!\n");
        return;
    }

    printf("Nama baru  : ");
    scanf("%s", daftarBuah[found].nama);

    printf("Stok baru  : ");
    scanf("%d", &daftarBuah[found].stok);

    printf("Harga baru : ");
    scanf("%f", &daftarBuah[found].harga);

    printf("Data buah berhasil diperbarui!\n");
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
