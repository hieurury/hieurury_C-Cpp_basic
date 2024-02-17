#include <stdio.h>


void Move(int n, char a, char b, char c) {
	if(n == 1) {
		printf("1: %c -> %c\n", a, c);
        return;
    }
    Move(n-1, a, c, b);
    Move(1, a, b, c);
    Move(n-1, b, a, c);
    
}

int main() {
	Move(3, 'A', 'B', 'C');
}