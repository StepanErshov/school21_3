#include <stdio.h>

void cycle_shift(int* A, int n, int c) {
    if (c < 0) {
        c = -c;
        for (int i = 0; i < c; i++) {
            int last = A[n - 1];
            for (int j = n - 1; j > 0; j--) {
                A[j] = A[j - 1];
            }
            A[0] = last;
        }
    } else {
        for (int i = 0; i < c; i++) {
            int first = A[0];
            for (int j = 0; j < n - 1; j++) {
                A[j] = A[j + 1];
            }
            A[n - 1] = first;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int A[10];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int c;
    scanf("%d", &c);
    cycle_shift(A, n, c);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}