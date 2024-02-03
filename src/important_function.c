#include <math.h>
#include <stdio.h>

double roundToOneDecimal(double num) { return round(num * 10.0) / 10.0; }

double calculateFunction(double x) {
  double y;
  y = 7e-3 * (pow(x, 4)) +
      ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) -
      x * pow((10 + x), (2 / x)) - 1.01;
  return roundToOneDecimal(y);
}

int main() {
  double x;
  printf("Введите число: ");

  if (scanf("%lf", &x) != 1) {
    printf("н/д\n");
    return 0;
  }

  double result = calculateFunction(x);
  printf("Результат: %.1f\n", result);

  return 0;
}