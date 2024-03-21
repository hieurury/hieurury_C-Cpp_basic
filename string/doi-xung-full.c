#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
    printf("%d\n", strlen(str));
    for(int i = 0; i < strlen(str)/2; i++) {
        if(str[i] != str[strlen(str) - 2 -i]) {
            printf("NO");
            return 1;
        }
        
    }
    printf("YES");
}