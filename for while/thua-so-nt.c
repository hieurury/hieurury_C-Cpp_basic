#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    int i = 2;
    while(n > 1) {
        if(n % i == 0) {
            printf("%d ", i);
            n /= i;
        } else i++;
    }
}