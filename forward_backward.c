#include <stdio.h>
#include <stdlib.h>

void printForwardDifferenceTable(float x[], float y[], int n);
void printBackwardDifferenceTable(float x[], float y[], int n);

int main() {
    int n, i;
    float *x, *y;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    // Allocate memory for x and y arrays
    x = (float *)malloc(n * sizeof(float));
    y = (float *)malloc(n * sizeof(float));
    
    if (x == NULL || y == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Input data points
    printf("Enter the data points (x,y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    
    // Generate and print forward difference table
    printf("\nForward Difference Table:\n");
    printForwardDifferenceTable(x, y, n);
    
    // Generate and print backward difference table
    printf("\nBackward Difference Table:\n");
    printBackwardDifferenceTable(x, y, n);
    
    // Free allocated memory
    free(x);
    free(y);
    
    return 0;
}

void printForwardDifferenceTable(float x[], float y[], int n) {
    int i, j;
    float **forwardDiff;
    
    // Allocate memory for the difference table
    forwardDiff = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        forwardDiff[i] = (float *)malloc((n - i) * sizeof(float));
    }
    
    // Fill the first column with function values
    for (i = 0; i < n; i++) {
        forwardDiff[i][0] = y[i];
    }
    
    // Calculate the forward differences
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            forwardDiff[i][j] = forwardDiff[i + 1][j - 1] - forwardDiff[i][j - 1];
        }
    }
    
    // Print header
    printf("\nx\t  y\t");
    for (i = 1; i < n; i++) {
        printf("Δ^%d\t", i);
    }
    printf("\n");
    
    // Print the difference table
    for (i = 0; i < n; i++) {
        printf("%.2f\t%.4f\t", x[i], forwardDiff[i][0]);
        for (j = 1; j < n - i; j++) {
            printf("%.4f\t", forwardDiff[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(forwardDiff[i]);
    }
    free(forwardDiff);
}

void printBackwardDifferenceTable(float x[], float y[], int n) {
    int i, j;
    float **backwardDiff;
    
    // Allocate memory for the difference table
    backwardDiff = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        backwardDiff[i] = (float *)malloc((i + 1) * sizeof(float));
    }
    
    // Fill the first column with function values
    for (i = 0; i < n; i++) {
        backwardDiff[i][0] = y[i];
    }
    
    // Calculate the backward differences
    for (j = 1; j < n; j++) {
        for (i = j; i < n; i++) {
            backwardDiff[i][j] = backwardDiff[i][j - 1] - backwardDiff[i - 1][j - 1];
        }
    }
    
    // Print header
    printf("\nx\t  y\t");
    for (i = 1; i < n; i++) {
        printf("∇^%d\t", i);
    }
    printf("\n");
    
    // Print the difference table
    for (i = 0; i < n; i++) {
        printf("%.2f\t%.4f\t", x[i], backwardDiff[i][0]);
        for (j = 1; j <= i; j++) {
            printf("%.4f\t", backwardDiff[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(backwardDiff[i]);
    }
    free(backwardDiff);
}