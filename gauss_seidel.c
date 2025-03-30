#include <stdio.h>
#include <math.h>

float f1(float y, float z) {
    return (9 - 2 * y - z) / 10.0;
}

float f2(float x, float z) {
    return (-22 - x + z) / 10.0;
}

float f3(float x, float y) {
    return (22 + 2 * x - 3 * y) / 10.0;
}

int main() {
    float x, y, z, x1, y1, z1, eps = 0.00001;

    printf("Enter the initial approximation of the solutions: ");
    scanf("%f %f %f", &x, &y, &z);

    do {
        x1 = x;
        y1 = y;
        z1 = z;

        x = f1(y, z);  // Update x first
        y = f2(x, z);  // Use the new x for y
        z = f3(x, y);  // Use the new x and y for z

        printf("Current solution: x = %f \t y = %f \t z = %f\n", x, y, z);
    } while (fabs(x1 - x) > eps || fabs(y1 - y) > eps || fabs(z1 - z) > eps);

    printf("Final solution: x = %f \t y = %f \t z = %f\n", x, y, z);
    
    return 0;
}
