#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct Student Student;
struct Student {
    char name[30];
    int age;
    char id[10];
    float gpa;
    char branch[10];
};

int menu() {
    printf("=== MENU ===\n");
    printf("1. add student\n");
    printf("2. print listStudent\n");
    printf("0. exit\n");
    printf("enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}
void removeLine(char *string) {
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0'; // Thay thế '\n' bằng '\0'
    }
}
Student createStudent() {
    Student newStudent;
    printf("enter name: ");
    getchar();
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    removeLine(newStudent.name);
    printf("enter age: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("enter id: ");
    fgets(newStudent.id, sizeof(newStudent.id), stdin);
    removeLine(newStudent.id);
    printf("enter gpa: ");
    scanf("%f", &newStudent.gpa);
    getchar();
    printf("enter branch: ");
    fgets(newStudent.branch, sizeof(newStudent.branch), stdin);
    return newStudent;
}
void addStudent(Student **listStudent, int *length) {
    int newLength = *length + 1;
    *listStudent = realloc(*listStudent, newLength * sizeof(Student));
    (*listStudent)[*length] = createStudent();
    *length = newLength;
    printf("successful!\n");
}
void display(Student *listStudent, int length) {
    if(length == 0) {
        printf("no data in list\n");
    } else {

        for(int i = 0; i < length; i++) {
            printf("name: %s | ", listStudent[i].name);
            printf("age: %d | ", listStudent[i].age);
            printf("id: %s | ", listStudent[i].id);
            printf("GPA: %.2f | ", listStudent[i].gpa);
            printf("Branch: %s\n", listStudent[i].branch);
        }
    }
}

int main() {
    int length = 0;
    Student *listStudent = NULL;;

    int isRunning = 1;
    while(isRunning) {
        int choice = menu();
        switch(choice) {
            case 1:
                printf("=========\n");
                printf("length: %d\n", length);
                addStudent(&listStudent, &length);
                break;
            case 2:
                printf("=========\n");
                display(listStudent, length);
                break;
            case 0:
                printf("exit the app");
                free(listStudent);
                isRunning = 0;
                break;
            default:
                printf("invalid, please choice again!");

        }
    }
}