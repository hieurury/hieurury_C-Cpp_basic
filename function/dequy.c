#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int parent[10] = {1, 4, 2, 3, 5, 3, 1, 1, 6, 7};
int length = 0;
int child[length];
void convert(int n) {
    if(n > 0)
}

int test(int n) {
    while(n > 1) {
        return n * test(n - 1);
    }
    return n;
}

int main() {


    int a = test(5);
    printf("%d", a);
}
