#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test() {
    struct TestCase {
        const char *input;
        size_t expected_output;
    };

    struct TestCase test_cases[] = {{"hello", 5}, {"world", 5}, {"", 0},
                                    {NULL, 0},    {"\0", 0},    {"abcdefghijklmnopqrstuvwxyz", 26}};

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(struct TestCase); ++i) {
        const char *input = test_cases[i].input;
        size_t result = s21_strlen(input);
        if (result == test_cases[i].expected_output) {
            printf("Test %zu: SUCCESS\nInput: %s\nExpected Output: %zu\nActual Output: %zu\n", i + 1, input,
                   test_cases[i].expected_output, result);
        } else {
            printf("Test %zu: FAIL\nInput: %s\nExpected Output: %zu\nActual Output: %zu\n", i + 1, input,
                   test_cases[i].expected_output, result);
        }
    }
}

void s21_strcmp_test(const char *s1, const char *s2, int expected) {
    int result = s21_strcmp(s1, s2);
    printf("Input: \"%s\", \"%s\"\n", s1, s2);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    printf("%s\n", result == expected ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test() {
    char source[] = "Hello, World!";
    char destination[50];

    s21_strcpy(destination, source);

    printf("Input: \"%s\"\nOutput: \"%s\"\nResult: SUCCESS\n", source, destination);
}
void s21_strcat_test() {
    char string1[50] = "Hello, ";
    char string2[] = "World!";
    char result[60];

    s21_strcpy(result, string1);
    s21_strcat(result, string2);

    printf("Input: \"%s\", \"%s\"\nOutput: \"%s\"\nResult: SUCCESS\n", string1, string2, result);
}

void s21_strchr_test() {
    const char *str = "Hello, World!";
    char target_char = 'W';
    char *found_char = s21_strchr(str, target_char);

    if (found_char) {
        printf("Input: \"%s\", '%c'\nOutput: Found at index %ld\nResult: SUCCESS\n", str, target_char,
               found_char - str);
    } else {
        printf("Input: \"%s\", '%c'\nOutput: Not found\nResult: FAIL\n", str, target_char);
    }
}

void s21_strstr_test() {
    const char *haystack = "The quick brown fox jumps over the lazy dog";
    const char *needle1 = "brown fox";
    const char *needle2 = "fox jumps over the";
    const char *needle3 = "";
    const char *needle4 = "the end";
    char *found;

    found = s21_strstr(haystack, needle1);
    printf("Input: \"%s\", \"%s\"\nOutput: %s\nResult: %s\n", haystack, needle1, found ? found : "Not found",
           found ? "SUCCESS" : "FAIL");

    found = s21_strstr(haystack, needle2);
    printf("Input: \"%s\", \"%s\"\nOutput: %s\nResult: %s\n", haystack, needle2, found ? found : "Not found",
           found ? "SUCCESS" : "FAIL");

    found = s21_strstr(haystack, needle3);
    printf("Input: \"%s\", \"%s\"\nOutput: %s\nResult: %s\n", haystack, needle3, found ? found : "Not found",
           found ? "SUCCESS" : "FAIL");

    found = s21_strstr(haystack, needle4);
    printf("Input: \"%s\", \"%s\"\nOutput: %s\nResult: %s\n", haystack, needle4, found ? found : "Not found",
           found ? "SUCCESS" : "FAIL");
}

void s21_strtok_test() {
    char test_str[] = "The quick brown fox jumps over the lazy dog";
    const char *delims = " ";
    char *token;

    token = s21_strtok(test_str, delims);
    while (token) {
        printf("%s\n", token);
        token = s21_strtok(NULL, delims);
    }
}

int main() {
#ifdef quest1
    s21_strlen_test();
#endif
#ifdef quest2
    s21_strcmp_test("abc", "abc", 0);
    s21_strcmp_test("abc", "def", -1);
    s21_strcmp_test("def", "abc", 1);
#endif
#ifdef quest3
    s21_strcpy_test();
#endif
#ifdef quest4
    s21_strcat_test();
#endif
#ifdef quest5
    s21_strchr_test();
#endif
#ifdef quest6
    s21_strstr_test();
#endif
#ifdef quest7
    s21_strtok_test();
#endif

    return 0;
}
