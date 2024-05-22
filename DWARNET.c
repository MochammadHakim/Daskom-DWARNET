#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char username[100];
    char password[100];
}user;

struct
{
    char username[100];
    char password[100];
}admin;

struct
{
    char nama[100];
}game;

struct
{
    char nama[100];
}software;

struct
{
    char nama[100];
    int harga;
}makanan;

struct
{
    char nama[100];
    int harga;
}minuman;

struct
{
    char nama[100];
    int harga;
    int jumlah;
    int total;
    char status[100];
}pesanan;

int pilihan;

int login();
int login_admin();
int daftar();
int daftar_admin();
void main_admin();
void manajemen_game();
int instalasi_game();
int hapus_game();
void manajemen_pc();
void instalasi_software();
int hapus_software();
void data_software();
void manajemen_akun();
void register_byadmin();
void hapus_akunbyadmin();
int detail_akunbyadmin();
void hapus_admin();
void detail_admin();
void penambahan_menu();
void tambah_makanan();
void hapus_makanan();
void detail_makanan();
void tambah_minuman();
void hapus_minuman();
void detail_minuman();
void main_user();
void lihat_status();
void pilih_game();
void beli_makanan();
void beli_minuman();
void bayar();
void bayar_minuman();
void main_software();
void lihat_status_admin();

int main(){
    printf("==Selamat Datang Di D'Warnet== \n 1. Login \n 2. Login Admin \n 3. Daftar \n 4. Keluar Program\n Pilihan: ");
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
        login_admin();
        break;

    case 3:
        system("cls");
        daftar_admin();
        break;

    case 4:
        system("cls");
        printf("Anda Keluar Dari Program. Terima Kasih!");
        return 0;
        break;
    default:
        printf("Pilihan Tidak Valid!");
        system("pause");
        system("cls");
        main();
        break;
    }
}

int login(){
    printf("== Login User ==\n");
    char username [100];
    char password [100];
    int i;
    int berhasil=0;
    int x=3;
    FILE *f_user;
    f_user=fopen("user.dat", "rb");
    if (f_user == NULL) {
        printf("Error Membuka File!\n");
        return 1;
    }
    for(i = 0; i < x; i++)
    {
        if (f_user == NULL) {
            printf("Error opening file");
            return 1;
        }
        printf("Masukkan Username: ");
        gets(username);
        printf("Masukkan Password: ");
        gets(password);
        rewind(f_user);
        while (fread(&user, sizeof(user), 1, f_user)==1)
        {
            if (strcmp(username, user.username)==0 && strcmp(password, user.password)==0)
            {
                berhasil=1;
                break;
            }
        }
        if (berhasil==1)
        {
            printf("Anda Berhasil Login!\n");
            system("pause");
            system("cls");
            main_user();
            break;
        } 
        else
        {
            printf("Username atau Password Salah!\nKesempatan Login: %d\n", x-i-1);
            if (i==2)
            {
                printf("Kesempatan Login Anda Habis! \nAnda Dikeluarkan Dari Program!");
            }
            
        }
        
    }
    fclose(f_user);
    return 0;
}
int login_admin(){
    printf("== Login Admin ==\n");
    char username [100];
    char password [100];
    int i;
    int berhasil=0;
    int x=3;
    FILE *f_admin;
    f_admin=fopen("admin.dat", "rb");
    if (f_admin == NULL) {
        printf("Error Membuka File!\n");
        return 1;
    }
    for(i = 0; i < x; i++)
    {
        if (f_admin == NULL) {
            printf("Error opening file");
            return 1;
        }
        printf("Masukkan Username: ");
        gets(username);
        printf("Masukkan Password: ");
        gets(password);
        rewind(f_admin);
        while (fread(&admin, sizeof(admin), 1, f_admin)==1)
        {
            if (strcmp(username, admin.username)==0 && strcmp(password, admin.password)==0)
            {
                berhasil=1;
                break;
            }
        }
        if (berhasil==1)
        {
            printf("Anda Berhasil Login!\n");
            system("pause");
            system("cls");
            main_admin();
            break;
        } 
        else
        {
            printf("Username atau Password Salah!\nKesempatan Login: %d\n", x-i-1);
            if (i==2)
            {
                printf("Kesempatan Login Anda Habis! \nAnda Dikeluarkan Dari Program!");
            }
            
        }
        
    }
    fclose(f_admin);
    return 0;
}

