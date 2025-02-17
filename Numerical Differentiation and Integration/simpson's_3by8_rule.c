#include <stdio.h>
#include <math.h>
#define f(x) (sin(x)-log(x)+exp(x))

int main()
{
    float lower, upper, integral = 0.0, stepSize, k;
    int i, subInterval;

    printf("C Program for Simpson's 3/8 Rule\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter lower limit of integral : ");
    scanf("%f", &lower);
    printf("Enter upper limit of integral : ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals : ");
    scanf("%d", &subInterval);

    stepSize = (upper - lower) / subInterval; 
    integral = f(lower) + f(upper);   

    for (i = 1; i < subInterval; i++)
    {
        k = lower + i * stepSize;
        if (i % 3 == 0)
            integral = integral + 2 * f(k);
        else
            integral = integral + 3 * f(k);
    }

    integral = integral * stepSize * 3/8;
    printf("\nRequired value of integral is : %.6f\n\n", integral);
    return 0;
}