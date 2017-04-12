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
  int n = atoi(argv[1]);
  int m = n + 1;
  double *matrix = malloc (sizeof (double) * m * n);
  if (n < 5) {
    /* code */
  }
  else {
    time_t t;
    srand48(t);
    for (int i = 0; i < m*n; i++) {
      *(matrix + i) = (drand48() - 0.5)*1000000;
    }
  }
  return 0;
}
