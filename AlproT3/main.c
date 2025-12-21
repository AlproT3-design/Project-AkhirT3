#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ===== ANSI COLORS ===== */
#define RESET   "\x1b[0m"
#define BLUE    "\x1b[34m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RED     "\x1b[31m"

/* ===== CONSTANT ===== */
#define MAX_BUAH 100
#define MAX_TRANS 50

/* ===== STRUCT ===== */
typedef struct {
    char kode[10];
    char nama[50];
    int stok;
    float harga;
} Buah;

typedef struct {
    char namaBuah[50];
    int jumlah;
    float total;
} Transaksi;

/* ===== GLOBAL DATA ===== */
Buah daftarBuah[MAX_BUAH];
Transaksi riwayat[MAX_TRANS];

int jumlahBuah = 0;
int totalTransaksi = 0;
int jumlahRiwayat = 0;

void saveData();
void loadData();
void resetData();

/* ===== HEADER ===== */
void header() {
    printf(BLUE"============================================\n"RESET);
    printf(RED " SISTEM PENGELOLAAN STOK BUAH PANEN-BUAH-PWK\n"RESET);
    printf(BLUE"============================================\n"RESET);
    printf(CYAN "Total Buah     : " RESET "%d item\n", jumlahBuah);
    printf(CYAN "Total Transaksi: " RESET "%d transaksi\n", totalTransaksi);
    printf(BLUE"============================================\n"RESET);
}

/* ===== MENU 1 : CRUD BUAH ===== */
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
    char kode[10];
    printf("Kode buah: ");
    scanf("%s", kode);

    for (int i = 0; i < jumlahBuah; i++) {
        if (strcmp(daftarBuah[i].kode, kode) == 0) {
            for (int j = i; j < jumlahBuah - 1; j++)
                daftarBuah[j] = daftarBuah[j + 1];
            jumlahBuah--;
            printf("Buah dihapus.\n");
            return;
        }
    }
    printf("Buah tidak ditemukan.\n");
    saveData();
}

/* ===== MENU 2 : TRANSAKSI ===== */
void tugasGregorius1() {
    char kode[10];
    int jumlah, lanjut = 1;
    float totalBayar = 0;

    while (lanjut == 1) {
        int idx = -1;
        printf("Kode buah: ");
        scanf("%s", kode);

        for (int i = 0; i < jumlahBuah; i++)
            if (strcmp(daftarBuah[i].kode, kode) == 0)
                idx = i;

        if (idx == -1) {
            printf("Buah tidak ditemukan.\n");
            return;
        }

        printf("Jumlah beli: ");
        scanf("%d", &jumlah);

        if (jumlah <= 0 || jumlah > daftarBuah[idx].stok) {
            printf("Jumlah tidak valid.\n");
            return;
        }

        float sub = jumlah * daftarBuah[idx].harga;
        daftarBuah[idx].stok -= jumlah;
        totalBayar += sub;

        strcpy(riwayat[jumlahRiwayat].namaBuah, daftarBuah[idx].nama);
        riwayat[jumlahRiwayat].jumlah = jumlah;
        riwayat[jumlahRiwayat].total = sub;
        jumlahRiwayat++;

        printf("Subtotal: %.2f\n", sub);
        printf("Tambah buah lain? (1=ya, 0=tidak): ");
        scanf("%d", &lanjut);
    }

    totalTransaksi++;
    printf("TOTAL BAYAR: %.2f\n", totalBayar);
    saveData();
}

void tampilRiwayat() {
    if (jumlahRiwayat == 0) {
        printf("Belum ada transaksi.\n");
        return;
    }

    for (int i = 0; i < jumlahRiwayat; i++) {
        printf("%d. %s - %d buah - Rp %.2f\n",
               i+1,
               riwayat[i].namaBuah,
               riwayat[i].jumlah,
               riwayat[i].total);
    }
}

/* ===== MENU 3 : SEARCH & SORT ===== */
int searchByKode(char key[]) {
    for (int i = 0; i < jumlahBuah; i++)
        if (strcmp(daftarBuah[i].kode, key) == 0)
            return i;
    return -1;
}

void tugasGhiyats1() {
    char key[10];
    printf("Masukkan kode buah: ");
    scanf("%s", key);

    int idx = searchByKode(key);
    if (idx == -1)
        printf("Buah tidak ditemukan.\n");
    else
        printf("Nama: %s | Stok: %d | Harga: %.2f\n",
               daftarBuah[idx].nama,
               daftarBuah[idx].stok,
               daftarBuah[idx].harga);
}

void sortNama() {
    for (int i = 0; i < jumlahBuah - 1; i++)
        for (int j = 0; j < jumlahBuah - i - 1; j++)
            if (strcmp(daftarBuah[j].nama, daftarBuah[j+1].nama) > 0) {
                Buah t = daftarBuah[j];
                daftarBuah[j] = daftarBuah[j+1];
                daftarBuah[j+1] = t;
            }
}

void sortHarga() {
    for (int i = 0; i < jumlahBuah - 1; i++)
        for (int j = 0; j < jumlahBuah - i - 1; j++)
            if (daftarBuah[j].harga > daftarBuah[j+1].harga) {
                Buah t = daftarBuah[j];
                daftarBuah[j] = daftarBuah[j+1];
                daftarBuah[j+1] = t;
            }
}

