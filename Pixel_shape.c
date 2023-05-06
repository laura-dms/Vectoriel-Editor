#include "Pixel.h"
#include "shapes.h"
#include "area.h"
#include "Structure_shape.h"
#include "Pixel_shape.h"
#include <stdlib.h>
#include <minmax.h>
#define MAX_PIXELS 100
#include <stdio.h>

void pixel_point(Point * point, Pixel** pixel, int* nb_pixels) //use & in the call
{
    pixel[0] = create_pixel(point->pos_x, point->pos_y); //create an array of pixels of 1 box
    *nb_pixels = 1;
}

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels)
{
    int dx, dy, dmin, dmax;
    dx=line->p2->pos_x - line->p1->pos_x; //distance in the x axis to reach the 2nd point of the line
    dy=line->p1->pos_y - line->p1->pos_y; //distance in the y axis to reach the 2nd point of the line

    dmin=min(dx, abs(dy)); //distance minimum
    dmax=max(dx, abs(dy)); //distance maximum

    int nb_segs= dmin+1; //number of segments in the line

    int size_pixel=(dmax+1)/(dmin+1); //size of basic segment

    int* segments = (int*) malloc(nb_segs*sizeof (int)); //array which contains the size of each pixel

    for (int i=0; i<nb_segs; i++) //array of segments that contains the size of each segment
    {
        segments[i]=size_pixel;
    }

    //Distribute the missing pixels on the segments
    int remaining = (dmax+1)%(dmin+1);
    *nb_pixels=(dmin+1)*size_pixel+remaining; //total numbers of pixels to create the line
    //operation : number of segments * size of 1 pixel + remaining pixels

    //int max_pixels = (dmax+1)*size_pixel + remaining;

    //Calculate the number of pixels remaining (containing 0 or 1) and update the table of segments
    int* cumuls = (int *)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;

    for (int i = 1; i < nb_segs;i++)
    {
        cumuls[i] = ((i+1)*remaining)%(dmin+1) < (i*remaining)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }

    //as we start the calculation from A, we remove 1 pixel to 1st segment
    segments[0]= segments[0]-1;

    //Fill the array of structure pixel
    int pos_1_x = line->p1->pos_x;
    int pos_1_y = line->p1->pos_y;

    pixel_point(line->p1, &*pixel, &*nb_pixels); ////add to the array of pixels the starting point of the line

    int pixel_index = 1; // initialize the index of the pixel array

    for (int i=0; i<nb_segs; i++)
    {
        for (int j=0; j<segments[i]; j++) //array of segments size
        {

            //// check if the pixel array is full
            if (pixel_index >= MAX_PIXELS)
            {
                //// handle the error
                printf("Error: the pixel array is full\n");
                break; ////exit(1) = exit the program
            }

            if (dy<0) ////trace down : inverse direction
            {
                if (dx>abs(dy)) ////segments are horizontal
                {
                    if (segments[i]==1) ////if there is only one segment
                    {
                        pixel[pixel_index]=create_pixel(pos_1_x,pos_1_y); //// fill the coordinates of the structure pixel
                                                                                 //// and associate the structure pixel to a box of the array
                        dy--;
                        pos_1_x++; ////increase the x position
                        break; ////exit
                    }
                    else
                    {
                        pixel[pixel_index]=create_pixel(pos_1_x,pos_1_y);
                        dy--;
                        pos_1_x++;
                    }
                }
                else
                {
                    ////the segments are vertical
                    pixel[pixel_index]=create_pixel(dx,abs(dy));
                    dx--;
                    pos_1_y--;
                }
            }
            else ////trace up
            {
                if (dx>dy)
                {
                    ////segments are horizontal
                    pixel[pixel_index]=create_pixel(dx,dy);
                    dy++;
                    pos_1_x++;
                }
                else
                {
                    ////segments are vertical
                    pixel[pixel_index]=create_pixel(dx,dy);
                    dx++;
                    pos_1_y++;
                }
            }
            pixel_index++;
        }
    }
}

void pixel_shape(Shape* shape, Pixel** pixel, int* nb_pixels)
{
    switch(shape->shape_type){
        case 0: pixel_point(shape->ptrShape,pixel, nb_pixels);break;
        case 1: pixel_line(shape->ptrShape,pixel, nb_pixels );break;
        case 2: pixel_square(shape->ptrShape, pixel, nb_pixels);break;
        case 3: pixel_rectangle(shape->ptrShape, pixel, nb_pixels);break;
        case 4: pixel_circle(shape->ptrShape, pixel, nb_pixels);break;
        case 5: pixel_polygon(shape->ptrShape, pixel, nb_pixels);
    }
}

