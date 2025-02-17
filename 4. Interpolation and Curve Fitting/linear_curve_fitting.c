#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    double a, b;

    /* Input */
    printf("C Program for Linear Curve Fitting\nCreated by Prabesh Babu Adhikari\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of number of terms (n) : ");
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
    }

    for (i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i] * y[i];
    }

    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - b * sumx) / n;
    if (b >= 0)
    {
        printf("\nThe line is y = %lf + %lfx\n\n", a, b);
    }
    else
    {
        printf("\nThe line is y = %lf - %lfx\n\n", a, -b);
    }

    return 0;
}
