#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct door {
    int id;
    // Additional fields as needed
} door;

typedef struct node {
    door* door;
    struct node* next;
} node;

// Declare functions here
struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
int test_add_door();
int test_remove_door();

#endif // LIST_H
