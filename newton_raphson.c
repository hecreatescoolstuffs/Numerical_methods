#include <stdio.h>
#include <math.h>

// Function definitions
float f(float x) {
    return pow(x, 2) - 10 * x - 25;
}

float f_dash(float x) {
    return 2 * x - 10;
}

float phi(float x) {
    return x - (f(x) / f_dash(x));
}

int main() {
    float ini, root1, root2;
    
    printf("Enter the value of the initial root: ");
    scanf("%f", &ini);
    
    // Convergence criterion check
    if (fabs(f(ini) * 2) < pow(f_dash(ini), 2)) {
        root1 = phi(ini);  // x_(1)
        root2 = phi(root1); // x_(2)
        
        while (fabs(root1 - root2) > 0.0001) {
            root1 = root2;   // root1 = x_(2)
            root2 = phi(root1); // root2 = x_(3)
        }
        
        printf("\nThe required root of the equation x^2 - 10x - 25 = 0 is: %.6f\n", root1);
    } else {
        printf("\nConvergence test fails, enter another initial root.\n");
    }
    
    return 0;
}
