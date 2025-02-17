#include <stdio.h>
int main()
{
    float x[100], y[100], xp, yp = 0, p;
    int n, i, j, d = 1;

    /* Input */
    printf("C Program for Lagrenge's Interpolation Formula\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    printf("\nEnter the respective values of the variables x and y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }

    printf("\nThe table you entered is as follows: \n\n");
    for (i = 0; i < n; i++)
    {
        printf("%0.3f\t%0.3f\n", x[i], y[i]);
    }

    while (d == 1)
    {
        yp = 0;
        printf("\nEnter the value of x to find the respective value of y: ");
        scanf("%f", &xp);

        for (i = 0; i < n; i++)
        {
            p = 1;

            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    p = p * (xp - x[j]) / (x[i] - x[j]);
                }
            }
            yp += p * y[i];
        }

        printf("\nThe respective value of the variable yp at xp = %.3f is: %.3f\n", xp, yp);
        printf("\nDo you want to continue?\nPress 1 to continue and any other key to exit the program: ");
        scanf("%d", &d);
    }
    return 0;
}
