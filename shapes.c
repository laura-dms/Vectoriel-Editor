#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>

//Prototypes of functions on the structure Point

Point* create_point(int px, int py) //Allocate dynamically a variable of type structure Point
{
    Point *point = (Point *) malloc(sizeof(Point)); //allocate a new point
    point->pos_x = px;
    point->pos_y = py;
    return point;
}
void delete_point(Point * point)
{
    free(point); //Free the allocated memory the point
    /*Note that the free does not delete the point variable itself,
     * it simply releases the data that it points to. The point variable
     * will still point to somewhere in the memory - but after calling point
     * we are not allowed to access that area anymore. We must not use that
     * pointer again until we allocate new data using it.*/
}
void print_point(Point * p) //Display on the screen the coordinates of Point
{
    printf("POINT %d %d", p->pos_x, p->pos_y);
}

//Prototypes of functions on the structure Line

Line *create_line(Point * p1, Point * p2) //Allocate dynamically a variable of type structure Line
{
    Line * line = (Line *) malloc(sizeof(Line)); //allocate a new line
    line->p1 = p1; //fill the first argument of line
    line->p2 = p2; //fill the second argument of line
    return line;
}
void delete_line(Line * line)
{
    free(line); //Free the allocated memory the line
}
void print_line(Line * line) //Display on the screen the coordinates of Line
{
    printf("\nLINE %d %d %d %d", line->p1->pos_x, line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}
