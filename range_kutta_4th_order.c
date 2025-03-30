#include <stdio.h>
#include <math.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;  // Example function
}

int main() {
    float x0, y0, xn, x, y, h, k1, k2, k3, k4;
    int i;

    // Input initial values
    printf("Enter the values of x0, y0, xn, and h: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &h);

    x = x0;
    y = y0;

    // Runge-Kutta 4th Order Method
    while (x < xn + h / 2) {  // Adjust to prevent floating-point errors
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        k4 = h * f(x + h, y + k3);
        y = y + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x = x + h;
    }

    // Output the result
    printf("The solution of the differential equation is y(%.2f) = %f\n", xn, y);

    return 0;
}
