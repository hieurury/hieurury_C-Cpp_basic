#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char first[100];
    char second[100];

    fgets(first, sizeof(first), stdin);
    fgets(second, sizeof(second), stdin);

    int result = strcmp(first, second);

    printf("%d", result);
}