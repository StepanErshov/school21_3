#include <stdio.h>

int main() {
  int num1, num2;
  if (scanf("%d %d", &num1, &num2) != 2) {
    printf("n/a");
    return 0;
  }

  if (num2 == 0) {
    printf("%d %d 0 n/a", num1 + num2, num1 - num2);
  } else {
    printf("%d %d %d %d", num1 + num2, num1 - num2, num1 * num2, num1 / num2);
  }

  return 0;
}
