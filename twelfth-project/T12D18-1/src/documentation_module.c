#include "documentation_module.h"

#include <stdlib.h>

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validation_func)(char *), int documents_count,
                                          char **documents) {
    int *availability_mask = malloc(documents_count * sizeof(int));
    if (!availability_mask) {
        return NULL;
    }

    for (int i = 0; i < documents_count; i++) {
        availability_mask[i] = validation_func(documents[i]);
    }

    return availability_mask;
}
