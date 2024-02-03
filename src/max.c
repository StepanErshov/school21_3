#include <stdio.h>

int main() {

  int num1, num2;
  if (scanf("%d %d", &num1, &num2) != 2) {
    printf("n/a");
    return 0;
  }
  rezult(num1, num2);
}

int rezult(int num1, int num2) {
  if (num1 > num2) {
    printf("%d", num1);
  } else if (num1 < num2) {
    printf("%d", num2);
  } else {
    printf("они равны");
  };

  return 0;
}