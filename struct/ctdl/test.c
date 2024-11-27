#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char name[50];
    int n;
    scanf("%d", &n);
    getchar();
    fgets(name, sizeof(name), stdin);
    printf("%s %d", name, n);
}