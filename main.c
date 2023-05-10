/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the main code of the project*/

#include <stdio.h>
#include "menu.h"
#include "list.h"

int main(){
    int m_state, nb_shape = 0;

    NODE* shapes = NULL;


    do{
        m_state = menu(&nb_shape, &shapes);
    }while(m_state != 1);

     //Area
    Area* draw_zone = create_area(12, 14);
    Shape* shape1 = create_line_shape(5, 5 , 10, 10);
    Shape* shape2 = create_circle_shape(5, 5, 4);
    add_shape_to_area (draw_zone, shape1);
    add_shape_to_area (draw_zone, shape2);
    draw_area (draw_zone);
    print_area (draw_zone);
    erase_area (draw_zone);
    draw_area (draw_zone);
    print_area (draw_zone);
    delete_area (draw_zone);
    
    return 0;
}
