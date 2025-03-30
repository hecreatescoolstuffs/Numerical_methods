#include <stdio.h>
#include <math.h>  // Required for fabs() function

int main() {
    double exact, approximate;
    
    // Input values
    printf("Enter the exact value: ");
    scanf("%lf", &exact);
    printf("Enter the approximate value: ");
    scanf("%lf", &approximate);
    
    // Calculate errors
    double absolute_error = fabs(approximate - exact);
    double relative_error = absolute_error / fabs(exact);
    double percentage_error = relative_error * 100;
    
    // Display results
    printf("\nAbsolute Error: %lf\n", absolute_error);
    printf("Relative Error: %lf\n", relative_error);
    printf("Relative Percentage Error: %lf%%\n", percentage_error);
    
    return 0;
}