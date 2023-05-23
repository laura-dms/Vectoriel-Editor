/*Project Vector Text-based Editor, Laura Damas and Laura Poilane, L1 Int1
File that contains the definitions of the functions about the structure shape*/

#ifndef STRUCTURE_SHAPE_H
#define STRUCTURE_SHAPE_H
#include "shapes.h"

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct shape {
    unsigned int id; //unique id of the shape
    SHAPE_TYPE shape_type;
    void *ptrShape;
}Shape;

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif
