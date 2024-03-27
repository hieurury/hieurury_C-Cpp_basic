#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int Compare(char s1[], char s2[]) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(toupper(s1[i]) > toupper(s2[i])) return 1;
        else if(toupper(s1[i]) < toupper(s2[i])) return -1;
        i++;
    }
    return 0;
}

int main() {
    char input1[100];
    char input2[100];

    fgets(input1, sizeof(input1), stdin);
    fgets(input2, sizeof(input2), stdin);

    int result = Compare(input1, input2);
    printf("%d", result);
}