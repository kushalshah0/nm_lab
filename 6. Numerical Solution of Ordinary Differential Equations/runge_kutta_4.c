#include <stdio.h>
#define f(x, y) (y * y - x * x) / (y * y + x * x)

int main()
{
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;
    int i, n;
    /* Input */
    printf("C Program for 4th Order Runge-Kutta Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of initial conditions x0 and y0 : ");
    scanf("%f%f", &x0, &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    h = (xn - x0) / n; /* Calculating step size (h) */
    printf("________________________\n");
    printf("\nx0\ty0\tyn\n"); /* Runge Kutta Method */
    printf("________________________\n\n");

    for (i = 0; i < n; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f((x0 + h / 2), (y0 + k1 / 2));
        k3 = h * f((x0 + h / 2), (y0 + k2 / 2));
        k4 = h * f((x0 + h), (y0 + k3));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        yn = y0 + k;
        printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }

    /* Displaying result */
    printf("________________________\n\n");
    printf("The approximate value of y at x = %0.3f is %0.5f\n\n", xn, yn);
    return 0;
}