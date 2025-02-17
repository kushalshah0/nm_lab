#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n, i, j, k;
  float a[20][20], x[20], ratio, sum = 0;
  /* Input */
  printf("C Program for Gauss Elimination Method\nCreated by Kushal Shah\n");
  printf("-----------------------------------\n\n");
  printf("Enter the number of unknowns: ");
  scanf("%d", &n);
  printf("\nEnter the elements of the augmented matrix (a[i][j]):\n");
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
      printf("Mathematical error i.e Gauss Elimination method cannot be applied.\n");
      exit(1);
    }
  }

  for (j = 1; j < n; j++)
  {
    for (i = 1; i <= n; i++)
    {
      if (i > j)
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
    printf("Infinite solutions exist, the system is consistent.\n");
    exit(0);
  }

  if (a[n][n] == 0.0 && a[n][n + 1] != 0.0)
  {
    printf("No solution exists, the system is inconsistent.\n");
    exit(0);
  }

  else
  {
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--)
    {
      for (j = i + 1; j <= n; j++)
      {
        sum = sum + a[i][j] * x[j];
      }
      x[i] = (a[i][n + 1] - sum) / a[i][i];
      sum = 0;
    }

    printf("\nThe required real approximate solution is:\n");
    for (i = 1; i <= n; i++)
    {
      printf("x[%d] = %0.6f\n", i, x[i]);
    }
    printf("\n");
  }
  return 0;
}