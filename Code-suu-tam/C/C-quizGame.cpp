#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

//KH?I T?O STRUCT
struct Player {
	char name[100];
	int id;
	int point;
};

struct Question {
	char name[200];
	char answer[200];
};

typedef struct Player Player;
typedef struct Question Question;

int main() {
	Player p1;
	Question q1;
}