void sortStok() {
    for (int i = 0; i < jumlahBuah - 1; i++)
        for (int j = 0; j < jumlahBuah - i - 1; j++)
            if (daftarBuah[j].stok > daftarBuah[j+1].stok) {
                Buah t = daftarBuah[j];
                daftarBuah[j] = daftarBuah[j+1];
                daftarBuah[j+1] = t;
            }
}

/* ===== MENU 4 : WHATSAPP ===== */
void hubungiSupplier() {
    char namaBuah[50];
    char waLink[300];

    printf("Nama buah: ");
    scanf("%s", namaBuah);

    sprintf(
        waLink,
        "start https://wa.me/6283107582920?text=Halo%%2C%%20stok%%20buah%%20%s%%20telah%%20habis%%2C%%20mohon%%20restock.",
        namaBuah
    );

    system(waLink);
}

/* ===== MENU 5 : RESET DATA ===== */
void resetData() {
    jumlahBuah = 0;
    jumlahRiwayat = 0;
    totalTransaksi = 0;

    FILE *fp = fopen("data.bin", "wb");
    if (fp != NULL) fclose(fp);

    printf("SEMUA DATA BERHASIL DIRESET.\n");
}

/* DATA SAVE PERMANEN VIA BINARY */
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

/* LOAD DATA OTOMATIS YEUH MANTAB */
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


/* ===== MAIN ===== */
int main() {
    loadData();

    int pilihan;

    do {
        system("cls");
        header();

        printf(YELLOW"MENU UTAMA\n"RESET);
        printf(GREEN"1. "RESET"Kelola Data Buah\n");
        printf(GREEN"2. "RESET"Transaksi Penjualan\n");
        printf(GREEN"3. "RESET"Pencarian & Pengurutan\n");
        printf(GREEN"4. "RESET"Hubungi Supplier\n");
        printf(GREEN"5. "RESET"RESET DATA!\n");
        printf(RED  "0. "RESET"Keluar\n");
        printf(YELLOW"Pilihan: "RESET);
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            int sub;
            do {
                system("cls"); header();
                printf(YELLOW"KELOLA DATA BUAH\n"RESET);
                printf(GREEN"1. "RESET"Tambah Buah\n");
                printf(GREEN"2. "RESET"Tampilkan Semua Buah\n");
                printf(GREEN"3. "RESET"Edit Data Buah\n");
                printf(GREEN"4. "RESET"Hapus Buah\n");
                printf(RED  "0. "RESET"Kembali\n");
                printf(YELLOW"Pilihan: "RESET);
                scanf("%d", &sub);

                system("cls"); header();
                if (sub == 1) tugasBilqhis1();
                else if (sub == 2) tugasBilqhis2();
                else if (sub == 3) tugasWulan1();
                else if (sub == 4) tugasWulan2();

                if (sub != 0) { printf("\nTekan Enter..."); getchar(); getchar(); }
            } while (sub != 0);
        }

        if (pilihan == 2) {
            int sub2;
            do {
                system("cls"); header();
                printf(YELLOW"TRANSAKSI PENJUALAN\n"RESET);
                printf(GREEN"1. "RESET"Buat Transaksi\n");
                printf(GREEN"2. "RESET"Riwayat Transaksi\n");
                printf(RED  "0. "RESET"Kembali\n");
                printf(YELLOW"Pilihan: "RESET);
                scanf("%d", &sub2);

                system("cls"); header();
                if (sub2 == 1) tugasGregorius1();
                else if (sub2 == 2) tampilRiwayat();

                if (sub2 != 0) { printf("\nTekan Enter..."); getchar(); getchar(); }
            } while (sub2 != 0);
        }

        if (pilihan == 3) {
            int sub3;
            do {
                system("cls"); header();
                printf(YELLOW"PENCARIAN & PENGURUTAN\n"RESET);
                printf(GREEN"1. "RESET"Cari Buah\n");
                printf(GREEN"2. "RESET"Urutkan Buah\n");
                printf(RED  "0. "RESET"Kembali\n");
                printf(YELLOW"Pilihan: "RESET);
                scanf("%d", &sub3);

                system("cls"); header();
                if (sub3 == 1) tugasGhiyats1();
                else if (sub3 == 2) {
                    int s;
                    printf(YELLOW"URUTKAN BUAH\n"RESET);
                    printf(GREEN"1. "RESET"Nama\n");
                    printf(GREEN"2. "RESET"Harga\n");
                    printf(GREEN"3. "RESET"Stok\n");
                    printf(RED  "0. "RESET"Kembali\n");
                    printf(YELLOW"Pilihan: "RESET);
                    scanf("%d", &s);

                    if (s == 1) sortNama();
                    else if (s == 2) sortHarga();
                    else if (s == 3) sortStok();

                    if (s != 0) tugasBilqhis2();
                }

                if (sub3 != 0) { printf("\nTekan Enter..."); getchar(); getchar(); }
            } while (sub3 != 0);
        }

        if (pilihan == 4) {
            system("cls"); header();
            hubungiSupplier();
            printf("\nTekan Enter...");
            getchar(); getchar();
        }

        if (pilihan == 5) {
    char konfirmasi;
    system("cls");
    header();

    printf(RED"Anda Yakin? Hal ini akan menghapus SELURUH data Aplikasi! (y/n)\n-->> "RESET);
    scanf(" %c", &konfirmasi);

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        resetData();
    } else {
        printf("Reset dibatalkan.\n");
    }

    printf("\nTekan Enter...");
    getchar(); getchar();
}


    } while (pilihan != 0);

    return 0;
}
