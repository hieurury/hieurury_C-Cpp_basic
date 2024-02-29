#include <stdio.h>
#include <math.h>
const double pi=3.141592653;
int giaiThua(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double cosin(double x, double e) {
    int n = 0;
    double result = 0;

    while (fabs(pow(x, 2 * n) / giaiThua(2 * n)) > e) {
        result += pow(-1, n) * pow(x, 2 * n) / giaiThua(2 * n);
        n++;
    }

    return result;
}

int main() {
   
}
