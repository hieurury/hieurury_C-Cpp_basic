#include <stdio.h>

int main()
{
    long long int a, b, c, d;
    scanf("%lli%lli%lli%lli", &a, &b, &c, &d);
    
    if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 0){
        printf("No odd number found.");}
    else{
        long long int min=10000000000;
        
        if(a % 2 != 0 && a <= min)
            min=a;
        if(b % 2 != 0 && b <= min)
            min=b;
        if(c % 2 != 0 && c <= min)
            min=c;
        if(d % 2 != 0 && d <= min)
            min = d;
        printf("%lli",min);   
    }
    return 0;
}