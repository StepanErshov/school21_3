/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n, double mnm, double vrc);
int even_number(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        return 0;
    };
    double mnmn = mean(data, n);
    double vrc = variance(data, n);
    output(data, n, mnmn, vrc);
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 && *n < 30) {
        printf("n/a");
        return 0;
    };
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a");
            return 1;
        };
    }
    return 0;
}
void output(int *a, int n, double mnmn, double vrc) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0 && *(a + i) >= mnmn && *(a + i) <= mnmn + 3 * sqrt(vrc) && *(a + i) != 0) {
            printf("%d", *(a + i));
        }
    }
}

double mean(int *a, int n) {
    double score = 0;
    for (int i = 0; i < n; i++) {
        score += a[i];
    }
    double mnm = score / n;
    return mnm;
}

double variance(int *a, int n) {
    double sred = 0;
    double otkl = 0;
    for (int i = 0; i < n; i++) {
        sred += a[i];
    }
    sred = sred / n;

    for (int i = 0; i < n; i++) {
        otkl += (a[i] * a[i]) - (sred * sred);
    }
    return otkl / n;
}