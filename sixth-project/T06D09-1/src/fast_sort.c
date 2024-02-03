#include <stdio.h>
#define NMAX 10


int input(int *a, int *n);
int quicksort(int *a, int n);
int heap_sort(int *a, int n);
void output(int *a, int n);


int main(){
    int data[NMAX], n = NMAX;
if(input(data, &n) == 1){
    printf("n/a");
    return 0;
}
    quicksort(data, n);
    heap_sort(data, n);
    output(data, n);
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


int quicksort(int *a, int n){
    int i = 0;
    int j = n - 1;
    int midle = a[n / 2];

    do{
        while(a[i] < midle){
            i++;
        }
    while(a[j] > midle){
        j--;
    }

    if(i <= j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        i++;
        j--;
    }

    }while( i <= j);

//рекурсивные вызовы
     if(j > 0){
        quicksort(a, j + 1);
    }
    if(i < n){
        quicksort(&a[i], n - i);
    }

    return 0;
}
void heapify(int *a, int n, int i) {
    int largest = i;
    int temp;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;
    if(largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

int heap_sort(int *a, int n) {
    int i, temp;
    for(i = n/2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for(i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
    return 0;
}

void output(int *a, int n) {

  for (int i = 0; i < n; i++) {

    printf("%d ", a[i]);
  }
  printf("\n");
  for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}