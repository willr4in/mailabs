#include<stdio.h>

/* 2
   1 4
   2 3 */

/* 3
   7 6 5
   8 1 4
   9 2 3 */

/* 4
   7 6 5 16
   8 1 4 15
   9 2 3 14
   10 11 12 13 */

/* 5
   21 20 19 18 17
   22  7  6  5 16
   23  8  1  4 15
   24  9  2  3 14
   25 10 11 12 13 */

/* 6
   21 20 19 18 17 36
   22 7  6  5  16 35
   23 8  1  4  15 34
   24 9  2  3  14 33
   25 10 11 12 13 32
   26 27 28 29 30 31 */

/* 7
   43 42 41 40 39 38 37
   44 21 20 19 18 17 36
   45 22 7  6  5  16 35
   46 23 8  1  4  15 34
   47 24 9  2  3  14 33
   48 25 10 11 12 13 32
   49 26 27 28 29 30 31 */

enum {maxn = 100};

int main() {
    int m[maxn][maxn];

    int n;
    scanf_s("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf_s("%d", &m[i][j]);
        }
    }

    int help[3] = {1, 2, 3};
    int q[3] = {0, 2, 4};
    int x[3] = {-1, 1, 3};
    int y[2] = {3, 5};
    int v = 1;
    if (n % 2 == 1) {
        int l = 2;
        int d = 0;
        int i, j;
        if (n == 7) {
            i = 2;
            j = 3;
        }
        if (n == 5) {
            i = 1;
            j = 2;
        }
        if (n == 3) {
            i = 0;
            j = 1;
        }
        if (n == 1) {
            i = 0;
            j = 0;
            printf("%d", m[i][j]);
        }
        int dir[4] = {1, 0, -1, 0};
        int ftp[12] = {-1 ,1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0};
        while (l != n + 1) {
            for (int k = 0; k != l; ++k) {
                j += dir[(d + 3) % 4];
                i += dir[d % 4];
                printf("%d", m[i][j]);
                printf("%c", ' ');
            }
            if ((i == 6) && (j == 0) || (i == 4) && (j == 0) || (i == 3) && (j == 0)) {
                break;
            }
            l += ftp[d % 12];
            ++d;
        }
    }
    else {
        int p = n / 2;
        for (int i = p - 1; i >= p - help[p - 1]; i--) {
            for (int j = i; j <= n - 1 - i; j++)
                printf("%d ", m[j][i]);
            for (int j = i; j < n - 1 - i; j++)
                printf("%d ", m[n - i - 1][j + 1]);
            for (int j = q[p-1] - i; j > x[p - v] - i; j--)
                printf("%d ", m[j][n - i - 1]);
            if (i == 0) {
                break;
            }
            for (int j = y[p-2] - i; j > i - 1; j--)
                printf("%d ", m[i - 1][j]);
            v += 1;
        }
    }
    printf("\n");
    return 0;
}