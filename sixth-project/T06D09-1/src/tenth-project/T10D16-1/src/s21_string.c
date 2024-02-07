#include "s21_string.h"

#include <stddef.h>

int s21_strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s)
        ;
    return s - str;
}

int s21_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

char *s21_strcpy(char *destination, const char *source) {
    char *dest_start = destination;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return dest_start;
}

char *s21_strcat(char *destination, const char *source) {
    char *dest_end = destination;
    while (*dest_end != '\0') {
        dest_end++;
    }

    while ((*dest_end++ = *source++) != '\0')
        ;

    return destination;
}

char *s21_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return 0;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack;

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n) return (char *)haystack;

        haystack++;
    }

    return 0;
}

static char *next_token = NULL;

char *s21_strtok(char *str, const char *delim) {
    if (!str) {
        str = next_token;
    }

    if (!str) {
        return NULL;
    }

    size_t delim_length = s21_strlen(delim);
    char *token_start = str;

    for (size_t i = 0; token_start[i] != '\0'; i++) {
        size_t j;
        for (j = 0; j < delim_length; j++) {
            if (token_start[i] == delim[j]) {
                token_start[i] = '\0';
                next_token = token_start + i + 1;
                return token_start;
            }
        }
    }

    next_token = NULL;
    return token_start;
}