int daftar(){
    printf("== DAFTAR USER BARU ==\n");
    char username[100];
    int usernameExist=0;
    FILE *f_user;
    f_user=fopen("user.dat", "ab+");
    if (f_user == NULL) {
        printf("Error opening file");
        return 1;
    }
    printf("Masukkan Username Baru: ");
    gets(username);
    rewind(f_user);
    while (fread(&user, sizeof(user), 1, f_user)==1)
    {
        if (strcmp(username, user.username) == 0)
        {
            usernameExist=1;
            break;
        }
    }

    if (usernameExist)
    {
        printf("Maaf, Username Telah Digunakan. Silahkan Gunakan Username Lain.\n");
        daftar();
    }
    else{
        strcpy(user.username, username);
        printf("Masukkan Password Baru: ");
        gets(user.password);
        fwrite(&user, sizeof(user), 1, f_user);
        rewind(f_user);
        fclose(f_user);
        printf("User Baru Berhasil Ditambahkan! \nSilahkan Login dari awal!\n");
        system("pause");
        system("cls");
        main();
    }
    return 0;
}

int daftar_admin(){
    printf("== DAFTAR ADMIN BARU ==\n");
    char username[100];
    int usernameExist=0;
    FILE *f_admin;
    f_admin=fopen("admin.dat", "ab+");
    if (f_admin == NULL) {
        printf("Error opening file");
        return 1;
    }
    printf("Masukkan Username Baru: ");
    gets(username);
    rewind(f_admin);
    while (fread(&admin, sizeof(admin), 1, f_admin)==1)
    {
        if (strcmp(username, admin.username) == 0)
        {
            usernameExist=1;
            break;
        }
    }

    if (usernameExist)
    {
        printf("Maaf, Username Telah Digunakan. Silahkan Gunakan Username Lain.\n");
        daftar_admin();
    }
    else{
        strcpy(admin.username, username);
        printf("Masukkan Password Baru: ");
        gets(admin.password);
        fwrite(&admin, sizeof(admin), 1, f_admin);
        rewind(f_admin);
        fclose(f_admin);
        printf("Admin Baru Berhasil Ditambahkan! \nKembali Ke Manajemen Akun!\n");
        system("pause");
        system("cls");
        manajemen_akun();
    }
    return 0;
}

void main_admin(){
    printf("== Menu Utama Admin ==\n");
    printf("1. Manajemen Game \n2. Manajemen PC \n3. Manajemen Akun \n4. Penambahan Menu \n5. Lihat Status Pesanan \n6. Logout \nPilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        manajemen_game();
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
        lihat_status_admin();
        break;
    
    case 6:
        printf("Anda Telah Logout dari Admin!\n");
        system("pause");
        system("cls");
        main();
        break;
    
    default:
        printf("Opsi Tidak Tersedia!\n");
        system("pause");
        system("cls");
        main_admin();
        break;
    }
}

void manajemen_game(){
    printf("==Manajemen Game==\n");
    printf("1. Instalasi Game\n2. Hapus Game\n3. Kembali Ke Menu Utama\nPilihan: ");
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
        system("pause");
        system("cls");
        main_admin();
        break;

    default:
        printf("Opsi Tidak Tersedia!\n");
        system("pause");
        system("cls");
        break;
    }
}
int instalasi_game(){
    printf("== Instalasi Game Baru == \n");
    char game_baru[100];
    int gameExist=0;
    FILE *f_game;
    f_game=fopen("game.dat", "ab+");
    if (f_game == NULL) {
        printf("Error Membuka File!\n");
        return 1;
    }
    printf("Masukkan Nama Game Baru: ");
    gets(game_baru);
    while (fread(&game, sizeof(game), 1, f_game)==1)
    {
        if (strcmpi(game_baru, game.nama)==0)
        {
            gameExist=1;
            break;
        }
    }
    if (gameExist)
    {
        printf("Tidak Dapat Menginstall Game!\nGame Sudah Ada!\n");
        system("pause");
        system("cls");
        instalasi_game();
    }
    else{
        strcpy(game.nama, game_baru);
        fwrite(&game, sizeof(game), 1, f_game);
        rewind(f_game);
        fclose(f_game);
        printf("Game telah berhasil di download!\n Anda Dikembalikan Ke Menu utama Admin!\n");
        system("pause");
        system("cls");
        main_admin();
    }
    return 0;
}


