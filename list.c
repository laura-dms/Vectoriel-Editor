/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the prototypes of the functions about the list of nodes*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

NODE* create_node(Shape* val){ /// create a new_node and return it
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->value = val;
    new_node->succ = NULL;
    return new_node;
}

LIST add_to_list(LIST L, Shape* val){ /// insert in the SLL a new node at the head
    NODE* new = create_node(val);
    new->succ=L;
    return new;
}

void print_list(LIST L){ ///display information of each shape of the list of shapes by running through the list with a temporary pointer
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

void delete_list(LIST* L){ ///deplace the head to the tail by one node and free the first node with a temporary pointer
    NODE* tmp = *L;
    while(*L != NULL){
        *L = (*L)->succ;
        free(tmp);
        tmp = *L;
    }
}
