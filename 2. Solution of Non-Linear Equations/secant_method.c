#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// #define f(x) (x * x * x - 2 * x - 5)
#define f(x) (sin(x)-2*x+1)

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int Iterations = 1, N;

    /* Input */
    printf("C Program for Secant Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of x0 & x1 = ");
    scanf("%lf%lf", &x0, &x1);
    printf("Enter max no. of iterations = ");
    scanf("%d", &N);
    printf("Enter value of tolerable error (e) = ");
    scanf("%lf", &e);
    printf("\n___________________________________________________________________________\n");
    printf("\nIterations\tx0\t\tx1\t\tx2\t\tf(x2)");
    printf("\n___________________________________________________________________________\n");

    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (f1 == f0)
        {
            printf("\n\nSecant Method fails i.e Math Error\n\n");
            exit(0);
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);
        printf("\n%d\t\t%lf\t%lf\t%lf\t%lf", Iterations, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;

        Iterations++;

        if (Iterations > N)
        {
            printf("\n\nSolution doesn't converge.\n\n");
            break;
        }

    } while (fabs(f2) > e);
    printf("\n___________________________________________________________________________\n");
    printf("\nThe approximate root of the equation is %0.8f\n\n", x2);
    return 0;
}