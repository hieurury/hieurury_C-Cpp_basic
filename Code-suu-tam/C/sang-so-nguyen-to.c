#include <stdio.h>
#include <math.h>



int array[1000001];
void sang_so() {
	for(int i = 0; i <= 1000000; i++) {
		array[i] = 1;
	}
	
	array[0] = array[1] = 0;
	
	for(int i = 2; i <= sqrt(1000000); i++) {		
			for(int j = i * i; j <= 1000000; j += i) {
				array[j] = 0;
			}		
	}
}

int main() {
	int n;
	sang_so();
	printf("nhap n: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		if(array[i]) {
			printf("%d ", i);
		}
	}
	return 1;
}