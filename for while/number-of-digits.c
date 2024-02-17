#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int result = 0;
    do {
    	result++;
    	n /= 10;
	} while(n > 0);
    printf("Number of digits: %d", result);
}