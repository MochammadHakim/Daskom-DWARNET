#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menghapus entri tertentu dari file
void hapusEntri(const char *namaFile, const char *username) {
    FILE *fileInput = fopen(namaFile, "r");
    if (fileInput == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    // Membuka file temporary untuk menulis sementara
    FILE *fileTemp = fopen("temp.txt", "w");
    if (fileTemp == NULL) {
        printf("Gagal membuka file temporary.\n");
        fclose(fileInput);
        return;
    }

    char buffer[256];
    int deleted = 0;

    // Membaca setiap baris dari fileInput
    while (fgets(buffer, sizeof(buffer), fileInput)) {
        // Memisahkan username dari baris yang dibaca
        char *token = strtok(buffer, " ");
        if (token != NULL && strcmp(token, username) != 0) {
            // Jika username bukan yang ingin dihapus, menulis baris ke file temporary
            if (deleted)
                fprintf(fileTemp, " %s", buffer);
            else {
                fprintf(fileTemp, "%s", buffer);
                deleted = 1;
            }
        }
    }

    // Menutup file
    fclose(fileInput);
    fclose(fileTemp);

    // Menghapus file asli
    remove(namaFile);

    // Mengganti nama file temporary menjadi nama file asli
    rename("temp.txt", namaFile);

    printf("Entri dengan username %s telah dihapus.\n", username);
}

int main() {
    // Panggil fungsi hapusEntri dengan parameter nama file dan username yang ingin dihapus
    hapusEntri("user.txt", "we");

    return 0;
}
