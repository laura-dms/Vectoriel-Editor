#include "area.h"
#include "Structure_shape.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "shapes.h"

//Functions about the structure area//
Area* create_area(unsigned int width, unsigned int height) //create a zone of type are
{
    Area * area = (Area*)malloc(width*height*sizeof(Area));//allocate the memory necessary to store the array of pixels//
    area->width = width;
    area->height = height;

    NODE ** list_shapes = NULL;//(Shape*)malloc(sizeof(Shape));
    area->shapes=list_shapes; //allocate dynamically the list of shapes

    return area;  //returns a pointer to area
}

void add_shape_to_area(Area* area, Shape* shape) /*insert the shape given in parameter into the array of shapes and increment
                                                nb_shape*/
{
    area->shapes=add_end_list(area->shapes, shape); //replace the previous list NODES** shapes
    area->nb_shape+=1;
}

void clear_area(Area* area) //initialise all the pixels to 0//
{
    int i,j;
    for (i=0; i<area->width; i++)
    {
        for (j=0; j<area->height; j++)
        {
            area->mat[i][j]=0;
        }
    }
}

void erase_area(Area* area) /*delete all the shapes in the drawing area
 * a drawing area with all the associated shapes*/
{
    free(area->shapes); //free all the memory linked to the shapes in the shape array
}

void delete_area(Area* area)
{
    free(area->mat);
}

void draw_area(Area* area)
{    //check if there is enough space in the area to store the shape
    int length = 0, height=0;
    for (int i=0; i<area->nb_shape; i++)
    {
        /*switch(area->shapes[i]->shape_type) {
            case 0:
                length = 1;
                height = 1;
                print_point(area->shapes[i]->ptrShape); //use the functions from structures shape
                break;
            case 1:
                height = 1;
                //length = ?? //how to calculate the length
                print_line(area->shapes[i]->ptrShape);
                break;
            case 2:
                print_square(area->shapes[i]->ptrShape);
                break;
            case 3:
                print_rectangle(area->shapes[i]->ptrShape);
                break;
            case 4:
                print_circle(area->shapes[i]->ptrShape);
                break;
            case 5:
                print_polygon(area->shapes[i]->ptrShape);
        }*/
    }
}

void print_area(Area* area) //draw the 2D matrix with the shapes in the console
{
    /*for each shape of type Shape, it must call
     * the function Pixel** create_shape_to_pixel(Shape* shape)
     * (which will be described later in this document) which must
     * return the list of pixels to be coloured.

    Run through the list of pixels to be coloured and set 0 or 1 to mat
    Pixel**List_Pixels=create_shape_to_pixel(Shape* shape);
    for (int i=0; i<area->nb_shape; i++)
    {
        if (*List_Pixels[i]==0)
        {
            area->mat[i]=0;
        }
        else if (*List_Pixels[i]==1)
        {
            area->mat[i]=1;
        }
    }
}*/