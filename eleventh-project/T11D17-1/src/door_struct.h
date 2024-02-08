#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

typedef struct door
{
    int id;
    int status;
} door;
void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void print_doors(struct door* doors);

#endif // DOOR_STRUCT_H