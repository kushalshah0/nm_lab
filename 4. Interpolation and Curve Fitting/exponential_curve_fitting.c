#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double x[50], y[50], sumx = 0, sumY = 0, sumxY = 0, sumx2 = 0, a, b, A, Y[50];

    /* Input */
    printf("C Program for Exponential Curve Fitting\nCreated by Shishir Timilsina\n");
    printf("-----------------------------------\n\n");
    printf("Enter the number of terms (n) : ");
    scanf("%d", &n);

    printf("\nEnter the values of x : ");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    printf("\nEnter the values of y : ");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
        Y[i] = log(y[i]); // Transform y to ln(y)
    }

    for (i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumY = sumY + Y[i];
        sumxY = sumxY + x[i] * Y[i];
    }

    b = (n * sumxY - sumx * sumY) / (n * sumx2 - sumx * sumx);
    A = (sumY - b * sumx) / n;
    a = exp(A); // Transform back to get a

    printf("\nThe exponential curve is y = %0.4fe^%0.4fx\n\n", a, b);

    return 0;
}
