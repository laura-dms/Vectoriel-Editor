#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>

//Prototypes of functions on the structure Point

Point* create_point(int px, int py){ //Allocate dynamically a variable of type structure Point
    Point *point = (Point *) malloc(sizeof(Point)); //allocate a new point
    point->pos_x = px;
    point->pos_y = py;
    return point;
}

void delete_point(Point * point){
    free(point); //Free the allocated memory the point
    /*Note that the free does not delete the point variable itself, it simply releases the data that it points to. The point variable
     will still point to somewhere in the memory - but after calling point we are not allowed to access that area anymore. We must not use that
     pointer again until we allocate new data using it.*/
}

void print_point(Point * p){ //Display on the screen the coordinates of Point
    printf("\nPOINT %d %d", p->pos_x, p->pos_y);
}



//Prototypes of functions on the structure Line

Line *create_line(Point * p1, Point * p2){ //Allocate dynamically a variable of type structure Line
    Line * line = (Line *) malloc(sizeof(Line)); //allocate a new line
    line->p1 = p1;
    line->p2 = p2;
    return line;
}
void delete_line(Line * line){
    free(line); //Free the allocated memory the line
}

void print_line(Line * line){ //Display on the screen the coordinates of Line
    printf("\nLINE %d %d %d %d", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}



//Prototypes of functions on the structure Square

Square* create_square(Point* point, int length){ //enter the coordinates of Point (pos_x, pos_y)
    Square *square = (Square*) malloc(sizeof(Square)); //allocate a new square (data needed to be stored is just the structure)
    square->length=length;

    /*Coordinates of the 4 points of the square
    p1 = px, py (Top Left)
    p2 = px+length, py (TR)
    p3 = px, py+length (BL)
    p4 = px+length, py+length (BR) */

    //Point 1
    square->point1->pos_x=point->pos_x;
    square->point1->pos_y=point->pos_y;

    return square;
}


void delete_square(Square * square){
    free(square); //free the memory allocated for the structure square
}

void print_square(Square * square){
    printf("\nSQUARE %d %d %d", square->point1->pos_x, square->point1->pos_y, square->length); //p1 pos_x,p1 pos_y, length
    /*printf(" %d %d |", square->point1->pos_x + square->length, square->point1->pos_y);
    printf(" %d %d |", square->point1->pos_x, square->point1->pos_y - square->length);
    printf(" %d %d", square->point1->pos_x + square->length, square->point1->pos_y - square->length);*/
}



//Prototypes of functions of Structure Rectangle

Rectangle *create_rectangle(Point * point, int width, int height) {
    Rectangle *rectangle = (Rectangle *) malloc(sizeof(Rectangle)); //allocate dynamically the structure rectangle

    rectangle->length = width;
    rectangle->width = height;

    //Point 1
    rectangle->initialpoint->pos_x = point->pos_x;
    rectangle->initialpoint->pos_y = point->pos_y;

    return rectangle;
}

void delete_rectangle(Rectangle * rectangle){
    free(rectangle); //free the memory dynamically allocated for the rectangle
}

void print_rectangle(Rectangle * rectangle){
    printf("\nRECTANGLE %d %d %d %d", rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y,rectangle->length, rectangle->width);
    /*printf(" %d %d |", rectangle->initialpoint->pos_x + rectangle->length, rectangle->initialpoint->pos_y);
    printf(" %d %d |", rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y - rectangle->width);
    printf(" %d %d", rectangle->initialpoint->pos_x + rectangle->length, rectangle->initialpoint->pos_y - rectangle->width);*/
}



//Prototypes of the functions of Structure Circle

Circle *create_circle(Point * center, int radius){
    Circle * circle= (Circle*)malloc(radius*sizeof(Circle));
    circle->radius = radius;
    circle->center = center;

    return circle;
}

void delete_circle(Circle * circle){
    free(circle);
}

void print_circle(Circle * circle){
    printf("\nCIRCLE %d %d %d", circle->center->pos_x, circle->center->pos_y, circle->radius);
}



//Prototypes of the functions of Structure Polygon

Polygon *create_polygon(int n){
    int i, x, y;
    Point* pt;
    Polygon * polygon = (Polygon*)malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points = (Point**)malloc(n*sizeof(Point*)); //dynamic creation of the list of vertices
    // 1st = last point : the user fill the list 'til the n-1 point (= n points)
    for (i = 0; i < n; i++){
        printf("\nCoor x y: ");
        scanf("%d %d", &x, &y);
        pt = create_point(x, y);
        polygon->points[i] = pt;
    }
    return polygon;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
}

void print_polygon(Polygon * polygon){
    //printf("%d points", polygon->n);
    printf("\nPOLYGON ");
    for (int i =0; i<polygon->n; i++) {
        print_point(polygon->points[i]);
    }
}
