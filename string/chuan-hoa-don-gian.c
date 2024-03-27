#include <stdio.h>
#include <string.h>

void upper(char *c) {
    if(*c >= 97 && *c <= 122) *c -= 32;
}

void lower(char *c) {
    if(*c >= 65 && *c <= 90)  *c +=32;
}

int main() {
    char input[100];
    
    fgets(input, sizeof(input), stdin);
    printf("%s", input);
    upper(&input[0]);
    for(int i = 1; i < strlen(input); i++) {
        lower(&input[i]);
        if(input[i] != ' ' && input[i-1] == ' ') upper(&input[i]);
    }
    printf("%s", input);
}