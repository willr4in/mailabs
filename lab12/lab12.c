#include <stdio.h>
#include <assert.h>

int stepen(int a, int b) {
    int tmp = a;
    if (b == 0) {
        return 1;
    }
    else {
        for (int i = 1; i < b; i++) {
            a *= tmp;
        }
        return a;
    }
}

void test_stepen() {
    assert(stepen(2, 5) == 32);
    assert(stepen(1, 5) == 1);
    assert(stepen(3,2) == 9);
    assert(stepen(4, 2) == 16);
}

int main() {
    test_stepen();
    
    int a = 0, k = 0, b, c;
    scanf_s("%d", &a);
    
    a = a / 10;
    
    int tmp = a;
    while (tmp != 0) {
        tmp = tmp / 10;
        k += 1;
    }
    
    c = k - 1;
    if (c == 0) {
        printf("%d\n", c);
    }
    
    else {
        b = stepen(10, k-1);
        a = a % b;
        printf("%d\n", a);
    }
    
    return 0;
}

