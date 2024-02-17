#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int flag = 1;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			flag = 0;
		}
	}
	
	if(flag) printf("la so nt");
	else printf("dell phai");
}
