#include <stdio.h>
#include <math.h>

int main() {
    double a, e;
    
    scanf("%lf%lf", &a, &e);
    
    double x0 = (1 + a)/2;
    double xn = (x0 + a/x0)/2;
    while(fabs((xn - x0)/x0) >= e) {
        x0 = xn;
        xn = (x0 + a/x0)/2;
    }
    printf("%.8f", xn);
}