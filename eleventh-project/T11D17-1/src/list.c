#include "list.h"

#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return NULL;
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = init(door);
    if (elem == NULL || new_node == NULL) return NULL;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL && current->door->id != door_id) {
        current = current->next;
    }
    return current;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL || elem == NULL) return NULL;
    struct node* prev = root;
    while (prev != NULL && prev->next != elem) {
        prev = prev->next;
    }
    if (prev != NULL) {
        prev->next = elem->next;
        free(elem);
    }
    return prev;
}

void destroy(struct node* root) {
    struct node* current = root;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
