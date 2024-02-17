#include <stdio.h>
#include <math.h>

int main() {
    double a, n;
    double e;
    scanf("%lf%lf%lf", &a, &n, &e);
    
    double x0 = a/n;
    double xk = fabs(((n-1)*pow(x0, n)+a) / (n*pow(x0, n-1)));
    while(fabs(a-pow(xk, n)) >= e) {
        x0 = xk;
        xk = fabs(((n-1)*pow(x0, n)+a) / (n*pow(x0, n-1)));
    }
    printf("%.8f", xk);
}