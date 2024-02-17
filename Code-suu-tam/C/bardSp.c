#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[100];
    int age;
};

typedef struct User User;

void insert_user(User *user) {
    printf("nhap ten: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng thừa.
    printf("nhap tuoi: ");
    scanf("%d", &user->age);
    getchar(); // Đọc và loại bỏ dấu xuống dòng còn lại sau hàm scanf.
}

void add_user(User **users, int *length) {
    User *tmp = realloc(*users, (*length + 1) * sizeof(User));
    if (tmp == NULL) {
        printf("Khong the cap phat!\n");
        exit(1);
    }

    insert_user(&tmp[*length]);
    (*length)++;
    *users = tmp;
}

void print_users(User *users, int length) {
    for (int i = 0; i < length; i++) {
        printf("name: %s | age: %d\n", users[i].name, users[i].age);
    }
}

int choice() {
    printf("====MENU====\n");
    printf("1. them user\n");
    printf("2. xem danh sach\n");
    printf("0. close\n");
    int number;
    printf("nhap lua chon: ");
    scanf("%d", &number);
    getchar(); // Đọc và loại bỏ dấu xuống dòng còn lại sau hàm scanf.
    return number;
}

int main() {
    int length = 0;
    User *users = NULL;

    int run = 1;
    while (run) {
        int number = choice();
        switch (number) {
            case 1:
                printf("Lua chon them user!\n");
                add_user(&users, &length);
                break;
            case 2:
                printf("Lua chon in ra danh sach user!\n");
                print_users(users, length);
                break;
            case 0:
                printf("Da chon dong chuong trinh!\n");
                printf("Tam biet!");
                run = 0;
                break;
            default:
                printf("Nhap sai lua chon, vui long thu lai.\n");
        }
    }

    free(users);

    return 0;
}
