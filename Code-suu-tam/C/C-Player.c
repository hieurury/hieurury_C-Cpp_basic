#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct Player {
	char name[100];
	int point;
	
};

typedef struct Player Player;

void add_player(Player *players, int *length) {
	Player *tmp[*length + 1];
	
	for(int i = 0; i < length; i++) {
		tmp[i] = players[i];
	}
	
	printf("nhap ten: ");
	gets(tmp[length]->name);
	printf("nhap diem: ");
	scanf("%d", tmp[length]->point);
	
	&players = &tmp;
	length++;
	printf("da them thanh cong!");
}

int main() {
	int length = 0;
	Player players[length];
	return 1;
}