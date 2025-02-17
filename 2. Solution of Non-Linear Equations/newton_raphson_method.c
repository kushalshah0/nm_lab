#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) exp(x)-3*x
#define df(x) exp(x)-3

int main()
{
    float x0, f0, df0, x1, f1, e;
    int Iterations = 1, N;

    /* Input */
    printf("C Program for Newton Raphson Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of x0 = ");
    scanf("%f", &x0);
    printf("Enter max no. of iterations = ");
    scanf("%d", &N);
    printf("Enter value of tolerable error (e) = ");
    scanf("%f", &e);
    printf("\n__________________________________________________________________________\n");
    printf("\nIterations\tx0\t\tf(x0)\t\tx1\t\tf(x1)");
    printf("\n__________________________________________________________________________\n");

    do
    {
        f0 = f(x0);
        df0 = df(x0);

        if (df0 == 0.0)
        {
            printf("Newton Raphson Method fails i.e Math Error");
            exit(0);
        }

        x1 = x0 - (f0 / df0);
        f1 = f(x1);

        printf("\n%d\t\t%f\t%f\t%f\t%f", Iterations, x0, f0, x1, f1);

        Iterations++;
        x0 = x1;

        if (Iterations > N)
        {
            printf("\nSolution doesn't converge.");
            break;
        }

    } while (fabs(f1) > e);
    printf("\n__________________________________________________________________________\n");
    printf("\nThe approximate root of the equation is %0.8f\n\n", x1);
    return 0;
}