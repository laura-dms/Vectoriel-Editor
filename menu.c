#include "menu.h"
#include "Structure_shape.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_MAX 25

int menu(int * nb_shape){
    Shape** shapes = (Shape**)malloc(sizeof(Shape*)*SIZE_MAX);
    char choice1[1] = "0";
    int x1, y1, x2, y2, width, height;

    printf("\n====================\n        MENU        \n====================\n\n"
           "----- Draw a shape -----\nType: \n- 'point'     - 'line'\n"
           "- 'square'    - 'rectangle'\n- 'circle'    - 'polygon'\n\n----- Display the shape list -----\nType 'list'"
           "\n\n----- Exit the program -----\nType 'exit'\n\n");
    scanf("%s", choice1);


    if (!strcmp(choice1, "point")){
        Shape* p;
        printf("Enter the coordinates of the point ('x y'): \n");
        scanf("%d %d", &x1, &y1);
        p = create_point_shape(x1, y1);
        print_shape(p);
        nb_shape ++;
        printf("\nThe shape has been added correctly !\n");
        shapes[*nb_shape] = p;
        print_shape(shapes[*nb_shape]);
    }

    else if (!strcmp(choice1, "line")){
        Shape* l;
        printf("Enter the coordinates of the 2 points of the line ('x1 y1, x2 y2'): \n");
        scanf("%d %d, %d %d", &x1, &y1, &x2, &y2);
        l = create_line_shape(x1, y1, x2, y2);
        //print_shape(l);
        printf("\nThe shape has been added correctly !\n");
        nb_shape ++;
        *(shapes + *nb_shape) = l;
    }

    else if (!strcmp(choice1, "square")){
        //create square
        Shape* s;
        printf("Enter the coordinates of the upper left point and the size of the square ('x y size'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        s = create_square_shape(x1, y1, width);
        //print_shape(s);
        printf("\nThe shape has been added correctly !\n");
        nb_shape ++;
        *(shapes + *nb_shape) = s;
    }

    else if (!strcmp(choice1, "rectangle")){
        //create rectangle
        Shape* r;
        printf("Enter the coordinates of the upper left point, the width and the height of the rectangle ('x y width height'): \n");
        scanf("%d %d %d %d", &x1, &y1, &width, &height);
        r = create_rectangle_shape(x1, y1, width, height);
        //print_shape(r);
        printf("\nThe shape has been added correctly !\n");
        nb_shape ++;
        *(shapes + *nb_shape) = r;
    }

    else if (!strcmp(choice1, "circle")){
        //create circle
        Shape* c;
        printf("Enter the coordinates of the center of the circle, and its radius ('x y radius'): \n");
        scanf("%d %d %d", &x1, &y1, &width);
        c = create_circle_shape(x1, y1, width);
        //print_shape(c);
        printf("\nThe shape has been added correctly !\n");
        nb_shape ++;
        *(shapes + *nb_shape) = c;
    }

    else if (!strcmp(choice1, "polygon")){
        //create polygon
        Shape* poly;
        printf("Enter the number of points of your polygon : ");
        scanf("%d", &width);
        poly = create_polygon_shape(width);
        //print_shape(poly);
        printf("\nThe shape has been added correctly !\n");
        nb_shape ++;
        *(shapes + *nb_shape) = poly;
    }

    else if (!strcmp(choice1, "list")){
        //print shapes list
        printf("\nHere is the list of shapes you added: \n");
        for (int i = 0; i < *nb_shape; i++){
            print_shape(shapes[i]);
        }
        printf("\n");
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
        //print more commands (exit the program, clear screen, change color (?))
    }*/

    else{
        printf("This command does not exist!");
    }
    return 0;
}
