#include <stdio.h>
#include <math.h>
#define f(x, y) (x * x + y)

int main()
{
    int i, j, c;
    float x[100], y[100], m[100], s[100], m1, m2, a, h, w;
    printf("C Program for Modified Euler's Method\nCreated by Kushal Shah\n");
    printf("-----------------------------------\n\n");
    printf("Enter initial conditions x : ");
    scanf("%f", &x[0]);
    printf("Enter value of increment h : ");
    scanf("%f", &h);
    printf("Enter final value of x : ");
    scanf("%f", &a);
    printf("Enter initial value of y : ");
    scanf("%f", &y[0]);
    s[0] = y[0];
    for (i = 1; x[i - 1] < a; i++)
    {
        w = 100.0;
        x[i] = x[i - 1] + h;
        m[i] = f(x[i - 1], y[i - 1]);
        c = 0;
        while (w > 0.0001)
        {
            m1 = f(x[i], s[c]);
            m2 = (m[i] + m1) / 2;
            s[c + 1] = y[i - 1] + m2 * h;
            w = s[c] - s[c + 1];
            w = fabs(w);
            c = c + 1;
        }
        y[i] = s[c];
    }
    printf("\nThe respective values of x and y are :\nx \t\t y\n\n");
    for (j = 0; j < i; j++)
    {
        printf("%f\t%f", x[j], y[j]);
        printf("\n");
    }
    return 0;
}