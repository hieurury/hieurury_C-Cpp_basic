#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
//KHỞI TẠO STRUCT
struct User {
	char name[100];
	int age;
};
//TYPEDEF ĐỂ KHAI BÁO KIỂU SẴN CHO STRUCT (SAU KHI TYPEDEF THÌ KHÔNG CẦN TỪ KHOÁ STRUCT KHI KHAI BÁO NỮA)
typedef struct User User;

//KHỞI TẠO MÀU SẮC
const char *RED = "\033[1;31m";
const char *RESETCOLOR = "\033[0m";
const char *GREEN = "\033[1;32m";
const char *BLUE = "\033[1;34m";
const char *YELLOW = "\033[1;33m";

//KHỞI TẠO HÀM
//nên khởi tạo hàm trước khi cấu trúc cho hàm để tránh các lỗi callback hoặc dùng hàm trước khai báo!
int choice();
void insert_user(User *user);
void add_user(User **users, int *length);
void print_users(User users[], int length);


int main() {
	int length = 0;
	//khởi tạo 1 con trỏ NULL để làm đối tượng chứa các giá trị sau này.
	User *users = NULL;
	int run = 1;
	while(run) {
		//gán thẳng cho hàm nhập luôn ko cần thêm đoạn nhập lằn quằn
		int number = choice();
		switch(number) {
			case 1:
				printf("%slua chon them user!\n%s", YELLOW, RESETCOLOR);
				add_user(&users, &length);
				break;
			case 2:
				printf("lua chon in ra danh sach user!\n");
				print_users(users, length);
				break;
			case 0:
				printf("%sda chon dong chuong trinh!\n", RED);
				printf("tam biet may con cho!\n%s", RESETCOLOR);
				//out thì cứ cho run = 0. dễ hiểu nghĩa hơn. 1 chạy - 0 tắt. dễ hiểu mà :)))
				run = 0;
				break;
			default:
				printf("thay co hong ma nhap tao lao vay?????\n");
		}
	}
	//không chơi nữa thì bỏ:)))
	free(users);
	//do thói quen
	return 1;
}

//HÀM NHẬP LIỆU CHO ĐỐI TƯỢNG USER
void insert_user(User *user) {
    printf("nhap ten: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng thừa.
    printf("nhap tuoi: ");
    scanf("%d", &user->age);
    getchar(); // Đọc và loại bỏ dấu xuống dòng còn lại sau hàm scanf.
}



//HÀM NẠP THÊM PHẦN TỬ VÀO LIST USERS
void add_user(User **users, int *length) {
	//dùng realloc thay cho malloc để tạo 1 mảng rộng hơn mảng chỉ định 1.
    User *tmp = realloc(*users, (*length + 1) * sizeof(User));
    if (tmp == NULL) {
        printf("%sKhong the cap phat!\n%s", RED, RESETCOLOR);
        exit(1);
    }

    insert_user(&tmp[*length]);
    (*length)++;
    *users = tmp;
}

//HÀM NÀY ĐỂ PRINT RA LIST USERS
void print_users(User *users, int length) {
	if(length == 0) {
		
		printf("%sdanh sach trong!\n%s", RED, RESETCOLOR);
		
	} else {
		
    	for (int i = 0; i < length; i++) {
        	printf("%sname: %s | age: %d\n%s",GREEN, users[i].name, users[i].age, RESETCOLOR);
    	}
	}
}


//ĐÂY LÀ HÀM NHẬP LỰA CHỌN. -> ĐỂ CUỐI TẠI LƯỜI ĐEM LÊN.
int choice() {
	printf("====MENU====\n");
	printf("1. them user\n");
	printf("2. xem danh sach\n");
	printf("0. close\n");
	int number;
	printf("nhap lua chon: ");
	scanf("%d", &number);
	getchar();//triệt tiêu dấu xuống dòng của hàm scanf
	return number;
}

