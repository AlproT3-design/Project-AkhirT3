#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data buah
struct Fruit {
    char name[50];
    int stock;
};

// Fungsi untuk menukar dua buah
void swap(struct Fruit *a, struct Fruit *b) {
    struct Fruit temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi bubble sort untuk mengurutkan berdasarkan stok ascending
void sortFruits(struct Fruit fruits[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (fruits[j].stock > fruits[j + 1].stock) {
                swap(&fruits[j], &fruits[j + 1]);
            }
        }
    }
}

// Fungsi utama
int main() {
    // Contoh data buah
    struct Fruit fruits[] = {
        {"Apel", 10},
        {"Jeruk", 5},
        {"Pisang", 20},
        {"Mangga", 15}
    };
    int n = sizeof(fruits) / sizeof(fruits[0]);

    // Tampilkan stok sebelum sorting
    printf("Stok buah sebelum sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", fruits[i].name, fruits[i].stock);
    }

    // Lakukan sorting
    sortFruits(fruits, n);

    // Tampilkan stok setelah sorting
    printf("\nStok buah setelah sorting (ascending berdasarkan stok):\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", fruits[i].name, fruits[i].stock);
    }

    return 0;
}
