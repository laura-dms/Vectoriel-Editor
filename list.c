#include "list.h"
#include <stdlib.h>
#include <stdio.h>

NODE* create_node(Shape* val){
    NODE* new_node = (NODE*)malloc(sizeof(NODE)); //dynamic allocation
    new_node->value = val;
    new_node->succ = NULL;
    return new_node;
}

LIST add_tail_list(LIST L, Shape* val){
    NODE* new = create_node(val);
    if (L == NULL){
        L = new;
    }
    else {
        NODE* temp = L;
        while (temp->succ != NULL){
            temp = temp->succ;
        }
        temp->succ = new;
    }
    return L;
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
