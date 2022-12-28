#include <stdio.h> 
#include <float.h> 
#include <stdint.h> 
#include <math.h> 
 
uint64_t factorial(uint64_t n) { 
    uint64_t res = 1; 
    for (uint64_t i = 1; i <= n; ++i) 
        res *= i; 
 
    return res; 
} 
 
long double Taylor(uint64_t n, long double x) { 
    long double res = 0; 
    for (int i = 1; i <= n; ++i) { 
        res += (powl(-1, i) * (powl(2 * x, 2 * i))) / factorial(2 * i); 
    } 
    return res; 
} 
 
long double function(long double x) { 
    return (2 * (cos(x) * cos(x) - 1)); 
} 
 
int main() { 
    long double a = 0.0; 
    long double b = 0.5; 
 
    uint64_t n; 
 
    scanf("%ld", &n); 
    printf("n = %ld\n", n); 
    printf("Machine epsilon is equal to: %Lg\n\n", LDBL_EPSILON); 
 
    printf("        Table of values of Taylor series and standard function\n"); 
    printf("___________________________________________________________________________\n"); 
    printf("|  x  | sum of Taylor series | f(x) function value | number of iterations |\n"); 
    printf("___________________________________________________________________________\n"); 
 
    long double x = 0; 
    long double step = (b - a) / n; 
    long double func = 1; 
    int i = 0; 
    while (fabsl(func) > LDBL_EPSILON && (i < 100) && (i < n)) { 
        i += 1; 
        x += step; 
        func = function(x); 
 
        printf("|%.3llf|%.16llf|%.16llf|           %d          |\n", x, Taylor(i, x), func, i); 
    } 
 
    printf("___________________________________________________________________________\n"); 
 
    return 0; 
}