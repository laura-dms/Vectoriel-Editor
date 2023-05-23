/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
        File that contains the main code of the project*/

#include <stdio.h>
#include "menu.h"
#include "list.h"
#include "area.h"
#include "commands.h"


int main(){
    int m_state, nb_shape = 0;
    /*NODE* shapes = NULL;

    do{
        m_state = menu(&nb_shape, &shapes);
    }while(m_state != 1);*/

    /*Area* draw_zone = create_area(30, 30);
    Shape* shape2 = create_rectangle_shape(16,9,10,4);
    Shape* shape3 = create_circle_shape(3, 3, 5);
    //Shape* shape4 = create_square_shape(3,27,4);
    add_shape_to_area(draw_zone, shape3);
    add_shape_to_area(draw_zone, shape2);
    //add_shape_to_area (draw_zone, shape4);
    print_list(draw_zone->shapes);
    printf("\n");
    clear_area(draw_zone);
    draw_area (draw_zone);
    print_area (draw_zone);
    //erase_area (draw_zone);
    delete_area (draw_zone);*/

    int state=1;
    while (state==1)
    {
        Command* command = create_command();
        read_from_stdin(command); ///fill the structure command
        state = read_exec_command(command); ///execute the command
        delete_cmd(command);
    }
    return 0;
}
