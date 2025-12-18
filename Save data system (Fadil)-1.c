void loadData() {
    FILE *fp = fopen("save_data.txt", "r");
    if (fp == NULL) return;
    fruitCount = 0;
    while (fscanf(fp, "%s %d %d", fruits[fruitCount].name,
                  &fruits[fruitCount].stock,
                  &fruits[fruitCount].price) != EOF) {
        fruitCount++;
    }
    fclose(fp);
}

void saveData() {
    FILE *fp = fopen("save_data.txt", "w");
    for (int i = 0; i < fruitCount; i++) {
        fprintf(fp, "%s %d %d\n", fruits[i].name,
                fruits[i].stock,
                fruits[i].price);
    }
    fclose(fp);
}

void resetData() {
    fruitCount = 0;
    FILE *fp = fopen("save_data.txt", "w");
    fclose(fp);
    printf("Data buah direset!\n");
}

loadData();
saveData();

case 5: resetData(); break;

 printf("5. Reset Data\n");

  printf("4. Save Data\n");

  case 4: saveData(); printf("Data disimpan!\n"); break;
