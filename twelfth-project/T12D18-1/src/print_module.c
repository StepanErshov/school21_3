#include "print_module.h"

#include <stdio.h>
#include <time.h>

#include "documentation_module.h"

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char *message) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[9];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

    print('[');
    print('L');
    print('O');
    print('G');
    print(']');
    print(' ');

    int i = 0;
    while (buffer[i]) {
        print(buffer[i]);
        i++;
    }

    print(' ');

    i = 0;
    while (message[i]) {
        print(message[i]);
        i++;
    }
}
