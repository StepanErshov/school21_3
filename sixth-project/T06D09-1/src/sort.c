#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int sort(int *a, int n);

int main(){

int data[NMAX], n = 10;
    if(input(data, &n) == 1){
        printf("n/a");
        return 0;
    }
    sort(data, n);
    return 0;
}

int input(int *a, int *n) {
  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1) {
      printf("n/a\n");
      return 1;
    };
  }
  return 0;
};

int sort(int *a, int n){
    int tmp;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i ; j++){
            if(a[j] > a[j + 1]){
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

for(int i = 0; i < n; i ++){
    printf("%d ", a[i]);
}
return 0;
}