#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++) {
        int result = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", result);
            result = result * (i - j) / (j + 1);
        }

        printf("\n");
    }
    return 0;
}
