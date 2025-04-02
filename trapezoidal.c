#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x) {
    return 1 / (1 + x * x);  // Example function: f(x) = 1 / (1 + x^2)
}

// Trapezoidal Rule implementation
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

int main() {
    double a, b;
    int n;
    
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of subintervals (n): ");
    scanf("%d", &n);
    
    double result = trapezoidal_rule(a, b, n);
    printf("The approximate integral value is: %lf\n", result);
    
    return 0;
}