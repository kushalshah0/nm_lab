#include <stdio.h>
#include <math.h>

#define f(x) 1 / (1 + pow(x, 2))

int main()
{
    float lower, upper, integral = 0.0, stepSize, k;
    int subInterval;

    /* Input */
    printf("C Program for Trapezoidal Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of lower limit : ");
    scanf("%f", &lower);
    printf("Enter the value of upper limit : ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals : ");
    scanf("%d", &subInterval);

    // Computation
    stepSize = (upper - lower) / subInterval;
    integral = f(lower) + f(upper);
    for (int i = 1; i < subInterval; i++)
    {
        k = lower + i * stepSize;
        integral = integral + 2 * f(k);
    }
    integral = integral * stepSize / 2;
    printf("\nRequired value of integral is : %.3f\n\n", integral);
    return 0;
}


// In our application of Simpson's 1/3 Rule for numerical integration, we observed that the method yields accurate approximations for smooth functions, particularly when a larger number of segments is used. The results demonstrated that the rule effectively captures the behavior of continuous and differentiable functions, providing estimates that closely align with exact integral values. However, the accuracy diminishes for functions with high curvature or discontinuities. Overall, Simpson's 1/3 Rule proves to be a valuable numerical technique, especially in scenarios where analytical integration is challenging, and further exploration of higher-order methods could enhance its applicability and precision for a broader range of functions.