int hapus_game(){
    char game_hapus[100];
    printf("== Hapus Game ==\n");
    int i=1;
    FILE *f_game;
    FILE *f_game2;
    printf("== List Game ==\n");
    f_game=fopen("game.dat", "rb");
    if (f_game == NULL) {
        printf("Error Membuka File!\n");
        return 1;
    }
    while (fread(&game, sizeof(game), 1, f_game)==1)
    {
        printf("%d. %s\n",i, game.nama);
        i++;
    }
    fclose(f_game);
    f_game=fopen("game.dat", "rb");
    if (f_game==NULL)
    {
        printf("Error Membuka File!\n");
    }
    
    f_game2=fopen("game2.dat", "wb");
    if (f_game2==NULL)
    {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama Game Yang Ingin Di Hapus: ");
    gets(game_hapus);
    while (fread(&game, sizeof(game), 1, f_game)==1)
    {
        if (strcmpi(game.nama, game_hapus)!=0)
        {
            fwrite(&game, sizeof(game), 1, f_game2);
        }
    }
    fclose(f_game);
    fclose(f_game2);
    remove("game.dat");
    rename("game2.dat", "game.dat");
    printf("Game %s Berhasil Di Hapus!\n", game_hapus);
    system("pause");
    system("cls");
    manajemen_game();
    return 0;
}
void manajemen_pc(){
    printf("== Manajemen PC ==\n");
    printf("1. Install Software\n2. Hapus Software\n3. Kembali Ke Menu Admin\n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        instalasi_software();
        break;

    case 2:
        system("cls");
        hapus_software();
        break;

    case 3:
        printf("Kembali Ke Menu Admin!\n");
        system("pause");
        system("cls");
        main_admin();
        break;
    
    default:
        printf("Opsi Tidak Tersedia!\n");
        system("pause");
        system("cls");
        manajemen_pc();
        break;
    }
}

void instalasi_software(){
    printf("== Instalasi Software ==\n");
    char software_baru[100];
    int softwareExist=0;
    FILE *f_sofware;
    f_sofware=fopen("software.dat", "ab+");
    if (f_sofware == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama Software Baru: ");
    gets(software_baru);
    while (fread(&software, sizeof(software), 1, f_sofware)==1)
    {
        if (strcmpi(software_baru, software.nama)==0)
        {
            softwareExist=1;
            break;
        }
    }
    if (softwareExist)
    {
        printf("Tidak Dapat Menginstall Software!\nSoftware Sudah Ada!\n");
        system("pause");
        system("cls");
        instalasi_game();
    }
    else{
        strcpy(software.nama, software_baru);
        fwrite(&software, sizeof(software), 1, f_sofware);
        rewind(f_sofware);
        fclose(f_sofware);
        printf("Software telah berhasil di download!\n Anda Dikembalikan Ke Menu Manajemen PC!\n");
        system("pause");
        system("cls");
        manajemen_pc();
    }
}

int hapus_software(){
    char software_hapus[100];
    printf("== Hapus Software ==\n");
    data_software();
    FILE *f_software;
    FILE *f_software2;
    f_software=fopen("software.dat", "rb");
    if (f_software==NULL)
    {
        printf("Error Membuka File!\n");
    }
    
    f_software2=fopen("software2.dat", "wb");
    if (f_software2==NULL)
    {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama Software Yang Ingin Di Hapus: ");
    gets(software_hapus);
    while (fread(&software, sizeof(software), 1, f_software)==1)
    {
        if (strcmpi(software.nama, software_hapus)!=0)
        {
            fwrite(&software, sizeof(software), 1, f_software2);
        }
    }
    fclose(f_software);
    fclose(f_software2);
    remove("software.dat");
    rename("software2.dat", "software.dat");
    printf("Software %s Berhasil Di Hapus!\n", software_hapus);
    system("pause");
    system("cls");
    manajemen_pc();
    return 0;
}

void data_software(){
    printf("== List Software ==\n");
    int i=1;
    FILE *f_software;
    f_software=fopen("software.dat", "rb");
    if (f_software == NULL) {
        printf("Error Membuka File!\n");
    }
    while (fread(&software, sizeof(software), 1, f_software)==1)
    {
        printf("%d. %s\n",i, software.nama);
        i++;
    }
    fclose(f_software);
}

void manajemen_akun(){
    printf("== Manajemen Akun ==\n");
    printf("1. Register Akun User by Admin \n2. Hapus Akun User \n3. Detail Akun User \n4. Tambah Admin Baru \n5. Hapus Admin \n6. Detail Admin \n7. Kembali Ke Menu Utama \nPilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        register_byadmin();
        break;
    
    case 2:
        system("cls");
        hapus_akunbyadmin();
        break;
    
    case 3:
        system("cls");
        detail_akunbyadmin();
        break;

    case 4:
        system("cls");
        daftar_admin();
        break;

    case 5:
        system("cls");
        hapus_admin();
        break;

    case 6:
        system("cls");
        detail_admin();
        break;

    case 7:
        system("cls");
        main_admin();
        break;
    
    default:
        printf("Opsi Tidak Ditemukan!\n");
        system("pause");
        system("cls");
        manajemen_akun();
        break;
    }
}

void register_byadmin(){
    printf("== DAFTAR USER BARU ==\n");
    char username[100];
    int usernameExist=0;
    FILE *f_user;
    f_user=fopen("user.dat", "ab+");
    if (f_user == NULL) {
        printf("Error opening file");
    }
    printf("Masukkan Username Baru: ");
    gets(username);
    rewind(f_user);
    while (fread(&user, sizeof(user), 1, f_user)==1)
    {
        if (strcmp(username, user.username) == 0)
        {
            usernameExist=1;
            break;
        }
    }

    if (usernameExist)
    {
        printf("Maaf, Username Telah Digunakan. Silahkan Gunakan Username Lain.\n");
        daftar();
    }
    else{
        strcpy(user.username, username);
        printf("Masukkan Password Baru: ");
        gets(user.password);
        fwrite(&user, sizeof(user), 1, f_user);
        rewind(f_user);
        fclose(f_user);
        printf("User Baru Berhasil Ditambahkan! \nKembali Ke Manajemen Akun!\n");
        system("pause");
        system("cls");
        manajemen_akun();
    }
}

void hapus_akunbyadmin(){
    char user_hapus[100];
    printf("\t==List Akun==\n");
    int i=1;
    FILE *f_user;
    f_user=fopen("user.dat", "rb");
    if (f_user == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Username== \t\t ==Password==\n");
    while (fread(&user, sizeof(user), 1, f_user)==1)
    {
        printf("%d.\t %s\t\t\t %s\n",i, user.username, user.password);
        i++;
    }
    fclose(f_user);
    FILE *f_user2;
    f_user=fopen("user.dat", "rb");
    if (f_user==NULL)
    {
        printf("Error Membuka File!\n");
    }
    
    f_user2=fopen("user2.dat", "wb");
    if (f_user2==NULL)
    {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama user Yang Ingin Di Hapus: ");
    gets(user_hapus);
    while (fread(&user, sizeof(user), 1, f_user)==1)
    {
        if (strcmp(user.username, user_hapus)!=0)
        {
            fwrite(&user, sizeof(user), 1, f_user2);
        }
    }
    fclose(f_user);
    fclose(f_user2);
    remove("user.dat");
    rename("user2.dat", "user.dat");
    printf("User %s Berhasil Di Hapus!\n", user_hapus);
    printf("Kembali Ke Menu Manajemen Akun!\n");
    system("pause");
    system("cls");
    manajemen_akun();
}

int detail_akunbyadmin(){
    printf("\t==List Akun==\n");
    int i=1;
    FILE *f_user;
    f_user=fopen("user.dat", "rb");
    if (f_user == NULL) {
        printf("Error Membuka File!\n");
        return 1;
    }
    printf("\t ==Username== \t\t ==Password==\n");
    while (fread(&user, sizeof(user), 1, f_user)==1)
    {
        printf("%d.\t %s\t\t\t %s\n",i, user.username, user.password);
        i++;
    }
    fclose(f_user);
    printf("Kembali Ke Menu Manajemen Akun...\n");
    system("pause");
    system("cls");
    manajemen_akun();
    return 0;
}

void hapus_admin(){
    char admin_hapus[100];
    printf("\t==List Akun==\n");
    int i=1;
    FILE *f_admin;
    f_admin=fopen("admin.dat", "rb");
    if (f_admin == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Username== \t\t ==Password==\n");
    while (fread(&admin, sizeof(admin), 1, f_admin)==1)
    {
        printf("%d.\t %s\t\t\t %s\n",i, admin.username, admin.password);
        i++;
    }
    rewind(f_admin);
    FILE *f_admin2;
    f_admin2=fopen("admin2.dat", "wb");
    if (f_admin2==NULL)
    {
        printf("Error Membuka File!\n");
        return;
    }
    printf("Masukkan Nama user Yang Ingin Di Hapus: ");
    gets(admin_hapus);
    while (fread(&admin, sizeof(admin), 1, f_admin)==1)
    {
        if (strcmp(admin.username, admin_hapus)!=0)
        {
            fwrite(&admin, sizeof(admin), 1, f_admin2);
        }
    }
    fclose(f_admin);
    fclose(f_admin2);
    remove("admin.dat");
    rename("admin2.dat", "admin.dat");
    printf("Admin %s Berhasil Di Hapus!\n", admin_hapus);
    printf("Kembali Ke Menu Manajemen Akun!\n");
    system("pause");
    system("cls");
    manajemen_akun();
}

void detail_admin(){
    printf("\t==List Akun==\n");
    int i=1;
    FILE *f_admin;
    f_admin=fopen("admin.dat", "rb");
    if (f_admin == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Username== \t\t ==Password==\n");
    while (fread(&admin, sizeof(admin), 1, f_admin)==1)
    {
        printf("%d.\t %s\t\t\t %s\n",i, admin.username, admin.password);
        i++;
    }
    fclose(f_admin);
    printf("Kembali Ke Menu Manajemen Akun...\n");
    system("pause");
    system("cls");
    manajemen_akun();
}
void penambahan_menu(){
    printf("==Penambahan Menu==\n");
    printf("1.Tambah Menu Makanan \n2. Hapus Menu Makanan \n3. Detail Makanan \n4. Tambah Menu Minuman \n5. Hapus Menu Minuman \n6. Detail Menu Minuman \n7. Kembali ke Menu Utama\nPilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        tambah_makanan();
        break;
    case 2:
        system("cls");
        hapus_makanan();
        break;
    case 3:
        system("cls");
        detail_makanan();
        break;

    case 4:
        system("cls");
        tambah_minuman();
        break;
    case 5:
        system("cls");
        hapus_minuman();
        break;
    case 6:
        system("cls");
        detail_minuman();
        break;

    case 7:
        printf("Kembali Ke Menu Utama...\n");
        system("pause");
        system("cls");
        main_admin();
        break;
    
    default:
        printf("Opsi Tidak Tersedia!\n");
        system("pause");
        system("cls");
        penambahan_menu();
        break;
    }
}

void tambah_makanan(){
    printf("==Tambah Makanan==\n");
    char makan[100];
    int makananExist=0;
    FILE *f_makanan;
    f_makanan=fopen("makanan.dat", "ab+");
    if (f_makanan == NULL) {
        printf("Error opening file");
    }
    printf("Masukkan Nama Makanan Baru: ");
    gets(makan);
    rewind(f_makanan);
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        if (strcmpi(makan, makanan.nama) == 0)
        {
            makananExist=1;
            break;
        }
    }

    if (makananExist)
    {
        printf("Maaf, Makanan Telah Ditambahkan Sebelumnya!.\n");
        tambah_makanan();
    }
    else{
        strcpy(makanan.nama, makan);
        printf("Masukkan Harga %s: ", makanan.nama);
        scanf("%d", &makanan.harga);
        getchar();
        fwrite(&makanan, sizeof(makanan), 1, f_makanan);
        rewind(f_makanan);
        fclose(f_makanan);
        printf("Makanan Baru Telah Ditambahkan!\n");
        printf("Kembali Ke Menu Sebelumnya!\n");
        system("pause");
        system("cls");
        penambahan_menu();
    }
}

void hapus_makanan(){
    char hapus_makanan[100];
    printf("\t==List Makanan==\n");
    int i=1;
    FILE *f_makanan;
    f_makanan=fopen("makanan.dat", "rb");
    if (f_makanan == NULL) {
        printf("Error Membuka File!\n");
    }
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        printf("\t ==Makanan== \t\t ==Harga==\n");
        printf("%d.\t %s\t\t Rp. %d\n",i, makanan.nama, makanan.harga);
        i++;
    }
    fclose(f_makanan);
    FILE *f_makanan2;
    f_makanan=fopen("makanan.dat", "rb");
    if (f_makanan==NULL)
    {
        printf("Error Membuka File!\n");
    }
    
    f_makanan2=fopen("makanan2.dat", "wb");
    if (f_makanan2==NULL)
    {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama Makanan Yang Ingin Di Hapus: ");
    gets(hapus_makanan);
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        if (strcmpi(makanan.nama, hapus_makanan)!=0)
        {
            fwrite(&makanan, sizeof(makanan), 1, f_makanan2);
        }
    }
    fclose(f_makanan);
    fclose(f_makanan2);
    remove("makanan.dat");
    rename("makanan2.dat", "makanan.dat");
    printf("Makanan %s Berhasil Di Hapus!\n", hapus_makanan);
    printf("Kembali Ke Menu Penambahan Makanan!\n");
    system("pause");
    system("cls");
    penambahan_menu();
}

void detail_makanan(){
    printf("\t==List Makanan==\n");
    int i=1;
    FILE *f_makanan;
    f_makanan=fopen("makanan.dat", "rb");
    if (f_makanan == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Makanan== \t\t ==Harga==\n");
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        printf("%d.\t %s\t\t Rp. %d\n",i, makanan.nama, makanan.harga);
        i++;
    }
    fclose(f_makanan);
    system("pause");
    system("cls");
    penambahan_menu();
}

void tambah_minuman(){
    printf("==Tambah Makanan==\n");
    char minum[100];
    int minumanExist=0;
    FILE *f_minuman;
    f_minuman=fopen("minuman.dat", "ab+");
    if (f_minuman == NULL) {
        printf("Error opening file");
    }
    printf("Masukkan Nama Minuman Baru: ");
    gets(minum);
    rewind(f_minuman);
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        if (strcmpi(minum, minuman.nama) == 0)
        {
            minumanExist=1;
            break;
        }
    }

    if (minumanExist)
    {
        printf("Maaf, Minuman Telah Ditambahkan Sebelumnya!.\n");
        tambah_minuman();
    }
    else{
        strcpy(minuman.nama, minum);
        printf("Masukkan Harga %s: ", minuman.nama);
        scanf("%d", &minuman.harga);
        getchar();
        fwrite(&minuman, sizeof(minuman), 1, f_minuman);
        rewind(f_minuman);
        fclose(f_minuman);
        printf("Minuman Baru Telah Ditambahkan!\n");
        printf("Kembali Ke Menu Sebelumnya!\n");
        system("pause");
        system("cls");
        penambahan_menu();
    }
}

void hapus_minuman(){
    char hapus_minuman[100];
    printf("\t==List Minuman==\n");
    int i=1;
    FILE *f_minuman;
    f_minuman=fopen("minuman.dat", "rb");
    if (f_minuman == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Minuman== \t\t ==Harga==\n");
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        printf("%d.\t %s\t\t Rp. %d\n",i, minuman.nama, minuman.harga);
        i++;
    }
    fclose(f_minuman);
    FILE *f_minuman2;
    f_minuman=fopen("minuman.dat", "rb");
    if (f_minuman==NULL)
    {
        printf("Error Membuka File!\n");
    }
    
    f_minuman2=fopen("minuman2.dat", "wb");
    if (f_minuman2==NULL)
    {
        printf("Error Membuka File!\n");
    }
    printf("Masukkan Nama Minuman Yang Ingin Di Hapus: ");
    gets(hapus_minuman);
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        if (strcmpi(minuman.nama, hapus_minuman)!=0)
        {
            fwrite(&minuman, sizeof(minuman), 1, f_minuman2);
        }
    }
    fclose(f_minuman);
    fclose(f_minuman2);
    remove("minuman.dat");
    rename("minuman2.dat", "minuman.dat");
    printf("Minuman %s Berhasil Di Hapus!\n", hapus_minuman);
    printf("Kembali Ke Menu Sebelumnya!\n");
    system("pause");
    system("cls");
    penambahan_menu();
}


void detail_minuman(){
    printf("\t==List Minuman==\n");
    int i=1;
    FILE *f_minuman;
    f_minuman=fopen("minuman.dat", "rb");
    if (f_minuman == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Minuman== \t\t ==Harga==\n");
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        printf("%d.\t %s\t\t Rp. %d\n",i, minuman.nama, minuman.harga);
        i++;
    }
    fclose(f_minuman);
    system("pause");
    system("cls");
    penambahan_menu();
}

void main_user(){
    printf("==Menu User==\n");
    printf(" 1. Pilih Game \n 2. Pilih Software \n 3. Beli Makanan \n 4. Beli Minuman \n 5. Bayar \n 6. Lihat Status Pesanan \n 7. Logout \n Pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        system("cls");
        pilih_game();
        break;
    
    case 2:
        system("cls");
        main_software();
        break;

    case 3:
        system("cls");
        beli_makanan();
        break;

    case 4:
        system("cls");
        beli_minuman();
        break;

    case 5:
        system("cls");
        bayar();
        break;

    case 6:
        system("cls");
        lihat_status();
        break;

    case 7:
        printf("Anda Logout Dari Sistem!\n");
        system("pause");
        system("cls");
        main();
        break;

    default:
        printf("Opsi Tidak Tersedia!\n");
        system("pause");
        system("cls");
        main_user();
        break;
    }
}

void pilih_game(){
    int i=1;
    int gameExist=0;
    int Exit=0;
    char main_game[100];
    printf("==List Game==\n");
    FILE *f_game;
    f_game=fopen("game.dat", "rb");
    if (f_game == NULL) {
        printf("Error Membuka File!\n");
    }

    while (fread(&game, sizeof(game), 1, f_game)==1)
    {
        printf("%d. %s\n",i, game.nama);
        i++;
    }
    rewind(f_game);
    printf(" Pilih Game Yang Di mainkan (Ketik 'exit' Untuk Kembali!): ");
    gets(main_game);
    while (fread(&game, sizeof(game), 1, f_game)==1)
    {
        if (strcmpi(main_game, game.nama)==0)
        {
            gameExist=1;
            break;
        }
        else if (strcmpi(main_game, "Exit")==0)
        {
            Exit=1;
            break;
        }
        
        
    }
    if (gameExist)
    {
        printf("Memainkan Game %s\n", game.nama);
        system("pause");
        printf("Selesai Memainkan Game %s\n", game.nama);
        printf("Kembali Ke Pemilihan Game!\n");
        system("pause");
        fclose(f_game);
        system("cls");
        pilih_game();
    }
    else if (Exit)
    {
        printf("Kembali Ke Menu Utama!\n");
        fclose(f_game);
        system("pause");
        system("cls");
        main_user();
    }
    else{
        printf("Game %s Tidak Tersedia\n", main_game);
        fclose(f_game);
        printf("Kembali Ke Pilih Game!\n");
        system("pause");
        system("cls");
        pilih_game();
    }
}

void main_software(){
    int i=1;
    int softwareExist=0;
    int keluar=0;
    char pilih_software[100];
    printf("==List Software==\n");
    FILE *f_software;
    f_software=fopen("software.dat", "rb");
    if (f_software == NULL) {
        printf("Error Membuka File!\n");
    }

    while (fread(&software, sizeof(software), 1, f_software)==1)
    {
        printf("%d. %s\n",i, software.nama);
        i++;
    }
    rewind(f_software);
    printf(" Pilih Software Yang Di Jalankan (Ketik 'exit' Untuk Kembali!): ");
    gets(pilih_software);
    while (fread(&software, sizeof(software), 1, f_software)==1)
    {
        if (strcmpi(pilih_software, software.nama)==0)
        {
            softwareExist=1;
            break;
        }
        else if (strcmpi(pilih_software, "exit")==0)
        {
            keluar=1;
            break;
        }
        
        
    }
    if (softwareExist)
    {
        printf("Menjalakan Software %s\n", software.nama);
        system("pause");
        printf("Selesai Menjalankan software %s\n", software.nama);
        printf("Kembali Ke Pemilihan software!\n");
        system("pause");
        fclose(f_software);
        system("cls");
        main_software();
    }
    else if (keluar)
    {
        printf("Kembali Ke Menu Utama!\n");
        fclose(f_software);
        system("pause");
        system("cls");
        main_user();
    }
    else{
        printf("Software %s Tidak Tersedia\n", pilih_software);
        fclose(f_software);
        printf("Kembali Ke Pilih Game!\n");
        system("pause");
        system("cls");
        main_software();
    }
    

}

void beli_makanan(){
    int x=1;
    char pilih_makanan[100];
    int makananExist=0;
    int Keluar=0;
    FILE *f_makanan;
    FILE *f_pesanan;
    f_makanan=fopen("makanan.dat", "rb");
    if (f_makanan == NULL) {
        printf("Error Membuka File!\n");
    }
    f_pesanan=fopen("pesanan.dat", "ab");
    if (f_pesanan == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Makanan== \t\t ==Harga==\n");
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        printf("%d.\t %s\t\t Rp. %d\n",x, makanan.nama, makanan.harga);
        x++;
    }
    rewind(f_makanan);
    printf("Pilih Nama Makanan Yang Ingin Di Pesan (Tulis 'Exit' Untuk Kembali!): ");
    gets(pilih_makanan);
    while (fread(&makanan, sizeof(makanan), 1, f_makanan)==1)
    {
        if (strcmpi(pilih_makanan, makanan.nama)==0)
        {
            makananExist=1;
            break;
        }
        else if (strcmpi(pilih_makanan, "Exit")==0)
        {
            Keluar=1;
            break;
        }
        
    }
    if (makananExist)
    {
        printf("Jumlah Yang Ingin Di Beli: ");
        scanf("%d", &pesanan.jumlah);
        getchar();
        pesanan.harga=makanan.harga;
        strcpy(pesanan.nama, makanan.nama);
        strcpy(pesanan.status, "On-Going");
        pesanan.total=pesanan.jumlah * pesanan.harga;
        fwrite(&pesanan, sizeof(pesanan), 1, f_pesanan);
        fclose(f_makanan);
        printf(" Makanan: %s\n Jumlah: %d, \n Harga: %d \n Total Bayar: %d\n Status: %s\n", pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        main_user();
    }
    else if (Keluar)
    {
        printf("Kembali Ke Menu Utama...\n");
        fclose(f_makanan);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        main_user();
    }
    
    else{
        printf("Makanan Tidak Tersedia!\n");
        fclose(f_makanan);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        beli_makanan();
    }
}
void lihat_status(){
    int x=1;
    FILE *f_pesanan;
    f_pesanan=fopen("pesanan.dat", "rb");
    if (f_pesanan == NULL) {
        printf("Error Membuka File!\n");
    }
    while (fread(&pesanan, sizeof(pesanan), 1, f_pesanan)==1)
    {
        printf("%d. Pesanan: %s\n Jumlah: %d \n Harga: %d \n Total Bayar: %d\n Status: %s\n",x, pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        x++;
    }
    system("pause");
    system("cls");
    fclose(f_pesanan);
    main_user();
}

void lihat_status_admin(){
    int x=1;
    FILE *f_pesanan;
    f_pesanan=fopen("pesanan.dat", "rb");
    if (f_pesanan == NULL) {
        printf("Error Membuka File!\n");
    }
    while (fread(&pesanan, sizeof(pesanan), 1, f_pesanan)==1)
    {
        printf("%d. Pesanan: %s\n Jumlah: %d \n Harga: %d \n Total Bayar: %d\n Status: %s\n",x, pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        x++;
    }
    system("pause");
    system("cls");
    fclose(f_pesanan);
    main_admin();
}

void bayar(){
    int x=1;
    int i=1;
    int jumlah;
    char pilih_pesanan[100];
    int pesananExist=0;
    int Keluar=0;
    int pembayaran;
    FILE *f_pesanan;
    FILE *f_pesanan2;
    f_pesanan=fopen("pesanan.dat", "ab+");
    if (f_pesanan == NULL) {
        printf("Error Membuka File!\n");
    }
    f_pesanan2=fopen("pesanan2.dat", "wb");
    if (f_pesanan2 == NULL) {
        printf("Error Membuka File!\n");
    }
    while (fread(&pesanan, sizeof(pesanan), 1, f_pesanan)==1)
    {
        printf("%d. Pesanan: %s\n Jumlah: %d, \n Harga: %d \n Total Bayar: %d\n Status: %s\n",x, pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        x++;
    }
    rewind(f_pesanan);
    printf("Pilih Nama Pesanan Yang Ingin Di Bayar (Tulis 'Exit' Untuk Kembali!): ");
    gets(pilih_pesanan);
    printf("Pilih Jumlah Pesanan Yang Ingin Di Bayar: ");
    scanf("%d", &jumlah);
    getchar();
    while (fread(&pesanan, sizeof(pesanan), 1, f_pesanan)==1)
    {
        if (strcmpi(pilih_pesanan, pesanan.nama)==0 && (jumlah==pesanan.jumlah))
        {
            pesananExist=1;
            break;
        }
        else if (strcmpi(pilih_pesanan, "Exit")==0)
        {
            Keluar=1;
            break;
        }
    }
    if (pesananExist)
    {
        system("cls");
        printf("%d. pesanan: %s\n Jumlah: %d \n Harga: %d \n Total Bayar: %d\n Status: %s\n",i, pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        i++;
        printf("Masukkan Total Bayar: ");
        scanf("%d", &pembayaran);
        getchar();
        if (pembayaran==pesanan.total)
        {
            rewind(f_pesanan);
            while (fread(&pesanan, sizeof(pesanan), 1, f_pesanan) == 1)
            {
                if (strcasecmp(pilih_pesanan, pesanan.nama) == 0) 
                {
                    strcpy(pesanan.status, "Completed");
                }
                fwrite(&pesanan, sizeof(pesanan), 1, f_pesanan2);
            }
            fflush(f_pesanan);
            fclose(f_pesanan);
            fclose(f_pesanan2);
            remove("pesanan.dat");
            rename("pesanan2.dat", "pesanan.dat");
            printf("Pembayaran Berhasil!\nSilahkan Tunggu Pesanan Anda!\n");
            printf("Kembali Ke Menu Utama...\n");
            system("pause");
            system("cls");
            main_user();
        }
        else{
            printf("Total Tidak Sesuai!\nSilahkan Input Ulang!\n");
            fclose(f_pesanan);
            fclose(f_pesanan2);
            system("pause");
            system("cls");
            bayar();
        }
    }
    else if (Keluar)
    {
        printf("Kembali Ke Menu Utama...\n");
        fclose(f_pesanan);
        fclose(f_pesanan2);
        remove("pesanan2.dat");
        system("pause");
        system("cls");
        main_user();
    }
    else{
        printf("Opsi Tidak Tersedia!\n");
        fclose(f_pesanan);
        system("pause");
        system("cls");
        bayar();
    }
    
}

void beli_minuman(){
    int x=1;
    char pilih_minuman[100];
    int minumanExist=0;
    int Keluar=0;
    FILE *f_minuman;
    FILE *f_pesanan;
    f_minuman=fopen("minuman.dat", "rb");
    if (f_minuman == NULL) {
        printf("Error Membuka File!\n");
    }
    f_pesanan=fopen("pesanan.dat", "ab");
    if (f_minuman == NULL) {
        printf("Error Membuka File!\n");
    }
    printf("\t ==Minuman== \t\t ==Harga==\n");
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        printf("%d.\t %s\t\t Rp. %d\n",x, minuman.nama, minuman.harga);
        x++;
    }
    rewind(f_minuman);
    printf("Pilih Nama Minuman Yang Ingin Di Pesan (Tulis 'Exit' Untuk Kembali!): ");
    gets(pilih_minuman);
    while (fread(&minuman, sizeof(minuman), 1, f_minuman)==1)
    {
        if (strcmpi(pilih_minuman, minuman.nama)==0)
        {
            minumanExist=1;
            break;
        }
        else if (strcmpi(pilih_minuman, "Exit")==0)
        {
            Keluar=1;
            break;
        }
        
    }
    if (minumanExist)
    {
        printf("Jumlah Yang Ingin Di Beli: ");
        scanf("%d", &pesanan.jumlah);
        getchar();
        pesanan.harga=minuman.harga;
        strcpy(pesanan.nama, minuman.nama);
        strcpy(pesanan.status, "On-Going");
        pesanan.total=pesanan.jumlah * pesanan.harga;
        fwrite(&pesanan, sizeof(pesanan), 1, f_pesanan);
        fclose(f_minuman);
        printf(" Minuman: %s\n Jumlah: %d, \n Harga: %d \n Total Bayar: %d\n Status: %s\n", pesanan.nama, pesanan.jumlah, pesanan.harga, pesanan.total, pesanan.status);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        main_user();
    }
    else if (Keluar)
    {
        printf("Kembali Ke Menu Utama...\n");
        fclose(f_minuman);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        main_user();
    }
    
    else{
        printf("Minuman Tidak Tersedia!\n");
        fclose(f_minuman);
        fclose(f_pesanan);
        system("pause");
        system("cls");
        beli_minuman();
    }
}