#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR_CMD "cls"
#else
#include <unistd.h>
#define CLEAR_CMD "clear"
#endif

#define MAX_FRUITS 200
#define NAME_LEN 64
#define FILE_FRUITS "fruits.csv"
#define FILE_TRANSACTIONS "transactions.csv"

// ANSI color codes (works on most Unix terminals; Windows 10+ supports ANSI too)
#define COL_RESET "\x1b[0m"
#define COL_RED "\x1b[31m"
#define COL_GREEN "\x1b[32m"
#define COL_YELLOW "\x1b[33m"
#define COL_BLUE "\x1b[34m"
#define COL_MAGENTA "\x1b[35m"
#define COL_CYAN "\x1b[36m"
#define COL_BOLD "\x1b[1m"

int main() {
    printf(COL_GREEN COL_BOLD);
    printf("==========================================\n");
    printf("         WELCOME TO TOKO BUAH CLI  \n");
    printf("==========================================\n");
    printf(COL_YELLOW "Author: Team 3 Alpro - Last Project CLI" COL_RESET "\n\n");

}
