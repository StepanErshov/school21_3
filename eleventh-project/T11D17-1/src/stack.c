#include "stack.h"

#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

void init(Stack* stack) { stack->top = NULL; }

int push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    return SUCCESS;
}

int pop(Stack* stack, int* data) {
    if (stack->top == NULL) return -1;
    Node* temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    return SUCCESS;
}

void destroy(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}
