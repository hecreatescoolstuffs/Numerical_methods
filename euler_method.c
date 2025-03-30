#include <stdio.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;  // Example function: dy/dx = x + y
}

// Function to implement Euler's method
void euler(float x0, float y0, float xn, float h) {
    float x = x0, y = y0;

    printf("\nStep-wise Computation:\n");
    printf("x\t\ty\n");

    while (x < xn + h / 2) {  // Adjusting condition for precision
        printf("%.4f\t%.6f\n", x, y);
        y = y + h * f(x, y);  // Euler's formula: y_new = y + h*f(x, y)
        x = x + h;
    }

    printf("\nFinal solution: y(%.2f) = %.6f\n", xn, y);
}

int main() {
    float x0, y0, xn, h;

    // Input initial values
    printf("Enter the values of x0, y0, xn, and h: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &h);

    // Solve ODE using Euler’s Method
    euler(x0, y0, xn, h);

    return 0;
}
