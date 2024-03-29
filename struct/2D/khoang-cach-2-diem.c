#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct Point Point;

struct Point {
    double X;
    double Y;
};



double distance(Point a, Point b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

int main() {
    //code
}