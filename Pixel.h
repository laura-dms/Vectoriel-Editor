#ifndef PIXEL_H
#define PIXEL_H

struct pixel { //coordinates of the points to be filled in the drawing area
    int px;
    int py;
};
typedef struct pixel Pixel;

//Definitions of functions about the structure Pixel

Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);

#endif