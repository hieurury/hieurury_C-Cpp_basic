#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int* &array, int &length);
void print(int array[], int length);
int menu();

int main() {
	int length = 0;
	int memory = length + 1;
	int *arr = (int*)malloc(memory * sizeof(int));
	int is_run = 1;
	while(1) {
		int your_chosse = menu();
		switch(your_chosse){
		case 1:
			printf("lua chon nap du lieu: \n");
			add(arr, length);
			printf("length: %d\n", length);
			break;
		case 2:
			printf("lua chon in gia tri: \n");
			print(arr, length);
			printf("length: %d\n", length);
			break;
		case 0:
			printf("lua chon ket thuc chuong trinh!\n");
			is_run = 0;
			break;
		default:
			printf("lua chon khong hop le!\n");
		}
		if(!is_run) break;
	}
	
}

int menu() {
	printf("DAY LA MENU LUA CHON CUA CHUONG TRINH\n");
	printf("1. them gia tri\n");
	printf("2. in gia tri\n");
	printf("0. exit\n");
	printf("------------------------------------------\n");
	int chosse;
	printf("nhap lua chon: ");
	scanf("%d", &chosse);
	return chosse;
}
void add(int* &array, int &length) {
	int new_length = length + 1;
	int new_memory = new_length + 1;
	int *tmp = (int*)malloc(new_memory * sizeof(int));
	for(int i = 0; i < length; i++) {
		tmp[i] = array[i];
	}
	printf("nhap gia tri moi: ");
	scanf("%d", &tmp[length]);
	free(array);
	printf("%d\n", tmp);
	array = tmp;
	printf("%d\n", array);
	length++;
}
void print(int array[], int length) {
	for(int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
