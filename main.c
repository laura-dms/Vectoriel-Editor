#include <stdio.h>
#include "menu.h"
#include "list.h"

int main(){
    int m_state, nb_shape = 0;

    NODE* shapes = NULL;


    do{
        m_state = menu(&nb_shape, &shapes);
    }while(m_state != 1);

    return 0;
}
