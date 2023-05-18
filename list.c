/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the prototypes of the functions about the list of nodes*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

NODE* create_node(Shape* val){
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->value = val;
    new_node->succ = NULL;
    return new_node;
}

LIST add_to_list(LIST L, Shape* val){
    NODE* new = create_node(val);
    new->succ=L;
    return new;
}

void print_list(LIST L){
    if (L==NULL){
        printf("Empty list");
    }
    else{
        NODE* tmp = L;
        while(tmp != NULL){
            print_shape(tmp->value);
            tmp = tmp->succ;
        }
    }
}
