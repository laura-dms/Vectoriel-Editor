#include "Pixel.h"
#include "shapes.h"
#include "area.h"
#include "Structure_shape.h"
#include "Pixel_shape.h"
#include <stdlib.h>
#include <math.h>
#include <minmax.h>

void pixel_point(Point* point, Pixel** pixel, int* nb_pixels) //use & in the call
{
    Point* pt = create_point(10,15);//OR (Point*)malloc(sizeof(shape->ptrShape);
    Pixel** pixel_tab = (Pixel**) malloc (sizeof (Pixel*)); //array of pixels
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y); //create an array of pixels of 1 box
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
    //number of segments * size of 1 pixel + remaining pixels

    //Calculate the number of pixels remaining and update the table of segments
    int *cumuls = (int *)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;

    for (int i = 1; i < nb_segs;i++)
    {
        cumuls[i] = ((i*remaining)%(dmin+1) < (i-1)*remaining)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }

    //Fill the array of structure pixel
    int pos_1_x = line->p1->pos_x;
    int pos_1_y = line->p1->pos_y;

    for (int i=0; i<nb_segs; i++)
    {
        for (int j=0; j<segments[i]; j++) //array of segments size
        {
            if (dy<0) //trace down : inverse direction
            {
                if (dx>abs(dy)) //segments are horizontal
                {
                    if (segments[i]==1) //if there is onl
                    {
                        pixel[j]=create_pixel(pos_1_x,pos_1_y);
                        dy--;
                        pos_1_x++; //increase the x position
                    }
                    else
                    {
                        pixel[j]=create_pixel(pos_1_x,pos_1_y);
                    }
                }
                else
                {
                    //the segments are vertical
                    pixel[j]=create_pixel(dx,abs(dy));
                    dx--;
                }
            }
            else//trace up
            {
                if (dx>dy)
                {
                    //segments are horizontal
                    pixel[j]=create_pixel(dx,dy);
                    dy++;
                }
                else
                {
                    //segments are vertical
                    pixel[j]=create_pixel(dx,dy);
                    dx++;
                }
            }
        }
        //fill the coordinates of the structure pixel
        //associate the structure pixel to a box of the array
    }

}

/*void pixel_shape(Shape* shape, Pixel** pixel, int* nb_pixels)
{
    switch(shape->shape_type){ //problem : &* ??
        case 0: pixel_point(shape->ptrShape,&*pixel, &*nb_pixels);break;
        case 1: pixel_line(shape->ptrShape,&*pixel, &*nb_pixels );break;
        case 2: pixel_square(shape->ptrShape, &*pixel, &*nb_pixels);break;
        case 3: pixel_rectangle(shape->ptrShape, &*pixel, &*nb_pixels);break;
        case 4: pixel_circle(shape->ptrShape, &*pixel, &*nb_pixels);break;
        case 5: pixel_polygon(shape->ptrShape, &*pixel, &*nb_pixels);
    }
}*/