#include "area.h"
#include "Pixel_shape.h"
#include "Structure_shape.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "shapes.h"

//Functions about the structure area//
Area* create_area(unsigned int width, unsigned int height){
    Area * area = (Area*)malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**) malloc(height*sizeof(BOOL));
    for (int i = 0; i < height; i++){
        area->mat[i] = malloc(width*sizeof(BOOL));
    }
    NODE* list_shapes = NULL;
    area->shapes=list_shapes;
    area->nb_shape = 0;

    return area;  //returns a pointer to area
}

void add_shape_to_area(Area* area, Shape* shape){ /*insert the shape given in parameter into the array of shapes and increment nb_shape*/
    area->shapes=add_end_list(area->shapes, shape); //replace the previous list NODES* shapes
    area->nb_shape+=1;
}

void clear_area(Area* area){ //initialize all the pixels to 0//
    int i,j;
    for (i=0; i<area->width; i++){
        for (j=0; j<area->height; j++){
            area->mat[i][j]=0;
        }
    }
}

void erase_area(Area* area){ //delete all the shapes in the drawing area and the list of shapes
    clear_area(area);
    free(area->shapes); ///Je pense qu'il faut free les nodes 1 par 1
}

void delete_area(Area* area){ //delete the area
    erase_area(area);
    free(area); ///Ptetre qu'il faut delete tous les paramètres 1 à 1 jsp
}

void draw_area(Area* area){
    ////check if there is enough space in the area to store the shape ???
    for (int i=0; i<area->nb_shape; i++){
        ////Run through the list of pixels to be coloured and set 0 or 1 to mat
        Pixel**List_Pixels=create_shape_to_pixel(area->shapes[i]);
        for (int j=0; j</*nb_pixels*/; j++){
            area->mat[List_Pixels[j]->px][List_Pixels[j]->py]=1;
        }
    }
}

void print_area(Area* area){ //draw the 2D matrix with the shapes in the console
    printf("\n");
    for (int i = 0; i < area->height; i++){
        for (int j = 0; j < area->width; j++){
            if (area->mat[i][j] == 0){
                printf(".");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }
}
