#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void Insert(char c, int x, char s[]) {
    //lập từ cuối đến vị trí cần chèn.
    //mỗi lần lập đẩy ra phía sau 1 ô để chừa ô trống cho giá trị mới.
    //lưu ý: strlen ko đếm \0 như nó vẫn đếm \n
    for(int i = strlen(s); i >= x; i--) {
        s[i+1] = s[i];
        printf("%s\n", s);
    }
    //thêm giá trị mới vô chổ trống.
    s[x] = c;
}

int main() {
    char input[100];

    fgets(input, sizeof(input), stdin);
    int length = strlen(input);
    if(input[9] == '\0') printf("true\n");
    printf("%d\n", length);
    Insert('-', 4, input);
    printf("%s", input);
}