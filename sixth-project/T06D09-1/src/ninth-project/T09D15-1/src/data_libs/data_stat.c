#include "data_stat.h"

double max(double *data, int n) {
    double max_argc = data[0];

    for (int i = 0; i < n; i++) {
        if (data[i] > max_argc) {
            max_argc = data[i];
        }
    }

    return max_argc;
}

double min(double *data, int n) {
    double min_argc = data[0];

    for (int i = 0; i < n; i++) {
        if (data[i] < min_argc) {
            min_argc = data[i];
        }
    }

    return min_argc;
}

double mean(double *data, int n) {
    double score = 0;
    for (int i = 0; i < n; i++) {
        score += data[i];
    }
    double mnm = score / n;
    return mnm;
}

double variance(double *data, int n) {
    double sred = 0;
    double otkl = 0;
    for (int i = 0; i < n; i++) {
        sred += data[i];
    }
    sred = sred / n;

    for (int i = 0; i < n; i++) {
        otkl += (data[i] * data[i]) - (sred * sred);
    }
    return otkl / n;
}