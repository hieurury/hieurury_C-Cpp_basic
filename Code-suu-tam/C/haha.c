#include <stdio.h>
typedef struct User {
	int id;
	char name[100];
	float point;
	int true_answers;
	
	
	
	
} User; 

typedef struct Quiz {
	char question[100];
	char answer[100];
} Quiz;

void add_user(User &user) {
	printf("id: ");
	scanf("%d", &user.id);
	fflush(stdin);
	printf("name: ");
	gets(user.name);
}


void print_user(User user) {
		printf("name: %s\n", user.name);
		printf("name and id: %s %d\n", user.name, user.id);
		printf("point: %.2f\n", user.point);
		printf("true answers: %d\n", user.true_answers);
}

int main() {
	User firstUser;
	add_user(firstUser);
	print_user(firstUser);
	return 1;
}