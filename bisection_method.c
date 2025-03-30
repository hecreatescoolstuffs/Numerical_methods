#include <stdio.h>
#include <math.h>

// Define the function for which we are finding the root
#define FUNC(x) ((x) * (x) * (x) - 4 * (x) - 9) // Example: f(x) = x^3 - 4x - 9

void bisection(double a, double b, double tol) {
    if (FUNC(a) * FUNC(b) >= 0) {
        printf("Invalid interval! The function must have opposite signs at a and b.\n");
        return;
    }
    
    double c;
    int iteration = 1;
    
    printf("Iter\t a\t	 b\t	 c\t	 f(c)\n");
    do {
        c = (a + b) / 2; // Midpoint
        
        printf("%d\t %lf\t %lf\t %lf\t %lf\n", iteration, a, b, c, FUNC(c));
        
        if (fabs(FUNC(c)) < tol) { // If f(c) is close enough to zero, stop
            break;
        }
        
        if (FUNC(a) * FUNC(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        iteration++;
    } while ((b - a) >= tol);
    
    printf("\nApproximate root: %lf\n", c);
}

int main() {
    double a, b, tol;
    
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);
    
    bisection(a, b, tol);
    
    return 0;
}
