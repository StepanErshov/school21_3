#include <math.h>
#include <stdio.h>
#define PI 3.14159265358979323846

double LemniscateOfBernoulli(double);
double Agnesi(double);
double QuadraticHyperbola(double);

int main() {

  double x = -3.14159265358979323846;
  double y1 = Agnesi(x);
  double y2 = LemniscateOfBernoulli(x);
  double y3 = QuadraticHyperbola(x);
  double step = PI * 2.0 / 41.0;

  for (double i = -PI; i <= PI; i += step) {
    x += 0.01556606;
    y1 = Agnesi(x);
    y2 = LemniscateOfBernoulli(x);
    y3 = QuadraticHyperbola(x);
    if (y2 != 100) {
      char y22 = '-';
      printf("%.7lf | %.7lf | %c | %.7lf\n", x, y1, y22, y3);
    } else {
      printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, y1, y2, y3);
    }
  }
  return 0;
}

double Agnesi(double x) {

  double y = ((pow(1, 3)) / (pow(1, 2) + pow(x, 2)));
  return y;
}

double LemniscateOfBernoulli(double x) {

  double y =
      sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));
  return y;
}

double QuadraticHyperbola(double x) {

  double y = (1 / pow(x, 2));
  return y;
}