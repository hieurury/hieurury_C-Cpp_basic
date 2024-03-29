#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct Point Point;

struct Point{
   double X,Y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}


int isTriangle(Point a, Point b, Point c) {
    if(distance(a, b) + distance(b, c) <= distance(c, a)) return 0;
    if(distance(a, b) + distance(a, c) <= distance(b, c)) return 0;
    if(distance(c, b) + distance(a, c) <= distance(b, a)) return 0;
    return 1;
}

int main() {
    //code
}