#include <stdio.h>


void in_xuoi(int n) {
	if(n > 0) {
		in_xuoi(n/10);
		printf("%d ", n%10);
	}
}

int main() {
   int n;
   scanf("%d", &n);
   
   in_xuoi(n);
}