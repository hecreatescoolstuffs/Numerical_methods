#include <stdio.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;  // Example function dy/dx = x + y
}

// Function to implement Modified Euler's Method
void modifiedEuler(float x0, float y0, float xn, float h) {
    float x = x0, y = y0, y_pred, y_corr, slope1, slope2;
    
    printf("\nStep-wise Computation:\n");
    printf("x\t\ty (Predicted)\ty (Corrected)\n");
    
    while (x < xn + h / 2) {  // Adjusting condition to handle precision errors
        slope1 = f(x, y);  // First slope at (x, y)
        y_pred = y + h * slope1;  // Predictor step (Euler's method)
        
        slope2 = f(x + h, y_pred);  // Second slope at (x+h, y_pred)
        y_corr = y + (h / 2) * (slope1 + slope2);  // Corrector step
        
        printf("%.4f\t%.6f\t%.6f\n", x, y_pred, y_corr);
        
        // Update y to corrected value and increment x
        y = y_corr;
        x += h;
    }
    
    printf("\nFinal solution: y(%.2f) = %.6f\n", xn, y);
}

int main() {
    float x0, y0, xn, h;

    // Input initial conditions and step size
    printf("Enter the values of x0, y0, xn, and h: ");
    scanf("%f %f %f %f", &x0, &y0, &xn, &h);

    // Solve ODE using Modified Euler's Method
    modifiedEuler(x0, y0, xn, h);

    return 0;
}
