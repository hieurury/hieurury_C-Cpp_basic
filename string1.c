#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper(char *c) {
    if(*c >= 97 && *c <= 122) *c -= 32;
}
void lower(char *c) {
    if(*c >= 65 && *c <= 90) *c += 32;
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
    upper(&str[0]);
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ') upper(&str[i+1]);
        if(str[i] != ' ') lower(&str[i+1]);
    }
    printf("%s", str);
}
