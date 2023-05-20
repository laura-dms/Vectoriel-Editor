#include "Pixel.h"
#include "shapes.h"
#include "Structure_shape.h"
#include "Pixel_shape.h"
#include <stdlib.h>
#include <minmax.h>
#include <stdio.h>

void pixel_point(Point * point, Pixel*** pixel, int* nb_pixels){ //✅
    *pixel[0] = create_pixel(point->pos_x, point->pos_y);
    *nb_pixels = 1;
}

void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels){ //✅
    int dx, dy, dmin, dmax;
    ///Ajouter ici (ou dans la fct qui store la line) que le le x de p1 < x de p2 (switch si besoin)
    dx=line->p2->pos_x - line->p1->pos_x; //distance in the x axis to reach the 2nd point of the line
    dy=line->p2->pos_y - line->p1->pos_y; //distance in the y axis to reach the 2nd point of the line
    dmin=min(dy, abs(dx)); //smallest difference between coordinates
    dmax=max(dy, abs(dx)); //largest difference between coordinates

    int nb_segs= dmin+1; //number of segments in the line
    int size_pixel=(dmax+1)/(dmin+1); //size of basic segment
    int* segments = (int*) malloc(nb_segs*sizeof (int)); //array of segments
    for (int i=0; i<nb_segs; i++){
        segments[i]=size_pixel;
    }

    //Distribute the missing pixels on the segments
    int remaining = (dmax+1)%(dmin+1);

    //Calculate the number of pixels remaining (containing 0 or 1) and update the table of segments
    int* cumuls = (int *)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;
    for (int i = 1; i < nb_segs;i++){
        cumuls[i] = ((i+1)*remaining)%(dmin+1) < (i*remaining)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }

    //Variables of point positions x and y
    int x_pos = line->p1->pos_x;
    int y_pos = line->p1->pos_y;

    //int pix_ind = 0; // initialize the index of the pixel array

    for (int i=0; i<nb_segs; i++){
        for (int j=0; j<segments[i]; j++){
            if (dx >= 0){ ////trace down
                if (dy >= dx){ ////segments are horizontal
                    (*pixel)[(*nb_pixels)++] = create_pixel(x_pos, y_pos);
                    //printf("x:%d y:%d", x_pos, y_pos);
                    y_pos++;
                }
                else{ ////segments are vertical
                    (*pixel)[(*nb_pixels)++] = create_pixel(x_pos, y_pos);
                    //printf("x:%d y:%d", x_pos, y_pos);
                    x_pos++;
                }
            }
            else{ ////trace up
                if (dy >= abs(dx)){////segments are horizontal
                    (*pixel)[(*nb_pixels)++] = create_pixel(x_pos, y_pos);
                    //printf("x:%d y:%d", x_pos, y_pos);
                    y_pos++;
                }
                else{////segments are vertical
                    (*pixel)[(*nb_pixels)++] = create_pixel(x_pos, y_pos);
                    //printf("x:%d y:%d", x_pos, y_pos);
                    x_pos--;
                }
            }
        }
        if(dy >= abs(dx)){ ///vertical seg
            if(dx >=0){
                x_pos++;
            }
            else{
                x_pos--;
            }
        }
        else{ ///horizontal seg
            y_pos++;
        }
    }
    free(segments);
    free(cumuls);
}

void pixel_circle(Circle * circle, Pixel*** pixel, int* nb_pixels){ //✅
    //// POINT GENERATION ////
    int x=0, y=circle->radius,d=circle->radius-1;
    int k=0; //number of items in the array of pixels
    Pixel * px = NULL;

    while (y>=x){
        //// ***DRAW EIGHT SYMMETRICAL POINTS***////

        /// Point of the first octant
        px=create_pixel(circle->center->pos_x + x, circle->center->pos_y + y);
        (*pixel)[k++]= px;

        //// Point for the opposite octant
        px=create_pixel(circle->center->pos_x + y, circle->center->pos_y + x);
        (*pixel)[k++]= px;

        ////Add the point to the 2nd octant
        px=create_pixel(circle->center->pos_x - x, circle->center->pos_y + y);
        (*pixel)[k++]= px;

        ////Add the point to the octant opposite
        px=create_pixel(circle->center->pos_x - y, circle->center->pos_y + x);
        (*pixel)[k++]= px;

        ////Add the point to the octant opposite
        px=create_pixel(circle->center->pos_x + x, circle->center->pos_y - y);
        (*pixel)[k++]= px;

        ////Add the point to the octant opposite
        px=create_pixel(circle->center->pos_x + y, circle->center->pos_y - x);
        //printf("\nk:%d x:%d y:%d", k, circle->center->pos_x + y, circle->center->pos_y - x);
        (*pixel)[k++]= px;

        ////Add the point to the octant opposite
        px=create_pixel(circle->center->pos_x - x, circle->center->pos_y - y);
        (*pixel)[k++]= px;

        ////Add the point to the octant opposite
        px=create_pixel(circle->center->pos_x - y, circle->center->pos_y - x);
        (*pixel)[k++]= px;

        if (d>=2*x){
            d-= 2*x+1;
            x++;
        }
        else if (d<(2*(circle->radius - y))){
            d+=2*y-1;
            y--;
        }
        else{
            d+=2*(y-x-1);
            y--;
            x++;
        }
    }
    *nb_pixels=k;
}

