/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the main code of the project*/

#include <stdio.h>
#include "menu.h"
#include "list.h"
#include "area.h"

int main(){
    int m_state, nb_shape = 0;
    /*NODE* shapes = NULL;

    do{
        m_state = menu(&nb_shape, &shapes);
    }while(m_state != 1);*/

    Area* draw_zone = create_area(12, 14);
    Shape* shape1 = create_point_shape(8, 11);
    add_shape_to_area (draw_zone, shape1);
    print_list(draw_zone->shapes);
    clear_area(draw_zone);
    draw_zone->mat[0][0] = 1;
    draw_area (draw_zone);
    print_area (draw_zone);
    //erase_area (draw_zone);
    delete_area (draw_zone);

    return 0;
}
