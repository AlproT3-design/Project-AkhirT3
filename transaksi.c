#include <stdio.h>
#include "fruit.h"

void sellFruit() {
    int id, qty;
    showFruits();

    printf("\nMasukkan ID buah yang ingin dibeli: ");
    scanf("%d", &id);

    int index = findFruitIndex(id);
    if(index == -1){
        printf("Buah tidak ditemukan!\n");
        return;
    }

    printf("Masukkan jumlah pembelian: ");
    scanf("%d", &qty);

    if(qty > fruits[index].stock){
        printf("Stok tidak mencukupi! Stok tersedia: %d\n",
               fruits[index].stock);
        return;
    }

    float total = qty * fruits[index].price;
    fruits[index].stock -= qty;

    printf("\n=== TRANSAKSI BERHASIL ===\n");
    printf("Buah   : %s\n", fruits[index].name);
    printf("Jumlah : %d\n", qty);
    printf("Total  : Rp %.2f\n", total);
}
