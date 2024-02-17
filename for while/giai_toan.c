#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    //  TOÁN RR CÂU 39/147.
    // i là số giấy 3 đồng -> i <= 26 (nếu lớn hơn sẽ lố số tiền trả - 78 đồng)
    // j là số giấy 5 đồng -> i <= 15 (nếu lớn hơn sẽ lố số tiền trả - 78 đồng)

    //CÁCH 1 GIẢI THEO SUY LUẬN
    // for(int i = 0; i <= 2 ; i++) {
    //     for(int j = 0; ; j--) {
    //         if(38*i + 117*j == 10) printf("%d %d\n", i, j);
    //     }
    // }

    // CÁCH 2 GIẢI THEO CÔNG THỨC
    // for(int i = 0; i <= 26; i++) {
    //     int x = i;
    //     int t = (x - 156) / - 5;
    //     int y = 3*t - 78;
    //     if(3*x + 5*y == 78) printf("%d %d\n", x, y);
    // }


    // TOÁN RR BÀI 37
    // for(int i = 0; i <= 30; i++) {
    //     for(int j = 0; j <= 30 - i; j++) {
    //         int k = 30 - i - j;
    //         if(i/3 + j/2 + k*2 == 30) printf("%d %d %d\n", i, j, k);
    //     }
    // }

    //
    for(int i = -99; i < -9; i++) {
        if(i % 9 == 0 && (i + 1) % 25 == 0) printf("%d\n", i);
    }
}