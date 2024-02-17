#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    if(a < 0) a = -a;
    if(b < 0) b = -b;

    while(b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    printf("%d", a);
}