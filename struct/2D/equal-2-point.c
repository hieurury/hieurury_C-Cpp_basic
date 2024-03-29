#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct Point Point;

struct Point {
    double X;
    double Y;
};

int equal(Point a, Point b, double e) {
    double result = sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
    if(result > e) return 0;
    return 1;
}

int main() {
    
}