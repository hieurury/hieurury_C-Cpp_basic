#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int f = 0;
    int e = 1;
    int tmp;
    for(int i = 0; i < n; i++) {

        if(i == 0) printf("%d", f);
        else printf(", %d", f);
        tmp = f;
        f = e;
        e += tmp;

    }
}
