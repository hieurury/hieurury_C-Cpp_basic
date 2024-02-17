#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        if(i != n) printf("%d, ", i);
        else printf("%d$", i);
    }
}