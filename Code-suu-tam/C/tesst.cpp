#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);
	
	int h, m, s;
	h = input / 3600;
	input = input - (h*3600);
	m = input / 60;
	input = input - (m*60);
	s = input;
	printf("%dh%dm%ds", h, m, s);
	
	
}