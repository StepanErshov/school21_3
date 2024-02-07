#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
void s21_strlen_test();
int s21_strcmp(const char *s1, const char *s2);
void s21_strcmp_test(const char *s1, const char *s2, int expected);
char *s21_strcpy(char *destination, const char *source);
void s21_strcpy_test();
char *s21_strcat(char *destination, const char *source);
void s21_strcat_test();
char *s21_strchr(const char *str, int c);
void s21_strchr_test();
char *s21_strstr(const char *haystack, const char *needle);
void s21_strstr_test();
char *s21_strtok(char *str, const char *delims);
void s21_strtok_test();

#endif
