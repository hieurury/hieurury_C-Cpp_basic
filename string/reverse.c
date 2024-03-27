#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


//chưa loại '\n' ở cuối;
void reverse(char s[]) {
    int length = strlen(s) - 2;
    for(int i = 0; i < length/2; i++) {
        char tmp = s[i];
        s[i] = s[length - i];
        s[length - i] = tmp;

    }
    s[strlen(s) - 1] = '\0';
}

//đã loại '\n' ở cuối
void reverse2(char s[]) {
    int length = strlen(s) - 1;
    for(int i = 0; i <= length/2; i++) {
        char tmp = s[i];
        s[i] = s[length - i];
        s[length - i] = tmp;
    }
    s[strlen(s)] = '\0';
}

int main() {
    char input[100];

    fgets(input, sizeof(input), stdin);
    printf("%s", input);

    int length = strlen(input);
    // printf("%d", length);
    reverse(input);
    // printf("%s", input);
    puts(input);


}