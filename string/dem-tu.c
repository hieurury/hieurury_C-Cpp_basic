#include <stdio.h>
#include <string.h>

void del(char s[], int x) {
    int len = strlen(s);
    for(int i = x; i < len- 1; i++) {
        s[i] = s[i+1];
    }
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    printf("%s", input);
    int count = 1;
    
    //cách 1 - các dạng không có dấu cách ở đầu
    // for(int i = 0; i < strlen(input); i++) {
    //     if(input[i] == ' ' && input[i+1] != ' ') count++;
    // }
    
    //cách 2 - xử lí được mọi trường hợp
    int run = 1;
    while(run) {
        run = 0;
        for(int i = 0; i < strlen(input) - 1; i++) {
            if(input[0] == ' ') del(input, i);
            if(input[i] == ' ' && input[i+1] == ' ') {
                del(input, i);
                run = 1;
            }
        }
    }
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') count++;
    }
    
    printf("%d", count);
    
}