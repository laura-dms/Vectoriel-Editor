#include "pixel.h"
#include <stdlib.h>

Pixel* create_pixel(int px, int py)
/*allocate a memory space of type Pixel, initialize it
 * and return the address of the allocated memory space*/
{
    Pixel * pixel = (Pixel*)malloc(sizeof(Pixel)); //dynamic allocation

    pixel->px=px; //fill the attributes of the structure pixel
    pixel->py=py;

    return pixel;
}

void delete_pixel(Pixel* pixel)
{
    free(pixel);
}