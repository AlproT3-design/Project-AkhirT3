#include <stdio.h>
#include <string.h>

#define MAX 50   // maksimal transaksi

// Struktur sederhana untuk transaksi
typedef struct {
    char fruit[30];
    int qty;
    float total;
} Transaction;

static Transaction list[MAX];
static int count = 0;

// Simpan transaksi
void saveTransaction(const char *fruitName, int qty, float total) {
    if (count < MAX) {
        strcpy(list[count].fruit, fruitName);
        list[count].qty = qty;
        list[count].total = total;
        count++;
    }
}

// Tampilkan riwayat
void showTransactionHistory() {
    printf("\n=== Riwayat Transaksi ===\n");
    if (count == 0) {
        printf("Belum ada transaksi.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d buah - Rp %.2f\n",
               i+1, list[i].fruit, list[i].qty, list[i].total);
    }
}

// Program utama
int main() {
    saveTransaction("Apel", 5, 25000);
    saveTransaction("Jeruk", 3, 18000);
    saveTransaction("Mangga", 2, 30000);

    showTransactionHistory();
    return 0;
}