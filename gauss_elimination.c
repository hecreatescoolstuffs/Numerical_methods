#include <stdio.h>

// Function to perform Gaussian Elimination
void gaussianElimination(float a[10][11], int n) {
    int i, j, k;
    float ratio, x[10];

    // Convert the matrix into upper triangular form
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error! Division by zero.\n");
            return;
        }
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back-substitution process
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Displaying the result
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6f\n", i + 1, x[i]);
    }
}

int main() {
    float a[10][11];
    int i, j, n;

    // Input the number of variables
    printf("Enter the number of equations (variables): ");
    scanf("%d", &n);

    // Input the augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Perform Gaussian Elimination
    gaussianElimination(a, n);

    return 0;
}
