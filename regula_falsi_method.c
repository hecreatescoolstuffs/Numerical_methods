#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
#define f(x) (x*x - 4*x - 10) // Example: x^2 - 4x - 10 = 0

void regula_falsi(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Incorrect initial guesses. The function must have opposite signs at a and b.\n");
        return;
    }

    double c;
    int iter = 0;

    do {
        // Regula-Falsi formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("Iteration %d: x = %.6lf, f(x) = %.6lf\n", iter + 1, c, f(c));

        if (fabs(f(c)) < tol) { // Convergence check
            printf("Root found: %.6lf\n", c);
            return;
        }

        // Update the interval based on sign
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (iter < 100); // Limit iterations to prevent infinite loop

    printf("Maximum iterations reached. Approximate root: %.6lf\n", c);
}

int main() {
    double a, b, tol;
    
    printf("Enter the initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);
    
    regula_falsi(a, b, tol);
    
    return 0;
}
