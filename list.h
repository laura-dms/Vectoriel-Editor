#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include "Structure_shape.h"

typedef struct node{
    Shape* value;
    struct node *succ;
}NODE;

/*-Definition of type LIST-*/
typedef NODE* LIST;

NODE* create_node(Shape*);
LIST add_end_list(LIST, Shape*) ;
void print_list(LIST);

#endif
