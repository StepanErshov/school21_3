#include "list.h"

#include <assert.h>
#include <stddef.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door() {
    struct door door1 = {1};
    struct node* root = init(&door1);
    assert(root != NULL);
    struct door door2 = {2};
    struct node* new_node = add_door(root, &door2);
    assert(new_node != NULL);
    assert(new_node->door == &door2);
    destroy(root);
    return 0;
}

int test_remove_door() {
    struct door door1 = {1};
    struct node* root = init(&door1);
    assert(root != NULL);
    struct door door2 = {2};
    struct node* new_node = add_door(root, &door2);
    assert(new_node != NULL);
    assert(new_node->door == &door2);
    struct node* removed_node = remove_door(new_node, root);
    assert(removed_node = new_node);
    destroy(root);
    return 0;
}

int main() {
    int result = test_add_door();
    if (result != SUCCESS) return FAIL;
    result = test_remove_door();
    if (result != SUCCESS) return FAIL;
    return SUCCESS;

}
