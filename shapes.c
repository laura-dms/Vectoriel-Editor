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

//Prototypes of functions on the structure Square
Square *create_square(Point * point, int length) //enter the coordinates of Point (pos_x, pos_y)
{
    //line*l1=*create_line(Point*point, *create_point(point->pos_x, point->pos_y+length));
    Square *square = (Square *) malloc(length*length * sizeof(square)); //allocate a new square (4*(length-1))
    //Length of the square
    square->length=length;

    //**Coordinates of the 4 points of the square**//
    // p1 = px, py
    //p2 = px, py+length
    //p3 = px+length, py
    //p4 = px+length, py+length

    //Point 1
    square->point1->pos_x=point->pos_x;
    square->point1->pos_y=point->pos_y;

    Point *pp2; //define the 3 others points
    Point *pp3;
    Point *pp4;
    //Point 2
    pp2 = create_point(point->pos_x, point->pos_y + square->length);
    square->point2->pos_x=pp2->pos_x;
    square->point2->pos_y=pp2->pos_y;

    //Point 3 => problème : ne veut pas s'afficher avec la fonction print_square
    //pp3 = create_point(point->pos_x + square->length, point->pos_y);
    //square->point3->pos_x=pp3->pos_x;
    //square->point3->pos_y=pp3->pos_y;

    //Point 4 => problème : ne veut pas s'afficher avec la fonction print_square
    //pp4 = create_point(point->pos_x + square->length, point->pos_y + square->length);
    //square->point4->pos_x=pp4->pos_x;
    //square->point4->pos_y=pp4->pos_y;

    return square;
}
    //for (int i=0; i<length;i++) //iterate in the number of lines
    //{
       //if (i==0) //line 1
       //{
         // *(square+i)=*create_line(point, create_point(point->pos_x, point->pos_y+length));
       //}
       //if (i==1) //line 2
       //{
         // *(square+i)=create_line(create_point(point->pos_x, point->pos_y+1), create_point(point->pos_x, point->pos_y+length+1));
       //}
       //if (i==2) //line 3
       //{
         //  *(square+i)=*create_line(create_point(point->pos_x, point->pos_y+2), create_point(point->pos_x, point->pos_y+length+2));
       //}
       //if (i==3) //line 4
         //  {
           //*(square+i)=*create_line(create_point(point->pos_x+length-1, point->pos_y), create_point(point->pos_x+length-1, point->pos_y+length-1));
           //}
    //}
    // DO WE HAVE TO DO A 2D array of size length*length + iterate at each line to create a new "line" ???

void delete_square(Square * square)
{
    free(square); //free the memory allocated for the structure square
}

void print_square(Square * square)
{
    printf("\nSQUARE P1 %d %d %d", square->point1->pos_x, square->point1->pos_y, square->length); //p1 pos_x,p1 pos_y, length
    printf("\nP2 %d %d", square->point2->pos_x, square->point2->pos_y);
    printf("\nP3 %d %d", square->point3->pos_x, square->point3->pos_y);
    printf("\nP4 %d %d", square->point4->pos_x, square->point4->pos_y);
}

//Prototypes of functions of Structure Rectangle
Rectangle *create_rectangle(Point * point, int width, int height) {
    Rectangle *rectangle = (Rectangle *) malloc(width * height * sizeof(rectangle)); //allocate dynamically the structure rectangle

    rectangle->length = width;
    rectangle->width = height;

    //Point 1
    rectangle->initialpoint->pos_x = point->pos_x;
    rectangle->initialpoint->pos_y = point->pos_y;


    Point * r2; //define the 3 others points
    Point * r3;
    Point * r4;

    //Point 2
    r2 = create_point(point->pos_x, point->pos_y + rectangle->length);
    rectangle->ndpoint->pos_x = r2->pos_x;
    rectangle->ndpoint->pos_y = r2->pos_y;

    //Point 3
    //r3 = create_point(point->pos_x + rectangle->width, point->pos_y);
    //rectangle->rdpoint->pos_x = r3->pos_x;
    //rectangle->rdpoint->pos_y = r3->pos_y;

    //Point 4
    //r4 = create_point(point->pos_x + rectangle->width, point->pos_y + +rectangle->length);
    //rectangle->thpoint->pos_x = r4->pos_x;
    //rectangle->thpoint->pos_y = r4->pos_y;

    return rectangle;
}
void delete_rectangle(Rectangle * rectangle)
{
    free(rectangle); //free the memory dynamically allocated for the rectangle
}
void print_rectangle(Rectangle * rectangle)
{
    printf("\nRECTANGLE P1 %d %d %d %d", rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y,rectangle->length, rectangle->width); //p1 pos_x,p1 pos_y, length
    printf("\nP2 %d %d", rectangle->ndpoint->pos_x, rectangle->ndpoint->pos_y); //p1 pos_x,p1 pos_y, length
    printf("\nP3 %d %d", rectangle->rdpoint->pos_x, rectangle->rdpoint->pos_y); //p1 pos_x,p1 pos_y, length
    printf("\nP4 %d %d", rectangle->thpoint->pos_x, rectangle->thpoint->pos_y); //p1 pos_x,p1 pos_y, length
}

//Prototypes of the functions of Structure Circle
Circle *create_circle(Point * center, int radius)
{
    Circle * circle= (Circle*)malloc(radius*sizeof(Circle));
    circle->radius = radius;
    circle->center = center;

    return circle;
}
void delete_circle(Circle * circle)
{
    free(circle);
}
void print_circle(Circle * circle)
{
    printf("\nCIRCLE Point_center %d %d %d", circle->center->pos_x, circle->center->pos_y, circle->radius);
}

//Prototypes of the functions of Structure Circle
Polygon *create_polygon(int n)
{
    Polygon * polygon = (Polygon*)malloc(n*n*sizeof(Polygon));

    return polygon;
}
void delete_polygon(Polygon * polygon)
{
    free(polygon);
}
void print_polygon(Polygon * polygon)
{
    printf("\nPOLYGON Array of Points");
    printf("\n");
    for (int i =0; i<polygon->n; i++) {
        print_point(polygon->points[i]);
    }
}
