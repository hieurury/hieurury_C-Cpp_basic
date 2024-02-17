#include <stdio.h>
int is_Armstrong(int n){
    int a ; int sum = 0;
    int temp = n;
    while(n != 0 ){
        a = n%10;
        sum += a*a*a;
        n/=10;
    }
    if(sum == temp) return 1;
    return 0;
}

int main() {
    printf("%d ", is_Armstrong(153));
    return 0;
}