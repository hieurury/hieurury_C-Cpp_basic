#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int d, m, y;
    scanf("%d%d%d", &d, &m, &y);
    

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 ) {
        if (d == 31) {
            if (m == 12) {
                printf("%02d/%02d/%d",1,  1, (y + 1));

            }else {
                printf("%02d/%02d/%d",1,  m+ 1, y);

            }
        }else  {
                printf("%02d/%02d/%d",d+1,  m, y);
        }
        
        

    } else if ( m == 4 || m == 6 || m == 9 || m == 11) {
        if (d == 30) {
            printf("%02d/%02d/%d",1,  m+1, y);
        } else {
            printf("%02d/%02d/%d",d+1,  m, y);
        }

    } else {
    
        
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            if (d == 29) {
                printf("%02d/%02d/%d",1,  m+1, y);
            } else {
                printf("%02d/%02d/%d",d+1,  m, y);
            }      
        } else {
            if (d == 28) {
                printf("%02d/%02d/%d",1,  m+1, y);
            } else {
                printf("%02d/%02d/%d",d+1,  m, y);
            }

        }
    }
}