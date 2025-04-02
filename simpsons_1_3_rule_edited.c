#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x) {
    return 1 / (1 + x * x);  // Example: f(x) = 1 / (1 + x^2)
}

// Simpson's 1/3 Rule implementation
double simpsons_rule(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error: n must be an even number.\n");
        return -1;
    }
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }
    
    return (h / 3) * sum;
}

int main() {
    double a, b;
    int n;
    
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of subintervals (n, even): ");
    scanf("%d", &n);
    
    double result = simpsons_rule(a, b, n);
    if (result != -1) {
        printf("The approximate integral value is: %lf\n", result);
    }
    
    return 0;
}
