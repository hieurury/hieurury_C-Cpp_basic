#include <stdio.h>

int main()
{
    int a, b, s1, s2, s3;
    scanf("%d",&a);
    
    s1 = a / 100;
    s2 = ( a / 10 ) % 10;
    s3 = a % 10;
    if(s1 == s2 && s2 == s3 && s1 == s3)
        printf("yes");
    else
        printf("no");
    
    return 0;
}