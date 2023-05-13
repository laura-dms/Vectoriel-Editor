#include "Pixel.h"
#include "shapes.h"
#include "area.h"
#include "Structure_shape.h"

#ifndef PIXEL_SHAPE_H
#define PIXEL_SHAPE_H

void pixel_point(Point* point, Pixel*** pixel, int* nb_pixels);
void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels);
void pixel_square(Square* square, Pixel*** pixel, int* nb_pixels);
void pixel_rectangle(Rectangle * rectangle, Pixel*** pixel, int* nb_pixels);
void pixel_circle(Circle * circle, Pixel*** pixel, int* nb_pixels);
void pixel_polygon(Polygon * polygon, Pixel*** pixel, int* nb_pixels);
void pixel_shape(Shape* shape, Pixel*** pixel, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel*** pixel, int* nb_pixels);

#endif
