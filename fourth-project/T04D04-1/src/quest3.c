#include <stdio.h>

long long fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int n;
  printf("Введите число n: ");
  if (scanf("%d", &n) != 1 || n < 0) {
    printf("n/a\n");
    return 1;
  }
  printf("%lld\n", fibonacci(n));
  return 0;
}
