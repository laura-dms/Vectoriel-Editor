/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the definition of the function menu*/

#include "menu.h"
#include "Structure_shape.h"
#include "list.h"
#include <stdio.h>
#include <string.h>

int menu(int * nb_shape, NODE** shapes){
    char choice[1] = "0";
    int x1, y1, x2, y2, width, height;

    printf("\n====================\n        MENU        \n====================\n\n"
           "----- Draw a shape -----\nType: \n- 'point'     - 'line'\n"
           "- 'square'    - 'rectangle'\n- 'circle'    - 'polygon'\n\n----- Display the shape list -----\nType 'list'"
           "\n\n----- Exit the program -----\nType 'exit'\n\n");
    scanf("%s", choice);


    if (!strcmp(choice, "point")){
        //create point
        Shape* p;
        printf("Enter the coordinates of the point ('x y'): \n");
        scanf("%d %d", &x1, &y1);
        p = create_point_shape(x1, y1);
        *shapes = add_to_list(*shapes, p); //add the shape and its coordinates in the SLL
        *nb_shape += 1; //increment the nb of shape
        printf("\nThe shape has been correctly added !\n");
        delete_shape(p); //dynamically delete the pointer to the shape
    }

    else if (!strcmp(choice, "line")){
        //create line
        Shape* l;
        printf("Enter the coordinates of the 2 points of the line ('x1 y1, x2 y2'): \n");
        scanf("%d %d, %d %d", &x1, &y1, &x2, &y2);
        l = create_line_shape(x1, y1, x2, y2);
        *shapes = add_to_list(*shapes, l);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_shape(l);
    }

    else if (!strcmp(choice, "square")){
        //create square
        Shape* s;
        printf("Enter the coordinates of the upper left point and the size of the square ('x y size'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        s = create_square_shape(x1, y1, width);
        *shapes = add_to_list(*shapes, s);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_shape(s);
    }

    else if (!strcmp(choice, "rectangle")){
        //create rectangle
        Shape* r;
        printf("Enter the coordinates of the upper left point, the width and the height of the rectangle ('x y width height'): \n");
        scanf("%d %d %d %d", &x1, &y1, &width, &height);
        r = create_rectangle_shape(x1, y1, width, height);
        *shapes = add_to_list(*shapes, r);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_shape(r);
    }

    else if (!strcmp(choice, "circle")){
        //create circle
        Shape* c;
        printf("Enter the coordinates of the center of the circle, and its radius ('x y radius'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        c = create_circle_shape(x1, y1, width);
        *shapes = add_to_list(*shapes, c);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_shape(c);
    }

    else if (!strcmp(choice, "polygon")){
        //create polygon
        Shape* poly;
        printf("Enter the number of points of your polygon : ");
        scanf("%d", &width);
        poly = create_polygon_shape(width);
        *shapes = add_to_list(*shapes, poly);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_shape(poly);
    }

    else if (!strcmp(choice, "list")){
        //print shapes list
        printf("\nHere is the list of shapes you added: \n");
        print_list(*shapes);
    }

    else if (!strcmp(choice, "exit")){
        return 1;
    }

    /*else if (!strcmp(choice, "screen")) {
        //print drawings
    }
    else if (!strcmp(choice, "delete")){
        //delete the choosen shape (via id ?) -> free(shape)
    }
    else if (!strcmp(choice, "help")){
        //print more commands (clear screen, change color (?))
    }*/

    else{
        printf("This command does not exist!");
    }
    return 0;
}
