#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct {
    char username_user[100];
    char password_user[100];
    int nomor_akun;
} user;
char username_admin [100];
char password_admin [100];
char game[100];

int login();
int daftar();
int login_user();
int login_admin();
int main_user();
int choose_game();
int makanan();
int minuman();
int lihat_status_pesanan();
int playgame();
int main_admin();
int manajemen_pc();
int instalasi_game();
void hapus_game();
int lihat_game();
int manajemen_akun();
int penambahan_menu();
int daftar_byadmin();
void cek_akun();
void hapus_akun();


void announcement(){
    printf("Login Berhasil!\n");
}
int main(){
    int pilihan;
    printf("==Selamat Datang Di D'Warnet== \n 1. Login \n 2. Daftar \n 3. Keluar Program\n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
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
        printf("Anda Keluar Dari Program. Terima Kasih!");
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
    switch (pilihan)
    {
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

    // Mencari nomor akun terakhir dan mengecek apakah username sudah digunakan
    user temp_user;
    int last_account_number = 0;
    while (fread(&temp_user, sizeof(user), 1, file) == 1) {
        if (strcmp(temp_user.username_user, new_user.username_user) == 0) {
            fclose(file);
            system("cls");
            printf("Username telah digunakan.\n");
            return daftar();
        }
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
    system("cls");
    printf("Registrasi Berhasil! Nomor Akun Anda adalah: %d\n", new_user.nomor_akun);
    return main();
}


int login_user(){
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
    int i;
    for (i = 3; i > 0; i--)
    {
        FILE *f_admin;
        char line[100];
        int username_exists=0;
        printf("==LOGIN ADMIN==\n");
        printf("Masukkan Username: ");
        fgets(username_admin, sizeof(username_admin), stdin);
        username_admin[strcspn(username_admin, "\n")] = '\0'; 
        printf("Masukkan password: ");
        fgets(password_admin, sizeof(password_admin), stdin);
        password_admin[strcspn(password_admin, "\n")] = '\0';
        f_admin = fopen("admin.txt", "r");
        if (f_admin == NULL) {
            printf("Tidak dapat membuka file!\n");
            return 1;
        }
        while (fgets(line, sizeof(line), f_admin) != NULL)
        {
            char existing_username[100];
            sscanf(line, "%s", existing_username);
            if (strcmp(username_admin, existing_username) == 0) {
                username_exists = 1;
                break;
            }
        }
        fclose(f_admin);
        if (username_exists)
        {
            system("cls");
            announcement();
            i=0;
            return main_admin();
        }
        else if (i > 1)
        {
            system("cls");
            printf("Username Atau Password Salah!\n");
            printf("Kesempatan Login: %d\n", i-1);
        }
        
        else{
            system("cls");
            printf("Username Atau Password Salah!\n");
            printf("Kesempatan Login Habis!");
        }

    }
}

int main_user(){
    int pilihan;
    printf("==Menu User== \n 1. Pilih Game \n 2. Beli Makanan \n 3. Beli Minuman \n 4. Lihat Status Pesanan \n 5. Logout \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        choose_game();
        break;

    case 2:
        system("cls");
        makanan();
        break;
    case 3:
        system("cls");
        minuman();
        break;

    case 4:
        system("cls");
        lihat_status_pesanan();
        break;

    case 5:
        system("cls");
        main();
        break;

    default:
        printf("Opsi Tidak Tersedia!");
        break;
    }
}

int choose_game(){
    int pilihan;
    FILE *file_software;
    char game[100];

    // Buka file game.dat dalam mode read
    file_software = fopen("game.dat", "r");
    if (file_software == NULL) {
        printf("Gagal membuka file game.dat atau file belum ada!\n");
        return 1;
    }

    printf("== Daftar Game ==\n");
    // Baca dan tampilkan setiap nama game dari file
    while (fgets(game, sizeof(game), file_software)) {
        // Menghapus newline di akhir string jika ada
        game[strcspn(game, "\n")] = '\0';
        printf("%s\n", game);
    }
    
    fclose(file_software);
    printf("99. Kembali Ke Menu User: \n");
    printf("Pilih Nomor Game: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        playgame();
        break;

    case 2:
        system("cls");
        playgame();
        break;
    case 99:
        system("cls");
        main_user();
        break;

    default:
        printf("Opsi Tidak Tersedia!");
        break;
    }
    return 0;

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
    return 0;
}

int playgame(){
    printf("Press any key to finish.....\n");
    getch();
    system("cls");
    return choose_game();
}

int main_admin(){
    int pilihan;
    printf("==Menu Admin== \n 1. Instalasi Game \n 2. Manajemen PC \n 3. Manajemen Akun \n 4. Penambahan Menu \n 5. Logout \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        instalasi_game();
        break;

    case 2:
        system("cls");
        manajemen_pc();
        break;
    case 3:
        system("cls");
        manajemen_akun();
        break;

    case 4:
        system("cls");
        penambahan_menu();
        break;

    case 5:
        system("cls");
        main();
        break;

    default:
        printf("Opsi Tidak Tersedia!");
        break;
    }
}
int instalasi_game(){
    FILE *file_software;
    char game[100];

    // Meminta input dari pengguna
    printf("== Install Game ==\n");
    printf("Masukkan Nama Game: ");
    fgets(game, sizeof(game), stdin);
    game[strcspn(game, "\n")] = '\0';  // Menghapus newline di akhir string

    // Buka file game.dat dalam mode append
    file_software = fopen("game.dat", "a");
    if (file_software == NULL) {
        printf("Gagal membuka file game.dat!\n");
        return 1;
    }

    // Menambahkan nama game ke file
    fprintf(file_software, "%s\n", game);
    fclose(file_software);

    printf("Game '%s' telah ditambahkan ke file game.dat\n", game);
    return main_admin();
}

int penambahan_menu(){
    printf(".");
}

int manajemen_pc(){
    int pilihan;
    printf("==Manajemen PC== \n 1. Instalasi Software \n 2. Hapus Software \n 3. Lihat List Game \n 4. Kembali Ke Menu Admin \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        instalasi_game();
        break;

    case 2:
        system("cls");
        hapus_game();
        break;

    case 3:
        system("cls");
        lihat_game();
        break;

    case 4:
        system("cls");
        main_admin();
        break;

    default:
        printf("Opsi Tidak Tersedia!");
        break;
    }
}

void hapus_game() {
    FILE *file_software, *temp_file;
    char game[100];

    // Buka file game.dat dalam mode read
    file_software = fopen("game.dat", "r");
    if (file_software == NULL) {
        printf("Gagal membuka file game.dat atau file belum ada!\n");
        manajemen_pc();
    }

    printf("== Daftar Software ==\n");
    // Baca dan tampilkan setiap nama game dari file
    while (fgets(game, sizeof(game), file_software)) {
        // Menghapus newline di akhir string jika ada
        game[strcspn(game, "\n")] = '\0';
        printf("%s\n", game);
    }
    
    fclose(file_software);
    char game_name[100];
    char game_to_delete[100];
    int found = 0;

    // Meminta input dari pengguna
    printf("== Hapus Software ==\n");
    printf("Masukkan Nama Game yang akan dihapus: ");
    fgets(game_to_delete, sizeof(game_to_delete), stdin);
    game_to_delete[strcspn(game_to_delete, "\n")] = '\0';  // Menghapus newline di akhir string

    // Buka file game.dat dalam mode read
    file_software = fopen("game.dat", "r");
    if (file_software == NULL) {
        printf("Gagal membuka file game.dat!\n");
        return;
    }

    // Buka file temporary dalam mode write
    temp_file = fopen("temp.dat", "w");
    if (temp_file == NULL) {
        printf("Gagal membuka file temporary!\n");
        fclose(file_software);
        manajemen_pc();
    }

    // Baca dan salin game yang tidak dihapus ke file temporary
    while (fgets(game_name, sizeof(game_name), file_software)) {
        game_name[strcspn(game_name, "\n")] = '\0'; // Menghapus newline di akhir string
        if (strcmp(game_name, game_to_delete) != 0) {
            fprintf(temp_file, "%s\n", game_name);
        } else {
            found = 1;
        }
    }

    fclose(file_software);
    fclose(temp_file);

    // Hapus file asli dan ganti dengan file temporary
    if (found) {
        remove("game.dat");
        system("cls");
        rename("temp.dat", "game.dat");
        printf("Game '%s' telah dihapus dari file game.dat\n", game_to_delete);
    
    } else {
        remove("temp.dat");
        system("cls");
        printf("Game '%s' tidak ditemukan dalam file game.dat\n", game_to_delete);
    }
     manajemen_pc();
}

int lihat_game(){
    FILE *file_software;
    file_software = fopen("game.dat", "r");
    if (file_software == NULL) {
        printf("Gagal membuka file game.dat atau file belum ada!\n");
        return 1;
    }

    printf("== Daftar Game ==\n");
    // Baca dan tampilkan setiap nama game dari file
    while (fgets(game, sizeof(game), file_software)) {
        // Menghapus newline di akhir string jika ada
        game[strcspn(game, "\n")] = '\0';
        printf("%s\n", game);
    }
    fclose(file_software);
    printf("== End Daftar Game ==");
    printf("Press any key to continue.....\n");
    getch();
    system("cls");
    manajemen_pc();

}
int manajemen_akun(){
    int pilihan;
    printf("==Menu Admin== \n 1. Daftar User Baru \n 2. Penghapusan Akun User \n 3. Detail Akun User \n 4. Kembali Ke Menu Admin \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        daftar_byadmin();
        break;

    case 2:
        system("cls");
        FILE *file;
        user temp_user;

        // Buka file untuk membaca data pengguna yang sudah terdaftar
        file = fopen("user.dat", "rb");
        if (file == NULL) {
            printf("Gagal membuka file!\n");
            return 1;
        }

        printf("== Daftar Akun ==\n");
        printf("%s\t %s\t %s\n", "Nomor Akun", "Username", "Password");
        printf("--------------------------------------------------\n");

        // Membaca dan menampilkan detail setiap akun
        while (fread(&temp_user, sizeof(user), 1, file) == 1) {
            printf("%d\t\t %s\t\t %s\n", temp_user.nomor_akun, temp_user.username_user, temp_user.password_user);
        }

        fclose(file);
        int nomor;
        printf("Pilih Nomor Akun Yang Ingin Di Hapus: ");
        scanf("%d", &nomor);
        getchar();
        hapus_akun(nomor);
        break;
    case 3:
        system("cls");
        cek_akun();
        break;

    case 4:
        system("cls");
        main_admin();
        break;

    default:
        printf("Opsi Tidak Tersedia!");
        break;
    }
}


int daftar_byadmin(){
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

    // Mencari nomor akun terakhir dan mengecek apakah username sudah digunakan
    user temp_user;
    int last_account_number = 0;
    while (fread(&temp_user, sizeof(user), 1, file) == 1) {
        if (strcmp(temp_user.username_user, new_user.username_user) == 0) {
            fclose(file);
            system("cls");
            printf("Username telah digunakan.\n");
            return daftar();
        }
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
    system("cls");
    printf("Registrasi Berhasil! Nomor Akun Anda adalah: %d\n", new_user.nomor_akun);
    return manajemen_akun();
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
    printf("Press any key to continue....\n");
    getch();
    system("cls");
    manajemen_akun();
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
            if (temp_user.nomor_akun > nomor_akun_hapus) {
                temp_user.nomor_akun -= 1; // Kurangi nomor akun untuk menjaga urutan
            }
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
    manajemen_akun();
}