void pixel_circle(Circle * circle, Pixel** pixel, int* nb_pixels)
{
    //// POINT GENERATION ////
    int x=0, y=circle->radius,d=circle->radius-1;
    int k=0; //number of items in the array of pixels
    Pixel * px = NULL;

    while (y>=x)
    {
        //// ***DRAW EIGHT SYMMETRICAL POINTS***////

        /// Add the point to the first octant : Point1 (p_x + x, p_y + y)
        px=create_pixel(circle->center->pos_x + x, circle->center->pos_y + y);
        pixel[k++]= px;

        //// Add the point for the octant opposite : Point2 (p_x + y, p_y + x)
        px=create_pixel(circle->center->pos_x + y, circle->center->pos_y + x);
        pixel[k++]= px;

        ////Add the point to the 2nd octant : Point3 (p_x - x, p_y + y)
        px=create_pixel(circle->center->pos_x - x, circle->center->pos_y + y);
        pixel[k++]= px;

        ////Add the point to the octant opposite : Point4 (p_x - y, p_y + x)
        px=create_pixel(circle->center->pos_x - y, circle->center->pos_y + x);
        pixel[k++]= px;

        ////Add the point to the octant opposite : Point5 (p_x + x, p_y - y)
        px=create_pixel(circle->center->pos_x + x, circle->center->pos_y - y);
        pixel[k++]= px;

        ////Add the point to the octant opposite : Point6 (p_x + y, p_y - x)
        px=create_pixel(circle->center->pos_x + y, circle->center->pos_y - x);
        pixel[k++]= px;

        ////Add the point to the octant opposite : Point7 (p_x - x, p_y - y)
        px=create_pixel(circle->center->pos_x - x, circle->center->pos_y - y);
        pixel[k++]= px;

        ////Add the point to the octant opposite : Point8 (p_x - y, p_y - x)
        px=create_pixel(circle->center->pos_x - y, circle->center->pos_y - x);
        pixel[k++]= px;

        if (d<2*x) ////the plot error delta is negative
        //// error /!\ : marquer >= sur le pdf ////
        {
            d+= 2*x+1; ////error : written add but -= in the pseudo-code
            x++;
        }
        else if (d>=(2*(circle->radius - y))) ////the plot error delta is positive
        {
            d+=2*y-1;
            y--;
            x++;
        }
        else
        {
            d+=2*(y-x-1);
            y--;
            x++;
        }
    }
    ////When x becomes greater than y, it means that all the points of the circle have been added to the array of pixels.
    *nb_pixels=k; ////number of items
}

void pixel_square(Square* square, Pixel** pixel, int* nb_pixels)
{
    ////Above horizontal line
    pixel_line(create_line(square->point1, create_point(square->point1->pos_x, square->point1->pos_y + square->length)), pixel, nb_pixels );

    ////Left vertical line
    pixel_line(create_line(square->point1, create_point(square->point1->pos_x + square->length, square->point1->pos_y)), pixel ,nb_pixels);

    ////Right vertical line
    pixel_line(create_line(create_point(square->point1->pos_x, square->point1->pos_y + square->length), create_point(square->point1->pos_x + square->length, square->point1->pos_y + square->length)), pixel, nb_pixels);

    ////Below horizontal line
    pixel_line(create_line(create_point(square->point1->pos_x + square->length, square->point1->pos_y), create_point(square->point1->pos_x + square->length, square->point1->pos_y + square->length)), pixel, nb_pixels);
}

void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels)
{
    ////Above horizontal line
    pixel_line(create_line(rectangle->initialpoint, create_point(rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y + rectangle->length)), pixel, nb_pixels );

    ////Left vertical line
    pixel_line(create_line(rectangle->initialpoint, create_point(rectangle->initialpoint->pos_x + rectangle->width, rectangle->initialpoint->pos_y)), pixel ,nb_pixels);

    ////Right vertical line
    pixel_line(create_line(create_point(rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y + rectangle->length), create_point(rectangle->initialpoint->pos_x + rectangle->width, rectangle->initialpoint->pos_y )), pixel, nb_pixels);

    ////Below horizontal line
    pixel_line(create_line(create_point(rectangle->initialpoint->pos_x + rectangle->width, rectangle->initialpoint->pos_y), create_point(rectangle->initialpoint->pos_x + rectangle->width, rectangle->initialpoint->pos_y + rectangle->length)), pixel, nb_pixels);
}

void pixel_polygon(Polygon* polygon, Pixel** pixel, int* nb_pixels)
{
    for (int i=0; i<polygon->n; i++) ////run through the list of points of polygon
    {
        pixel_line(create_line(polygon->points[i], polygon->points[i+1]), pixel, nb_pixels );
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels) ////transform any shape into a set of pixels
{
    switch(shape->shape_type){
        case 0: pixel_point(shape->ptrShape);break;
        case 1: pixel_line(shape->ptrShape);break;
        case 2: pixel_square(shape->ptrShape);break;
        case 3: pixel_rectangle(shape->ptrShape);break;
        case 4: pixel_circle(shape->ptrShape);break;
        case 5: pixel_polygon(shape->ptrShape);break;
    }
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels) ////free the memory of the allocated pixels
{
    free(pixel);
}