void pixel_square(Square* square, Pixel*** pixel, int* nb_pixels){ //✅
    ////Top line
    pixel_line(create_line(square->point1, create_point(square->point1->pos_x, square->point1->pos_y + square->length-1)), pixel, nb_pixels);

    ////Left line
    pixel_line(create_line(square->point1, create_point(square->point1->pos_x + square->length-1, square->point1->pos_y)), pixel ,nb_pixels);

    ////Right line
    pixel_line(create_line(create_point(square->point1->pos_x, square->point1->pos_y + square->length-1), create_point(square->point1->pos_x + square->length-1, square->point1->pos_y + square->length-1)), pixel, nb_pixels);

    ////Bottom line
    pixel_line(create_line(create_point(square->point1->pos_x + square->length-1, square->point1->pos_y), create_point(square->point1->pos_x + square->length-1, square->point1->pos_y + square->length-1)), pixel, nb_pixels);
}

void pixel_rectangle(Rectangle* rectangle, Pixel*** pixel, int* nb_pixels){ //✅
    ////Above horizontal line
    pixel_line(create_line(rectangle->initialpoint, create_point(rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y + rectangle->length-1)), pixel, nb_pixels);

    ////Left vertical line
    pixel_line(create_line(rectangle->initialpoint, create_point(rectangle->initialpoint->pos_x + rectangle->width-1, rectangle->initialpoint->pos_y)), pixel ,nb_pixels);

    ////Right vertical line
    pixel_line(create_line(create_point(rectangle->initialpoint->pos_x, rectangle->initialpoint->pos_y + rectangle->length-1), create_point(rectangle->initialpoint->pos_x + rectangle->width-1, rectangle->initialpoint->pos_y + rectangle->length-1)), pixel, nb_pixels);

    ////Below horizontal line
    pixel_line(create_line(create_point(rectangle->initialpoint->pos_x + rectangle->width-1, rectangle->initialpoint->pos_y), create_point(rectangle->initialpoint->pos_x + rectangle->width-1, rectangle->initialpoint->pos_y + rectangle->length-1)), pixel, nb_pixels);
}

void pixel_polygon(Polygon* polygon, Pixel*** pixel, int* nb_pixels){ //✅
    for (int i=0; i<polygon->n-1; i++){ ////run through the list of points of polygon
        pixel_line(create_line(polygon->points[i], polygon->points[i+1]), pixel, nb_pixels);
    }
    pixel_line(create_line(polygon->points[0], polygon->points[(polygon->n)-1]), pixel, nb_pixels);
}

void pixel_shape(Shape* shape, Pixel*** pixel, int* nb_pixels){ //✅
    switch(shape->shape_type){
        case 0: pixel_point(shape->ptrShape,pixel, nb_pixels);break;
        case 1: pixel_line(shape->ptrShape,pixel, nb_pixels);break;
        case 2: pixel_square(shape->ptrShape, pixel, nb_pixels);break;
        case 3: pixel_rectangle(shape->ptrShape, pixel, nb_pixels);break;
        case 4: pixel_circle(shape->ptrShape, pixel, nb_pixels);break;
        case 5: pixel_polygon(shape->ptrShape, pixel, nb_pixels);break;
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){ ////transform any shape into a set of pixels
    Pixel** set_pixels = (Pixel**)malloc(200*sizeof(Pixel*)); ////initialise an array of structure pixel
    pixel_shape(shape, &set_pixels, nb_pixels); ////fill the array with the function pixel_shape
    return set_pixels; ////must returns an array of pixels
}

void delete_pixel_shape(Pixel*** pixel, int nb_pixels){ //✅ free the memory of the allocated pixels
    for (int i=0; i<nb_pixels; i++){
        delete_pixel((*pixel)[i]);
    }
    *pixel=NULL;
}
