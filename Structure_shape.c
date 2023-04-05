#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>
#include "Structure_shape.h"

//Create a dynamic allocation which contains the type of shape given in parameter
Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL; //void pointer
    shp->id = 1; //called later get_next_id() = address of the next box of SLL;
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Line * l = create_line(create_point(px1,py1), create_point(px2,py2));
    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length)
{
    Shape *shp = create_empty_shape(SQUARE);
    Square * s = create_square(create_point(px,py), length);
    shp->ptrShape = s;
    return shp;
}
Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle * r = create_rectangle(create_point(px, py), width, height);
    shp->ptrShape = r;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Circle * c = create_circle(create_point(px, py), radius);
    shp->ptrShape = c;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n) //lst[] ) = 1D array of Point* of the polygon (
{
    Shape *shp = create_empty_shape(POLYGON);
    Polygon * poly = create_polygon(n);
    shp->ptrShape = poly;
    return shp;
}

void delete_shape(Shape * shape)
{
    free(shape); //free the dynamic allocated memory of shape
}

void print_shape(Shape * shape)
{

}