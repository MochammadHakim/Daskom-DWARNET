#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    int jumlah;
    float harga;
    char status[20]; // Menambahkan status pesanan
} Pesanan;
void tambah_pesanan() {
    FILE *file = fopen("pesanan.dat", "ab");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    Pesanan pesanan;
    printf("Masukkan nama makanan: ");
    fgets(pesanan.nama, sizeof(pesanan.nama), stdin);
    pesanan.nama[strcspn(pesanan.nama, "\n")] = 0;  // Menghilangkan newline

    printf("Masukkan jumlah: ");
    scanf("%d", &pesanan.jumlah);
    getchar();  // Mengonsumsi newline yang tersisa

    printf("Masukkan harga: ");
    scanf("%f", &pesanan.harga);
    getchar();  // Mengonsumsi newline yang tersisa

    strcpy(pesanan.status, "ongoing"); // Set status as "ongoing"

    fwrite(&pesanan, sizeof(Pesanan), 1, file);
    fclose(file);

    printf("Pesanan berhasil ditambahkan dengan status 'ongoing'!\n");
}
void lihat_status_pesanan() {
    FILE *file = fopen("pesanan.dat", "rb");
    if (file == NULL) {
        printf("Gagal membuka file atau belum ada pesanan.\n");
        return;
    }

    Pesanan pesanan;
    printf("== Daftar Pesanan ==\n");
    while (fread(&pesanan, sizeof(Pesanan), 1, file)) {
        printf("Nama Makanan: %s\n", pesanan.nama);
        printf("Jumlah: %d\n", pesanan.jumlah);
        printf("Harga: %.2f\n", pesanan.harga);
        printf("Status: %s\n", pesanan.status);
        printf("---------------------\n");
    }

    fclose(file);
}
void bayar_pesanan() {
    FILE *file = fopen("pesanan.dat", "rb+");
    if (file == NULL) {
        printf("Gagal membuka file atau belum ada pesanan.\n");
        return;
    }

    Pesanan pesanan;
    int found = 0;
    long pos;

    printf("Masukkan nama makanan yang ingin dibayar: ");
    char nama_makanan[50];
    fgets(nama_makanan, sizeof(nama_makanan), stdin);
    nama_makanan[strcspn(nama_makanan, "\n")] = 0;  // Menghilangkan newline

    while (fread(&pesanan, sizeof(Pesanan), 1, file)) {
        if (strcmp(pesanan.nama, nama_makanan) == 0 && strcmp(pesanan.status, "ongoing") == 0) {
            found = 1;
            pos = ftell(file) - sizeof(Pesanan);
            fseek(file, pos, SEEK_SET);
            strcpy(pesanan.status, "dibayar");
            fwrite(&pesanan, sizeof(Pesanan), 1, file);
            printf("Status pesanan '%s' telah diubah menjadi 'dibayar'.\n", pesanan.nama);
            break;
        }
    }

    if (!found) {
        printf("Pesanan dengan nama '%s' tidak ditemukan atau sudah dibayar.\n", nama_makanan);
    }

    fclose(file);
}
int main_user() {
    int pilihan;
    do {
        printf("==Menu User== \n 1. Pilih Game \n 2. Beli Makanan \n 3. Beli Minuman \n 4. Lihat Status Pesanan \n 5. Bayar Pesanan \n 6. Logout \n Pilihan: ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan) {
            case 1:
                system("cls");
                // game();  // Pastikan fungsi game diimplementasikan
                break;

            case 2:
                system("cls");
                tambah_pesanan();
                break;
            case 3:
                system("cls");
                // minuman();  // Pastikan fungsi minuman diimplementasikan
                break;

            case 4:
                system("cls");
                lihat_status_pesanan();
                break;

            case 5:
                system("cls");
                bayar_pesanan();
                break;

            case 6:
                system("cls");
                // Logout atau kembali ke fungsi utama
                break;

            default:
                printf("Opsi Tidak Tersedia!\n");
                break;
        }
    } while (pilihan != 6);

    return 0;
}
int main() {
    main_user();
    return 0;
}
