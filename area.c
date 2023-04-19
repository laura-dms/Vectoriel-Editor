#include "area.h"
#include "Structure_shape.h"
#include <stdio.h>
#include <stdlib.h>

//Functions about the structure area//
Area* create_area(unsigned int width, unsigned int height) //create a zone of type are
{
    Area * area = (int*)malloc(width*height*sizeof(int));//allocate the memory necessary to store the array of pixels//
    area->width = width;
    area->height = height;

    return area;

} //returns a pointer to area

void add_shape_to_area(Area* area, Shape* shape) /*add a shape to the drawing area
                                                *insert the shape given in parameter into the array of shapes and increment
                                                nb_shape*/
{
    //check if there is enough space in the area to store the shape
    int i,j;
    int length = 0, height=0;
    switch (shape->shape_type){

        case POINT{
            length=1;
            area->
            break;
        }
        case LINE{
            length=
            break;
        }
        case SQUARE{

            break;
        }
        case RECTANGLE{

            break;
        }
        case CIRCLE{

            break;
        }
        case POLYGON{

            break;
        }
    }

    length = shape->shape_type
    for (i=0; i<shape->ptrShape)
    if (area->shapes[i]==0)
    {
        area->shapes[0]=shape; //add a shape to the array of shapes
    }
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
    int i,j;
    for (i=0; i<area->width; i++)
    {
        for (j=0; j<area->height; j++) {

            if (area->mat[i][j]==1)
            {
                area->mat[i][j]==0;
            }
        }
    free(area->mat); //free all the memory linked to the shapes in the shape array
}

void delete_area(Area* area)
{

}

void draw_area(Area* area)
{

}

void print_area(Area* area)
{

}