#include "menu.h"
#include <stdio.h>
#include <string.h>
#define SIZE 100

void menu(){
    char shapes[0];
    char choice1[1] = "0";
    int x1, y1, x2, y2;

    printf("====================\n        MENU        \n====================\n\n"
           "----- Draw a shape -----\nType: \n- 'point'     - 'line'\n"
           "- 'square'    - 'rectangle'\n- 'circle'    - 'polygon'\n\n----- Display the shape list -----\nType 'list'"
           "\n\n----- Delete a shape -----\nType 'delete'\n\n----- Display the screen -----\nType 'screen'\n\n"
           "----- More commands -----\nType 'help'\n");
    scanf("%s", choice1);


    if (!strcmp(choice1, "point")){
        printf("Enter the coordinates (x y) of the point: \n");
        scanf("%d %d", &x1, &y1);
        print_point(create_point(x1, y1));
        //shapes[0] = point.px
    }
    else if (!strcmp(choice1, "line")){
        printf("Enter the coordinates of the 2 points of the line (x1 y1, x2 y2): \n");
        scanf("%d %d, %d %d", &x1, &y1, &x2, &y2);
        print_line(create_line(create_point(x1, y1), create_point(x2, y2)));
    }
    else if (!strcmp(choice1, "square")){
        //create square
    }
    else if (!strcmp(choice1, "rectangle")){
        //create rectangle
    }
    else if (!strcmp(choice1, "circle")){
        //create circle
    }
    else if (!strcmp(choice1, "polygon")){
        //create polygon
    }


    else if (!strcmp(choice1, "screen")){
        //print drawings
    }
    else if (!strcmp(choice1, "list")){
        //print shapes list
    }
    else if (!strcmp(choice1, "delete")){
        //delete the choosen shape (via id ?) -> free(shape)
    }
    else if (!strcmp(choice1, "help")){
        //print more commands (exit the program, clear screen, change color (?))
    }
    else{
        printf("This command does not exist!");
    }
}