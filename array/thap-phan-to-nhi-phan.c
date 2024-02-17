#include <stdio.h>



int main() {
    int n;
    scanf("%d", &n);

    int bin[64];

    int index = 0;

    while(n > 0) {
        bin[index] = n % 2;
        index++;
        n /= 2;
    }

    for(int i = index - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }

}