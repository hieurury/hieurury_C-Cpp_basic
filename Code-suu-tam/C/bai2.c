#include <stdio.h>
#include <string.h>

void checkInput(char input[]) {
    int length = strlen(input) - 1;
    
    if(input[0] < 65 || input[0] > 90 || input[1] < 65 || input[1] > 90 ) {
            printf("not valid");
            return;
    }
    int index;
    for(int i = 2; i < length; i++) {
        if(input[i] == '_') {
            index = i;
            if(input[index + 1] < 65 || input[index + 1] > 90 || input[index + 2] < 65 || input[index + 2] > 90 ) {
                printf("not valid");
                return;
            }
        }
    }
    
    for(int i = index - 1; i > 1; i--) {
        if(input[i] > 57 || input[i] < 48) {
            printf("not valid");
            return;
        }
    }
    for(int i = index + 3; i < length; i++) {
        if(input[i] > 57 || input[i] < 48) {
            printf("not valid");
            return;
        }
    }
    
    printf("valid");
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    checkInput(input);
}