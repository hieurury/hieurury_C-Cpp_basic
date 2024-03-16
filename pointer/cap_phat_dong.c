#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int x;
 int y;
 int z;
} P;

int main() {
    P a;
    P *b;
    b = &a;
    scanf("%d", &b->x);
    printf("%d", a.x);
}
