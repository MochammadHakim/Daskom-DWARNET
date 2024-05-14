#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char username_user [100];
char password_user [100];
char username_admin [100];
char password_admin [100];

int login();
int daftar();
int login_user();
int login_admin();
int main_user();

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
    printf("== Login == \n 1. User \n 2. Admin \n 3. Kembali \n Pilihan:");
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
    FILE *f_user;
    char line[100];
    int username_exists = 0;
    printf("==Daftar== \n");
    printf("Masukkan Username: ");
    fgets(username_user, sizeof(username_user), stdin);
    username_user[strcspn(username_user, "\n")] = '\0'; 
    printf("Masukkan password: ");
    fgets(password_user, sizeof(password_user), stdin);
    password_user[strcspn(password_user, "\n")] = '\0';
    f_user = fopen("admin.txt", "r");
    if (f_user == NULL) {
        printf("Tidak dapat membuka file!\n");
        return 1;
    }
    while (fgets(line, sizeof(line), f_user) != NULL)
    {
        char existing_username[100];
        sscanf(line, "%s", existing_username);
        if (strcmp(username_user, existing_username) == 0) {
            username_exists = 1;
            break;
        }
    }
    fclose(f_user);
    
    if (username_exists)
    {
        system("cls");
        printf("Username Telah Digunakan!\n");
        return daftar();
    }
    
    f_user = fopen("user.txt", "a");
    if (f_user == NULL) {
        printf("Tidak dapat membuka file!\n");
        return main();
    }
    fprintf(f_user, "%s %s\n", username_user, password_user);
    fclose (f_user);
    system("cls");
    printf("Registrasi Berhasil!\n");
    return main();
}


int login_user(){
    int i;
    for (i = 3; i > 0; i--)
    {
        FILE *f_user;
        char line[100];
        int username_exists=0;
        printf("==lOGIN USER==\n");
        printf("Masukkan Username: ");
        fgets(username_user, sizeof(username_user), stdin);
        username_user[strcspn(username_user, "\n")] = '\0'; 
        printf("Masukkan password: ");
        fgets(password_user, sizeof(password_user), stdin);
        password_user[strcspn(password_user, "\n")] = '\0';
        f_user = fopen("user.txt", "r");
        if (f_user == NULL) {
            printf("Tidak dapat membuka file!\n");
            return 1;
        }
        while (fgets(line, sizeof(line), f_user) != NULL)
        {
            char existing_username[100];
            sscanf(line, "%s", existing_username);
            if (strcmp(username_user, existing_username) == 0) {
                username_exists = 1;
                break;
            }
        }
        fclose(f_user);
        if (username_exists)
        {
            system("cls");
            i=0;
            return main_user();
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

int login_admin(){
    int i;
    for (i = 3; i > 0; i--)
    {
        FILE *f_admin;
        char line[100];
        int username_exists=0;
        printf("==lOGIN ADMIN==\n");
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
            i=0;
            return main_user();
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
    printf("Login Berhasil!");
    return 0;
}
