#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i <= n; i++) {
        int value = 1;
        for(int j = 0; j <= i; j++) {
            printf("%d ", value);
            value = value * (i-j) / (j + 1);
        }
        printf("\n");
    }
}