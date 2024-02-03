#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  if (input(data, &n) == 1) {
    return 0;
  };
  output(data, n);
  output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) != 1 && *n <= 10) {
    printf("n/a");
    return 1;
  };
  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1) {
      printf("n/a\n");
      return 1;
    };
  }
  return 0;
};

void output(int *a, int n) {

  for (int i = 0; i < n; i++) {

    printf("%d ", a[i]);
  }
  printf("\n");
}

int max(int *a, int n) {

  int max_argc = a[0];

  for (int i = 0; i < n; i++) {
    if (a[i] > max_argc) {
      max_argc = a[i];
    }
  }

  return max_argc;
}
int min(int *a, int n) {

  int min_argc = a[0];

  for (int i = 0; i < n; i++) {
    if (a[i] < min_argc) {
      min_argc = a[i];
    }
  }

  return min_argc;
}

double mean(int *a, int n) {

  double score = 0;
  for (int i = 0; i < n; i++) {
    score += a[i];
  }
  return score / n;
}

double variance(int *a, int n) {
  double sred = 0;
  double otkl = 0;
  for (int i = 0; i < n; i++) {
    sred += a[i];
  }
  sred = sred / n;

  for (int i = 0; i < n; i++) {
    otkl += (a[i] * a[i]) - (sred * sred);
  }
  return otkl / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {

  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}