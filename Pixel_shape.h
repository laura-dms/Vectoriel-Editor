#include "Pixel.h"
#include "shapes.h"
#include "area.h"
#include "Structure_shape.h"

#ifndef PIXEL_SHAPE_H
#define PIXEL_SHAPE_H

void pixel_shape(Shape* shape, Pixel** pixel, int* nb_pixels);
/* Parameters :
 * - pointer to the shape to be drawn (point, line, circle...)
 * - array of pointers to pixels (double pointer)
 * -A pointer to an integer representing the logical size
 * of the array of pixels and which is updated
 * each time a pixel is added to the array.
 * => implement this function for each SHAPE TYPE*/

//Store the position of the point to be plotted in the array of pixels//
void pixel_point(Point* point, Pixel** pixel, int* nb_pixels);

//Calculate the positions of the points to draw a line
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);

void pixel_square(Square* square, Pixel** pixel, int* nb_pixels);

void pixel_rectangle(Rectangle * rectangle, Pixel** pixel, int* nb_pixels);

void pixel_circle(Circle * circle, Pixel** pixel, int* nb_pixels);

void pixel_polygon(Polygon * polygon, Pixel** pixel, int* nb_pixels);

#endif