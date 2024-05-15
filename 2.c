#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char username_user[100];
    char password_user[100];
    int nomor_akun;
} user;

int login();
int daftar();
int login_user();
int login_admin();
int main_user();
int game();
int makanan();
int minuman();
int lihat_status_pesanan();
int playgame();
int main_admin();
int instalasi_game();
int manajemen_pc();
int manajemen_akun();
int penambahan_menu();
void cek_akun();

void announcement(){
    printf("Login Berhasil!\n");
}

int main(){
    int pilihan;
    printf("==Selamat Datang Di D'Warnet== \n 1. Login \n 2. Daftar \n 3. Keluar Program\n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan) {
    case 1:
        system("cls");
        login();
        break;
    
    case 2:
        system("cls");
        daftar();
        break;

    case 3:
        system("cls");
        cek_akun();
        return 0;
    
    default:
        system("cls");
        printf("Pilihan Tidak Valid!");
        break;
    }
}

int login(){
    int pilihan;
    printf("== Login == \n 1. User \n 2. Admin \n 3. Kembali \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan) {
    case 1:
        system("cls");
        login_user();
        break;
    
    case 2:
        system("cls");
        login_admin();
        break;
    
    case 3:
        system("cls");
        main();
        break;

    default:
        system("cls");
        printf("Opsi Tidak Tersedia!");
    }
}

int daftar() {
    FILE *file;
    user new_user;

    // Meminta input dari pengguna
    printf("== Daftar ==\n");
    printf("Masukkan Username: ");
    fgets(new_user.username_user, sizeof(new_user.username_user), stdin);
    new_user.username_user[strcspn(new_user.username_user, "\n")] = '\0';
    printf("Masukkan Password: ");
    fgets(new_user.password_user, sizeof(new_user.password_user), stdin);
    new_user.password_user[strcspn(new_user.password_user, "\n")] = '\0';

    // Buka file untuk membaca data pengguna yang sudah terdaftar
    file = fopen("user.dat", "rb");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    // Mencari nomor akun terakhir
    user temp_user;
    int last_account_number = 0;
    while (fread(&temp_user, sizeof(user), 1, file) == 1) {
        if (temp_user.nomor_akun > last_account_number) {
            last_account_number = temp_user.nomor_akun;
        }
    }
    fclose(file);

    // Menetapkan nomor akun baru
    new_user.nomor_akun = last_account_number + 1;

    // Menambahkan pengguna baru ke file
    file = fopen("user.dat", "ab");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }
    fwrite(&new_user, sizeof(user), 1, file);
    fclose(file);

    // Pemberitahuan registrasi berhasil
    printf("Registrasi Berhasil! Nomor Akun Anda adalah: %d\n", new_user.nomor_akun);
    return 0;
}


int login_user() {
    int i;
    char username_user[100];
    char password_user[100];

    for (i = 3; i > 0; i--) {
        FILE *file;
        user current_user;
        int found = 0;

        printf("== LOGIN USER ==\n");
        printf("Masukkan Username: ");
        fgets(username_user, sizeof(username_user), stdin);
        username_user[strcspn(username_user, "\n")] = '\0'; 
        printf("Masukkan Password: ");
        fgets(password_user, sizeof(password_user), stdin);
        password_user[strcspn(password_user, "\n")] = '\0';

        // Buka file untuk membaca data pengguna
        file = fopen("user.dat", "rb");
        if (file == NULL) {
            printf("Tidak dapat membuka file!\n");
            return 1;
        }

        // Baca setiap entri dalam file dan cocokkan dengan input pengguna
        while (fread(&current_user, sizeof(user), 1, file) == 1) {
            if (strcmp(username_user, current_user.username_user) == 0 &&
                strcmp(password_user, current_user.password_user) == 0) {
                found = 1;
                break;
            }
        }
        fclose(file);

        if (found) {
            system("cls");
            announcement();
            return main_user();
        } else if (i > 1) {
            system("cls");
            printf("Username Atau Password Salah!\n");
            printf("Kesempatan Login: %d\n", i-1);
        } else {
            system("cls");
            printf("Username Atau Password Salah!\n");
            printf("Kesempatan Login Habis!\n");
        }
    }
    return 1; // Kembalikan 1 jika login gagal
}

int login_admin(){
    printf(".");
}

int main_user(){
    printf(".");
}

int game(){
    printf(".");
}

int makanan(){
    printf(".");
    return 0;
}

int minuman(){
    printf(".");
    return 0;
}

int lihat_status_pesanan(){
    printf(".");
}

void cek_akun() {
    FILE *file;
    user temp_user;

    // Buka file untuk membaca data pengguna yang sudah terdaftar
    file = fopen("user.dat", "rb");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    printf("== Daftar Akun ==\n");
    printf("%s\t %s\t %s\n", "Nomor Akun", "Username", "Password");
    printf("--------------------------------------------------\n");

    // Membaca dan menampilkan detail setiap akun
    while (fread(&temp_user, sizeof(user), 1, file) == 1) {
        printf("%d\t\t %s\t\t %s\n", temp_user.nomor_akun, temp_user.username_user, temp_user.password_user);
    }

    fclose(file);
}

void hapus_akun(int nomor_akun_hapus) {
    FILE *file;
    FILE *temp_file;
    user temp_user;

    // Buka file untuk membaca data pengguna yang sudah terdaftar
    file = fopen("user.dat", "r+b");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    // Buka file temporary untuk menulis data yang akan disalin
    temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        printf("Gagal membuka file temporary!\n");
        fclose(file);
        return;
    }

    int found = 0;

    // Membaca dan menyalin data pengguna ke file temporary
    while (fread(&temp_user, sizeof(user), 1, file) == 1) {
        if (temp_user.nomor_akun != nomor_akun_hapus) {
            fwrite(&temp_user, sizeof(user), 1, temp_file); // Menyalin data ke file temporary
        } else {
            found = 1; // Akun ditemukan
        }
    }

    fclose(file);
    fclose(temp_file);

    if (!found) {
        printf("Akun dengan nomor akun tersebut tidak ditemukan.\n");
        remove("temp.dat"); // Hapus file temporary jika akun tidak ditemukan
        return;
    }

    // Mengganti file original dengan file temporary
    remove("user.dat");
    rename("temp.dat", "user.dat");

    printf("Akun dengan nomor akun %d telah dihapus.\n", nomor_akun_hapus);
}
