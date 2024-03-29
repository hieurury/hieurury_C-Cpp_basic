#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>

typedef struct Point Point;
typedef struct Rect Rect;

struct Point {
    double X;
    double Y;
};
struct Rect {
    Point UR;
    Point LL;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

double area(Rect t) {
    Point UL = {t.LL.X, t.UR.Y};
    
    double lineTop = distance(UL, t.UR);
    double lineLeft = distance(UL, t.LL);
    return lineLeft*lineTop;
}

int main() {
    Rect r = {{10, 2}, {2, 8}};
    double rs = area(r);
    printf("%.4lf", rs);
}