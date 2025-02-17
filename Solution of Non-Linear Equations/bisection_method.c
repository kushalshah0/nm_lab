#include <stdio.h>
#include <math.h>

#define f(x) 4*exp(-x)*sin(x)-1

int main()
{
    float x0, x1, f0, f1, x2, f2, e;
    int Iterations = 1;

    /* Input */
    printf("C Program for Bisection Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
input:
    printf("Enter the value of x0 & x1 = ");
    scanf("%f%f", &x0, &x1);
    printf("Enter value of tolerable error (e) = ");
    scanf("%f", &e);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0.0)
    {
        printf("Wrong initial guesses!\n");
        goto input;
    }
    printf("\n__________________________________________________________________________\n");
    printf("\nIterations\tx0\t\tx1\t\tx2\t\tf(x2)");
    printf("\n__________________________________________________________________________\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("\n%d\t\t%f\t%f\t%f\t%f", Iterations, x0, x1, x2, f2);
        Iterations++;

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }

    } while (fabs(f2) > e);
    printf("\n__________________________________________________________________________\n");
    printf("\nThe approximate root of the equation is %0.8f\n\n", x2);
    return 0;
}
