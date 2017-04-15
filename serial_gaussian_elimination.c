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
#include <time.h>

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  int m = n + 1;
  double *matrix = malloc (sizeof (double) * m * n);
  if (n < 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        double tmp = 0.0;
        scanf("%lf", &tmp);
        *(matrix + i*m + j) = tmp;
      }
    }
  }
  else {
    srand48(time(0));
    for (int i = 0; i < m*n; i++) {
      *(matrix + i) = ((drand48() - 0.5)/0.5)*1000000;
    }
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.10e", *(matrix + i*m + j));
      if (j<m-1) {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("\n\n");

  for (int i = 0; i < n-1; i++) { //For each matrix element along the diagonal.
    double denominator = *(matrix + i*n + i);
    if (denominator == 0.0) { //If any diagonal would cause a divide-by-zero issue.
      for (int j = i+1; j < n-1; j++) { //In same column, find non-zero row.
        if (*(matrix + j*m + i) != 0.0) {
          for (int k = 0; k < m; k++) {
            double tmp = *(matrix + i*m + k);
            *(matrix + i*m + k) = *(matrix + j*m + k);
            *(matrix + j*m + k) = tmp;
          }
          break;
        }
      }
    }
    denominator = *(matrix + i*m + i);
    if (denominator != 0.0) { //As long as at least one row had a non-zero value
      for (int j = i+1; j < n; j++) { //For each column in the row below diagonal.
        double numerator = *(matrix + j*m + i);
        for (int k = i; k < m; k++) { //For each element in the row.
          double relim = *(matrix + i*m + k);
          *(matrix + j*m + k) = *(matrix + j*m + k) - relim*numerator/denominator;
        }
      }
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.10e", *(matrix + i*m + j));
      if (j<m-1) {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
