#include <math.h>
#include <stdio.h>

int main() {

  double num1, num2;
  scanf("%lf %lf", &num1, &num2);

  if ((num1 * num1) + (num2 * num2) <= 25) {
    printf("Gotcha!\n");
  } else {
    printf("Miss\n");
  }

  return 0;
}
