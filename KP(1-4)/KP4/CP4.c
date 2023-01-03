#include <stdio.h>
#include <math.h>
#include <float.h>

long double function8(long double x) {
    return ((0.6 * powl(3, x)) - (2.3 * x) - 3);
}

long double function9(long double x) {
    return sqrt(log(1 + x) + 3);
}

long double derivative(long double x) {
    return 1/(2 * (x + 1) * sqrt(log(x + 1) + 3));
}

long double move(long double (*f)(long double), long double a, long double b) {
    long double x = (a + b) / 2.0;
    long double xk = function9(x);
    while (fabsl(xk - x) > LDBL_EPSILON) {
        x = xk;
        xk = function9(x);
    }
    return xk;
}

int main() {
    long double a = 2.0;
    long double b = 3.0;
    
    if (function8(a) * function8(b) > 0) {
        printf("8. NO ROOTS\n");
    }
    else {
        while (fabsl(a - b) < LDBL_EPSILON) {
            if (function8(a) * function8((a + b) / 2) > 0) {
                a = (a + b) / 2;
                b = b;
            }
            else if (function8(b) * function8((a + b) / 2) > 0) {
                a = a;
                b = (a + b) / 2;
            }
        }
        
        printf("8. Our root is: %Lf\n", (a + b) / 2);
    }
    
    a = 2.0;
    b = 3.0;
    
    if (fabsl(derivative(a)) < 1 || fabsl(derivative(b)) < 1) {
        printf("9. Our x = %Lf\n", move(function9, a, b));
    }
    else {
        printf("No");
    }

    return 0;
}