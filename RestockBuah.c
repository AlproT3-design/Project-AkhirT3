// Done by Farrel

int main() {
    char runoutbuah[] = "apel";  // contoh buah habis
    char waLink[300];

    sprintf(waLink, "start https://wa.me/6283107582920?text=Halo%%2C%%20stok%%20buah%%20%s%%20telah%%20habis%%2C%%20mohon%%20restock.", runoutbuah);

    system(waLink);

    return 0;
}

