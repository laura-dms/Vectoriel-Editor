#include "menu.h"
#include "Structure_shape.h"
#include "list.h"
#include <stdio.h>
#include <string.h>

int menu(int * nb_shape, NODE** shapes){
    char choice1[1] = "0";
    int x1, y1, x2, y2, width, height;

    printf("\n====================\n        MENU        \n====================\n\n"
           "----- Draw a shape -----\nType: \n- 'point'     - 'line'\n"
           "- 'square'    - 'rectangle'\n- 'circle'    - 'polygon'\n\n----- Display the shape list -----\nType 'list'"
           "\n\n----- Exit the program -----\nType 'exit'\n\n");
    scanf("%s", choice1);


    if (!strcmp(choice1, "point")){
        //create point
        Shape* p;
        printf("Enter the coordinates of the point ('x y'): \n");
        scanf("%d %d", &x1, &y1);
        p = create_point_shape(x1, y1);
        *shapes = add_tail_list(*shapes, p);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_point(p->ptrShape);
    }

    else if (!strcmp(choice1, "line")){
        //create line
        Shape* l;
        printf("Enter the coordinates of the 2 points of the line ('x1 y1, x2 y2'): \n");
        scanf("%d %d, %d %d", &x1, &y1, &x2, &y2);
        l = create_line_shape(x1, y1, x2, y2);
        *shapes = add_tail_list(*shapes, l);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_line(l->ptrShape);
    }

    else if (!strcmp(choice1, "square")){
        //create square
        Shape* s;
        printf("Enter the coordinates of the upper left point and the size of the square ('x y size'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        s = create_square_shape(x1, y1, width);
        *shapes = add_tail_list(*shapes, s);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_square(s->ptrShape);
    }

    else if (!strcmp(choice1, "rectangle")){
        //create rectangle
        Shape* r;
        printf("Enter the coordinates of the upper left point, the width and the height of the rectangle ('x y width height'): \n");
        scanf("%d %d %d %d", &x1, &y1, &width, &height);
        r = create_rectangle_shape(x1, y1, width, height);
        *shapes = add_tail_list(*shapes, r);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_rectangle(r->ptrShape);
    }

    else if (!strcmp(choice1, "circle")){
        //create circle
        Shape* c;
        printf("Enter the coordinates of the center of the circle, and its radius ('x y radius'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        c = create_circle_shape(x1, y1, width);
        *shapes = add_tail_list(*shapes, c);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_circle(c->ptrShape);
    }

    else if (!strcmp(choice1, "polygon")){
        //create polygon
        Shape* poly;
        printf("Enter the number of points of your polygon : ");
        scanf("%d", &width);
        poly = create_polygon_shape(width);
        *shapes = add_tail_list(*shapes, poly);
        *nb_shape += 1;
        printf("\nThe shape has been correctly added !\n");
        delete_polygon(poly->ptrShape);
    }

    else if (!strcmp(choice1, "list")){
        //print shapes list
        printf("\nHere is the list of shapes you added: \n");
        print_list(*shapes);
    }

    else if (!strcmp(choice1, "exit")){
        return 1;
    }

    /*else if (!strcmp(choice1, "screen")) {
        //print drawings
    }
    else if (!strcmp(choice1, "delete")){
        //delete the choosen shape (via id ?) -> free(shape)
    }
    else if (!strcmp(choice1, "help")){
        //print more commands (clear screen, change color (?))
    }*/

    else{
        printf("This command does not exist!");
    }
    return 0;
}
