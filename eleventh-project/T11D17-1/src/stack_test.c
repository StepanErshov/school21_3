#include "stack.h"

#include <assert.h>
#include <stdio.h>

int main() {
#ifdef quest3
    Stack stack;
    init(&stack);
    assert(push(&stack, 10) == 0);
    assert(push(&stack, 20) == 0);
    int poppedData;
    assert(pop(&stack, &poppedData) == 0 && poppedData == 20);
    assert(pop(&stack, &poppedData) == 0 && poppedData == 10);
    destroy(&stack);
    printf("SUCCESS");
#endif
    return 0;
}
