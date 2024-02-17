#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT CHO KIEU DU LIEU NGUOI CHOI
struct Player {
	char name[100];
	int point;
	
	void create() {
		printf("nhap ten: ");
		fflush(stdin);
		gets(this->name);
		printf("nhap diem: ");
		scanf("%d", &this->point);
	}
	
	void print() {
		printf("Ten: %s | Diem so: %d\n", this->name, this->point);
	}
};

struct Quesion {
	char name[200];
	int answer;
	
	void create() {
		printf("nhap cau hoi: ");
		fflush(stdin);
		gets(this->name);
		while(1) {
			printf("dap an: ");
			scanf("%d", &this->answer);
			if(this->answer != 0 && this->answer != 1) {
				printf("dap an phai thuoc 0 hoac 1 (false/true)\n");
			} else {
				break;
			}
		}
	}
	
	void print() {
		printf("Cau hoi: %s | Dap an: %d\n",this->name, this->answer);
	}
};

//KHOI TAO HÀM

int menu();
void add_player(Player* &players, int &player_length);
void print_player(Player* &players, int player_length);
void delete_player(Player* &players, int &player_length);
void rank_player(Player* &players, int player_length);

//VIET CODE O DAY
int main() {
	int player_length = 0;
	Player *players = (Player*)malloc(1 * sizeof(Player));
	
	int is_run = 1;
	while(is_run) {
		int your_chosse = menu();
		system("cls");
		switch(your_chosse) {
			case 1:
				printf("da chon nap them player:\n");
				add_player(players, player_length);
				break;
			case 2:
				printf("da chon in ra danh sach player:\n");
				print_player(players, player_length);
				break;
			case 3:
				printf("da chon xoa player them ten:\n");
				delete_player(players, player_length);
				break;
			case 4:
				printf("da chon sap xep player theo diem so:\n");
				rank_player(players, player_length);
				break;
			case 0:
				printf("da chon ket thuc chuong trinh!\n");
				is_run = 0;
				break;
			default:
				printf("lua chon khong hop le!\n");
		}
	}
	return 1;
	
}
//HAM IN RA DANH SACH LUA CHON
int menu() {
	printf("----------------------------\n");
	printf("=== MENU ===\n");
	printf("1. nap them player\n");
	printf("2. in ra danh sach player\n");
	printf("3. xoa player theo ten\n");
	printf("4. sap xep lai player theo diem so\n");
	printf("0. ket thuc chuong trinh\n");
	printf("\n-------\n\n");
	int number;
	printf("lua chon cua ban: ");
	scanf("%d", &number);
	return number;
}

//HAM THEM NGUOI CHOI VAO CUOI DANH SACH
void add_player(Player* &players, int &player_length) {
	int new_player_length = player_length + 1;
	int memory = new_player_length;
	Player *tmp = (Player*)malloc(memory * sizeof(Player));
	
	for(int i = 0; i < player_length; i++) {
		tmp[i] = players[i];
	}
	
	tmp[player_length].create();
	free(players);
	players = tmp;
	player_length++;
	printf("da them thanh cong!\n");
}

//HAM IN RA DANH SACH NGUOI CHOI
void print_player(Player* &players, int player_length) {
	if(player_length == 0) {
		printf("danh sach trong!\n");
		return;
	}
	for(int i = 0; i < player_length; i++) {
		players[i].print();
	}
}

//HAM XOA NGUOI CHOI THEO TEN
void delete_player(Player* &players, int &player_length) {
	int index = -1;
	int new_player_length = player_length - 1;
	int memory = new_player_length;
	Player *tmp = (Player*)malloc(memory * sizeof(Player));
	char tmp_name[100];
	printf("nhap ten can xoa: ");
	fflush(stdin);
	gets(tmp_name);
	for(int i = 0; i < player_length; i++) {
		if(strcmp(tmp_name, players[i].name) == 0) {
			index = i;
			break;
		}
	}
	if(index == -1) {
		printf("khong tim thay nguoi choi!\n");
		return;
	}
	for(int i = index; i < player_length - 1; i++) {
		players[i] = players[i + 1];
	}
	for(int i = 0; i < new_player_length; i++) {
		tmp[i] = players[i];
	}
	free(players);
	players = tmp;
	player_length--;
	printf("da xoa thanh cong!\n");
}

//HAM SAP XEP NGUOI CHOI THEO DIEM SO

void rank_player(Player* &players, int player_length) {
	for(int i = player_length - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			if(players[j].point < players[j + 1].point) {
				Player tmp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = tmp;
			}
		}
	}
	printf("da sap xep xong!\n");
}
