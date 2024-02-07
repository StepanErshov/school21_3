#include "data_sort.h"

#include <stdio.h>

void sort(double *data, int n) {
    double tmp;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (data[j] > data[j + 1]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }
}