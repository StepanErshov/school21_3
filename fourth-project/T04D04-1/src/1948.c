#include <math.h>
#include <stdio.h>

int largestPrimeDivisor(int num) {
  int divisor = 2;
  while (divisor * divisor <= num) {
    if (num % divisor == 0) {
      num /= divisor;
    } else {
      divisor += 1;
    }
  }
  return num;
}

int main() {
  int num;
  if (scanf("%d", &num) != 1) {
    printf("n/d\n");
    return 1;
  }
  if (num < 0) {
    num = num * -1;
    int result = largestPrimeDivisor(num);
    printf("%d\n", result);
  } else {
    int result = largestPrimeDivisor(num);
    printf("%d\n", result);
  }
}