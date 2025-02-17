#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define g(x) (exp(x)/3)

int main()
{
    float x0, x1, e;
    int Iterations = 1, N;

    /* Input */
    printf("C Program for Fixed Point Iteration Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the initial guess x0 = ");
    scanf("%f", &x0);
    printf("Enter max no. of iterations = ");
    scanf("%d", &N);
    printf("Enter value of tolerable error (e) = ");
    scanf("%f", &e);
    printf("\n__________________________________________________________________________\n");
    printf("\nIterations\tx0\t\tg(x0)\t\tx1\t\tError");
    printf("\n__________________________________________________________________________\n");

    do
    {
        x1 = g(x0);
        printf("\n%d\t\t%f\t%f\t%f\t%f", Iterations, x0, g(x0), x1, fabs(x1 - x0));

        if (fabs(x1 - x0) < e)
        {
            printf("\n__________________________________________________________________________\n");
            printf("\nThe approximate root of the equation is %0.8f\n\n", x1);
            break;
        }

        x0 = x1;
        Iterations++;

        if (Iterations > N)
        {
            printf("\nSolution doesn't converge.\n\n");
            exit(0);
        }

    } while (1);

    return 0;
}