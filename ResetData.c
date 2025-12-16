#include <stdio.h>
#include <string.h>

#define MAX_FRUITS 50
typedef struct {
    char name[30];
    int stock;
    int price;
    int sold;
} Fruit;

Fruit fruits[MAX_FRUITS];
int fruitCount = 0;

void tugasFarrel() {
    for (int i = 0; i < MAX_FRUITS; i++) {
        strcpy(fruits[i].name, "");
        fruits[i].stock = 0;
        fruits[i].price = 0;
        fruits[i].sold = 0;
    }
    fruitCount = 0; 
    printf("\n=== Semua data sudah direset! ===\n\n");
}

int main() {
    strcpy(fruits[0].name, "Apel");
    fruits[0].stock = 10;
    fruits[0].price = 5000;
    fruits[0].sold = 2;
    fruitCount = 1;

    printf("Sebelum reset: %s stok %d\n", fruits[0].name, fruits[0].stock);

    resetData();

    printf("Sesudah reset: %s stok %d\n", fruits[0].name, fruits[0].stock);

    return 0;
}
