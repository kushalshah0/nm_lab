#include <stdio.h>

void gaussJordan(double a[3][4], double x[3]) {
    int i, j, k;
    double ratio;

    // Partial pivoting
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < 4; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    // Obtaining the solution
    for (i = 0; i < 3; i++) {
        x[i] = a[i][3] / a[i][i];
    }
}

int main() {
    int n, i;
    double x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumx2y = 0;
    double a, b, c;

    /* Input */
    printf("C Program for Parabola Curve Fitting\nCreated by Prabesh Babu Adhikari\n");
    printf("-----------------------------------\n\n");
    printf("Enter the value of number of terms n : ");
    scanf("%d", &n);

    printf("\nEnter the values of x : ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("\nEnter the values of y : ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumx3 += x[i] * x[i] * x[i];
        sumx4 += x[i] * x[i] * x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2y += x[i] * x[i] * y[i];
    }
    double N = n;
    double matrix[3][4] = {
        {N, sumx, sumx2, sumy},
        {sumx, sumx2, sumx3, sumxy},
        {sumx2, sumx3, sumx4, sumx2y}
    };

    double result[3];
    gaussJordan(matrix, result);

    a = result[0];
    b = result[1];
    c = result[2];

    printf("\nThe parabola is y = %0.3f + %0.3fx + %0.3fx^2\n\n", a, b, c);

    return 0;
}
