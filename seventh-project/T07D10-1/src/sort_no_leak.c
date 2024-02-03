#include <stdio.h>
#include <stdlib.h>
#define NMAX 30

int input(int *a, int *n);
int sort(int *a, int n);

int main(){
int n, *data = malloc(n * sizeof(int));
    if(input(data, &n) == 1){
        printf("n/a");
        return 0;
    }
    sort(data, n);
    free(data);
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
