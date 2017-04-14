/*
Matthew Riddell
mriddell
005498481
CSCI 551
Assignment 3
Description - This implements a serial version of Gaussian elimination with
              partial pivoting.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char ch;
  int n = atoi(argv[1]);
  int m = n + 1;
  double *matrix = malloc (sizeof (double) * m * n);
  if (n < 5) {
    for (size_t i = 0; i < m*n; i++) {
      double tmp;
      scanf("%lf", &tmp);
      ch = getchar();
      *(matrix + i) = tmp;
    }
  }
  else {
    time_t t;
    srand48(t);
    for (int i = 0; i < m*n; i++) {
      *(matrix + i) = ((drand48() - 0.5)/0.5)*1000000;
    }
  }
  for (int i = 0; i < n-1; i++) {
    double divisor = *(matrix + n*i + i);
    for (int j = i; j < n; j++) {
      int l;
      double abs_max;
      for (int k = i+1; k < n-1; k++) {
        if (k == i+1) {abs_max = fabs(*(matrix + k*n + j));l=k;}
        else {
          double abs_tmp = fabs(*(matrix + k*n + j));
          if (abs_tmp > abs_max) {l=k;abs_max = abs_tmp;}
        }
      }
      if (l > i+1) {
        //Swap rows.
      }
      //Gaussian elimination of row.
    }
  }
  return 0;
}
