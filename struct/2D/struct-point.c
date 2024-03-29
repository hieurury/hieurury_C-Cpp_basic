#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct Point Point;

struct Point {
  double x;
  double y;
};

Point readPoint() {
    struct Point tmp;
    scanf("%lf%lf", &tmp.x, &tmp.y);
    return tmp;
    
}

void printPoint(Point a) {
    printf("(%.3lf, %.3lf)", a.x, a.y);
}

int main() {
    
}