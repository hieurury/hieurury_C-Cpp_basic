#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct Point Point;
typedef struct Rect Rect;

struct Point {
    double X,Y;
};
struct Rect {
    Point UR,LL;
};

//này tách ra kiểm tra xem điểm x có thuộc đoạn a-b không
int check(double a, double b, double x) {
    double value = (x-a)/(b-a);
    if(value >= 0 && value <= 1) return 1;
    return 0;
}

//này là kiểm tra xem có thuộc hcn không
int isIn(Point m, Rect t) {
    //kiểm tra là X của điểm m thuộc cạnh ngang của hcn(theo hình chiếu lên OX);
    //kiểm tra là Y của điểm m thuộc cạnh bên của hcn(theo hình chiếu lên OY);
    //kết hợp 2 cái vào điều kiện if rồi trả đáp án.
    if(check(t.LL.X, t.UR.X, m.X) && check(t.LL.Y, t.UR.Y, m.Y)) return 1;
    return 0;
}



int main() {
    //code
}