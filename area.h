#ifndef AREA_H
#define AREA_H

#define BOOL int
#include "list.h"
#include "Structure_shape.h"

//Definition of the structure are//
struct area {
    unsigned int width; // Number of pixels in width or number of columns (y-axis)
    unsigned int height; // Number of pixels in height or number of lines (x axis)
    BOOL ** mat; //2D array of int + pixel size matrix (width * height) + 0 if the pixel is empty or 1 if full
    NODE* shapes; // array of shapes = drawing area
    int nb_shape; // number of shapes in the shapes array (logical size)
};
typedef struct area Area;

//Prototypes of the functions about the structure area

Area* create_area(unsigned int height, unsigned int width);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

#endif
