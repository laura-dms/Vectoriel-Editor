#include "shapes.h"
#include <stdlib.h>
#include "Structure_shape.h"
#include "id.h"
#include <stdio.h>

//Create a dynamic allocation which contains the type of shape given in parameter
Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py){
    Shape *shp = create_empty_shape(POINT);
    Point *point = create_point(px, py);
    shp->ptrShape = point;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Line * line = create_line(create_point(px1,py1), create_point(px2,py2));
    shp->ptrShape = line;
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Square * square = create_square(create_point(px,py), length);
    shp->ptrShape = square;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle * rectangle = create_rectangle(create_point(px, py), width, height);
    shp->ptrShape = rectangle;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Circle * circle = create_circle(create_point(px, py), radius);
    shp->ptrShape = circle;
    return shp;
}

Shape *create_polygon_shape(int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon * poly = create_polygon(n);
    shp->ptrShape = poly;
    return shp;
}

void delete_shape(Shape * shape){
    switch(shape->shape_type){
        case 0: delete_point(shape->ptrShape);break;
        case 1: delete_line(shape->ptrShape);break;
        case 2: delete_square(shape->ptrShape);break;
        case 3: delete_rectangle(shape->ptrShape);break;
        case 4: delete_circle(shape->ptrShape);break;
        case 5: delete_polygon(shape->ptrShape);break;
    }
}

void print_shape(Shape * shape){
    switch(shape->shape_type){
        case 0: print_point(shape->ptrShape);break;
        case 1: print_line(shape->ptrShape);break;
        case 2: print_square(shape->ptrShape);break;
        case 3: print_rectangle(shape->ptrShape);break;
        case 4: print_circle(shape->ptrShape);break;
        case 5: print_polygon(shape->ptrShape);
    }
    printf("\nID: %d\n", shape->id);
}
