/*
Matthew Riddell
mriddell
005498481
CSCI 551
Assignment 3
Description - This implements a serial version of Gaussian elimination with
              partial pivoting.
*/
#define _XOPEN_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  struct timeval user_time, sys_time;
  struct rusage ru;
  int n = atoi(argv[1]);
  int m = n + 1;
  double *matrix = malloc (sizeof (double) * m * n);
  double *ortrix = malloc (sizeof (double) * m * n);
  double *answers = malloc (sizeof (double) *n);
  double *average = malloc (sizeof (double) *n);
  if (n < 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        double tmp = 0.0;
        scanf("%lf", &tmp);
        *(matrix + i*m + j) = tmp;
        *(ortrix + i*m + j) = tmp;
        *(average + i) = *(average + i) + tmp/m;
      }
      *(answers + i) = 0.0;
    }
  }
  else {
    srand48(time(0));
    for (int i = 0; i < m*n; i++) {
      double tmp = ((drand48() - 0.5)/0.5)*1000000;
      *(matrix + i) = tmp;
      *(ortrix + i) = tmp;
    }
    for (int i = 0; i < n; i++) {
      *(average + i) = 0.0;
      *(answers + i) = 0.0;
      for (int j = 0; j < m; j++) {
        *(average + i) = *(average + i) + *(matrix + i*m + j)/m;
      }
    }
  }

  for (int i = 0; i < n-1; i++) { //For each matrix element along the diagonal.
    //Check for scaling issue first.
    double multiplier = *(matrix + i*m + i);
    if (multiplier == 0.0) { //If any diagonal would cause a divide-by-zero issue.
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
    multiplier = *(matrix + i*m + i);
    if (multiplier != 0.0) { //As long as at least one row had a non-zero value
      for (int j = i+1; j < n; j++) { //For each column in the row below diagonal.
        double factor = *(matrix + j*m + i);
        for (int k = i; k < m; k++) { //For each element in the row.
          double s_elim = *(matrix + i*m + k);
          double c_elim = *(matrix + j*m + k);
          *(matrix + j*m + k) = c_elim*multiplier - s_elim*factor;
        }
      }
    }
  }
  *(matrix + n*m -1) = *(matrix + n*m -1)/ *(matrix + m*n -2);
  *(matrix + m*n -2) = 1;

  for (int i = n-1; i >= 0; i--) {
    double right_side = *(matrix + i*m + m-1);
    for (int j = m-2; j >= i; j--) {
      double element = *(matrix + i*m + j);
      if (j > i) {
        double multiplier = *(answers + j);
        right_side = right_side - element * multiplier;
      }
      else {
        *(answers + i) = right_side / element;}
    }
  }
  getrusage(RUSAGE_SELF, &ru);
  user_time = ru.ru_utime;
  sys_time = ru.ru_stime;
  printf("%.10e %.10e %.10e %.10e %.10e\n", (double) user_time.tv_sec + (double)user_time.tv_usec / (double) 1000000, (double) sys_time.tv_sec + (double) sys_time.tv_usec /  (double) 1000000, (double) ru.ru_maxrss, (double) ru.ru_minflt, (double) ru.ru_majflt);

  if (n < 5) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%.10e", *(ortrix + i*m + j));
        if (j<m-1) {
          printf(" ");
        }
      }
      printf("\n");
    }
    printf("answers:\n");
    for (int i = 0; i < n; i++) {
      printf("%.10e", *(answers + i));
      if (i < n+1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  double sum_sqrs = 0.0;
  for (int i = 0; i < 1; i++) {
    double b = *(ortrix + i*m + n);
    for (int j = 0; j < n; j++) {
      long double x = *(answers + (n-j-1));
      printf("b: %.10e\t", b);
      printf("x: %.10e\t", (double)x);
      double A = *(ortrix + i*m + j);
      printf("A: %.10e\n", A);
      double Axb2 = ((double)x*A - b);
      Axb2 = pow(Axb2, 2.0);
      printf("Axb2: %.10e\n", sqrt(Axb2));
      sum_sqrs = sum_sqrs + sqrt(Axb2);
      printf("%.10e\n", (double)sum_sqrs);
    }
  }
  printf("%.10e\n", (double)sum_sqrs);

  return 0;
}
