#include <stdio.h>
#include <math.h>
#define f(x) (x * x * x - 2 * x - 5)
int main()
{

    float x0, x1, x2, f0, f1, f2, e;
    int Iterations = 1;
    printf("C Program for False Position Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n");
/* Inputs */
input:
    printf("\nEnter initial guesses x0 & x1 = ");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable error = ");
    scanf("%f", &e);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0.0)
    {
        printf("Wrong initial guesses.\n");
        goto input;
    }
    printf("\n__________________________________________________________________________\n");
    printf("\nIterations\tx0\t\tx1\t\tx2\t\tf(x2)");
    printf("\n__________________________________________________________________________\n");
    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);
        printf("\n%d\t\t%f\t%f\t%f\t%f", Iterations, x0, x1, x2, f2);

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
        Iterations++;

    } while (fabs(f2) > e);
    printf("\n__________________________________________________________________________\n");
    printf("\nThe approximate root of the equation is %0.8f\n\n", x2);
    return 0;
}