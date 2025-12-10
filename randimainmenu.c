#include <stdio.h>
#define RESET   "\033[0m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define RED     "\033[1;31m"

// Menu utama
void displayMainMenu() {
    int mainMenu;
    
    do {
        printf(BLUE"============================================\n" RESET);
        printf(RED"      SISTEM PENGELOLAAN STOK BUAH UMKM\n" RESET);
        printf(BLUE"============================================\n");
        printf("============================================\n" RESET);
        printf("Total Buah     : %d item\n",\\tambahin variable totalbuah);
        printf("Total Transaksi: %d transaksi\n", \\tambahin variable totaltransaksi);
        printf("============================================\n");
        printf(RED"MENU UTAMA:\n"RESET);
        printf("1. Kelola Data Buah\n");
        printf("2. Transaksi Penjualan\n");
        printf("3. Pencarian & Pengurutan\n");
        printf("4. Manajemen Stok\n");
        printf("5. Pengaturan Sistem\n");
        printf("0. Keluar\n");
        printf(BLUE"============================================\n"RESET);
        printf(RED"%sPilihan Anda: %s", RESET);
        
        scanf("%d", &mainMenu);
        
        if (mainMenu == 1) { 
            //tambah fungsi fitur 1 ();
        } 
        else if (mainMenu == 2) {
            //tambah fungsi fitur 2(); 
        }
        else if (mainMenu == 3) {
            //tambah fungsi fitur 3(); 
        }
        else if (mainMenu == 4) {
            //tambah fungsi fitur 4(); 
        }
        else if (mainMenu == 5) {
            //tambah fungsi fitur 5(); 
        }
        else if (mainMenu == 0): {
                printf("Pilihan tidak valid! Tekan Enter...");
        }   
    } while (mainMenu != 0);
    return 0 ;
}