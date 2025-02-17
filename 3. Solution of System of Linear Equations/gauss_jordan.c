#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n, i, j, k; 
  float a[20][20], x[20], ratio;

  /* Input */
  printf("C Program for Gauss Jordan Method\nCreated by Kushal Shah\n");
  printf("-----------------------------------\n\n");

  printf("Enter the number of unknowns: ");
  scanf("%d", &n);
  printf("\nEnter the coefficients of the augmented matrix (a[i][j]):\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n + 1; j++)
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%f", &a[i][j]);
    }
  }

  for (i = 1; i <= n - 1; i++)
  {
    if (a[i][i] == 0.0)
    {
      printf("Mathematical error i.e Gauss Jordan method cannot be applied.\n");
      exit(1);
    }
  }

  for (j = 1; j <= n; j++)
  {
    for (i = 1; i <= n; i++)
    {
      if (i != j)
      {
        ratio = a[i][j] / a[j][j];
        for (k = 1; k <= n + 1; k++)
        {
          a[i][k] = a[i][k] - ratio * a[j][k];
        }
      }
    }
  }

  if (a[n][n] == 0.0 && a[n][n + 1] == 0.0)
  {
    printf("The system has infinite solutions and is consistent.\n");
    exit(0);
  }

  if (a[n][n] == 0.0 && a[n][n + 1] != 0.0)
  {
    printf("The system has no solution and is inconsistent.\n");
    exit(0);
  }

  else
  {
    for (int i = 1; i <= n; i++)
    {
      x[i] = a[i][n + 1] / a[i][i];
    }

    printf("\nThe real approximate solution to the system is:\n");
    for (i = 1; i <= n; i++)
    {
      printf("x[%d] = %0.6f\n", i, x[i]);
    }
    printf("\n");
  }
  return 0;
}