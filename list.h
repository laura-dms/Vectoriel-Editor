/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the definitions of the functions about the list of nodes*/

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
