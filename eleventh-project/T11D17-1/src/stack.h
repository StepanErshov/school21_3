#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init(Stack* stack);
int push(Stack* stack, int data);
int pop(Stack* stack, int* data);
void destroy(Stack* stack);

#endif // STACK_H
