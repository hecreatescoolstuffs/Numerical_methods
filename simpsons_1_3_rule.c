#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    // Example function: f(x) = x^2
    // You can replace this with any function you want to integrate
    return x * x;
}

// Trapezoidal rule implementation
double trapezoidalRule(double a, double b, int n) {
    // a: lower limit of integration
    // b: upper limit of integration
    // n: number of subintervals
    
    double h = (b - a) / n;  // Width of each subinterval
    double sum = 0.5 * (f(a) + f(b));  // First and last terms
    
    // Sum of all other terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;  // Multiply by width to get the area
}

int main() {
    double a, b;  // Integration limits
    int n;        // Number of subintervals
    
    // Get user input
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);
    
    printf("Enter number of subintervals: ");
    scanf("%d", &n);
    
    // Calculate and display the result
    double result = trapezoidalRule(a, b, n);
    printf("The integral from %.2f to %.2f using %d subintervals = %.6f\n", a, b, n, result);
    
    // Example: For f(x) = x^2 from 0 to 1, the exact value is 1/3 ˜ 0.333333
    if (a == 0 && b == 1) {
        printf("Exact value for ?x² from 0 to 1 = 0.333333\n");
        printf("Error = %.10f\n", fabs(result - 1.0/3.0));
    }
    
    return 0;
}
