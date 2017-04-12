/*
Matthew Riddell
mriddell
005498481
CSCI 551
Assignment 3
Description - This implements a serial version of Gaussian elimination with
              partial pivoting.
*/
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
  //Forward elimination
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      /* code */
    }
  }
  return 0;
}
