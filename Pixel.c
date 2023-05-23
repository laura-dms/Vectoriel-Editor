#include "pixel.h"
#include <stdlib.h>

Pixel* create_pixel(int px, int py){
    Pixel * pixel = (Pixel*)malloc(sizeof(Pixel));
    pixel->px=px;
    pixel->py=py;
    return pixel;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}
