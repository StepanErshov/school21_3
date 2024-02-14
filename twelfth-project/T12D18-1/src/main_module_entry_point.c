#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef quest1
    print_log(print_char, Module_load_success_message);
#endif
#ifdef quest2
    char *Documents[] = {"Linked lists", "Queues", "Maps", "Binary Trees"};
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    // Output availability for each document....
    for (int i = 0; i < Documents_count; i++) {
        printf("%-15s: %s\n", Documents[i], availability_mask[i] ? "(available)" : "(unavailable)");
    }

    free(availability_mask);  // Освобождаем память после использования
#endif
    return 0;
}
