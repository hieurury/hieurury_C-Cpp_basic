#include <stdio.h>

void fibonacci(int n, int f, int e) {
    if(n > 1) {
        printf("%d, ", f);
        return fibonacci(n-1, e, f+e);
    }
    printf("%d", f);
    return;

}


int main() {
    int n;
    scanf("%d", &n);
    fibonacci(n, 0, 1);
}