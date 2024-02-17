#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_Armstrong(int n) {

    int tmp = n;
    int value = 0;
    int k = 0;
    while(tmp > 0) {
        k++;
        tmp /= 10;
    }
    tmp = n;
    while(tmp > 0) {
        value += pow(tmp%10, k);
        printf("%d %d\n", tmp%10, value);
        tmp /= 10;
    }
    return value == n;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", is_Armstrong(n));
}