#include<stdio.h>

int main() {
    int k = 0, stbmax = 0, stbmin = 0, n, max = 0, min = 0, matrix[100][100] = {0};
    printf("size of matrix: ");
    scanf_s("%d", &n);
    while (n <= 0) {
        printf("Incorrect matrix size is entered\nEnter the size of the matrix: ");
        scanf_s("%d", &n);
    }
    printf("Enter the matrix elements matrix: ");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf_s("%d", &matrix[i][j]);
    printf("Original matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    max = matrix[0][0];
    min = matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                stbmax = j;
            }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] < min) {
                max = matrix[i][j];
                stbmin = j;
            }
    }
    if (stbmin != stbmax) {
        for(int i = 0; i < n; i++) {
            k = matrix[i][stbmin];
            matrix[i][stbmin] = matrix[i][stbmax];
            matrix[i][stbmax] = k;
        }
    }
    printf("Received matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
