#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct User User;
typedef struct Bank Bank;

struct User {
	char name[50];
	char pass[10];
};

struct Bank {
	User member;
	int balance;
	Bank *link;
};


int menu() {
	printf("----MENU----\n");
	printf("1. insert data.\n");
	printf("2. delete data.\n");
	printf("3. show length.\n");
	printf("4. show data.\n");
	printf("0. exit.\n");
	int number;
	printf("enter your choice: ");
	scanf("%d", &number);
	getchar();
	return number;
}

User createUser() {
	User newUser;
	printf("enter new name: ");
	fgets(newUser.name, sizeof(newUser.name), stdin);
	newUser.name[strcspn(newUser.name, "\n")] = '\0';
	printf("is password: ");
	fgets(newUser.pass, sizeof(newUser.pass), stdin);
	newUser.pass[strcspn(newUser.pass, "\n")] = '\0';
	return newUser;
	
}

Bank *createBank(User data) {
	Bank *newBank = (Bank*)malloc(sizeof(Bank));
	newBank->member = data;
	newBank->balance = 0;
	newBank->link = NULL;
	return newBank;
}

int count(Bank *bank) {
	int count = 0;
	while(bank != NULL) {
		count++;
		bank = bank->link;
	}
	return count;
}

void display(Bank *bank) {
	while(bank != NULL) {
		printf("name: %s | balance: %d\n", bank->member.name, bank->balance);
		bank = bank->link;
	}
}

void push(Bank **queue, User data) {
	Bank *newBank = createBank(data);
	newBank->link = *queue;
	*queue = newBank;
}

void pop(Bank **queue) {
	if(*queue == NULL) return;
	Bank *tmp = *queue;
	while(tmp->link->link != NULL) {
		tmp = tmp->link;
	}
	tmp->link = NULL;
}

int main() {
	Bank *myBank = NULL;
	int isRunning = 1;
	while(isRunning) {
		int choice = menu();
		switch(choice) {
			case 1:
				User a = createUser();
				push(&myBank, a);
				break;
			case 2:
				pop(&myBank);
				break;
			case 3:
				count(myBank);
				break;
			case 4:
				display(myBank);
				break;
			case 0:
				isRunning = 0;
				break;
			default:
				printf("...\n");
		}
	}
	
}