#include "area.h"
#include "Pixel_shape.h"
#include "Structure_shape.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "shapes.h"

//Functions about the structure area//
Area* create_area(unsigned int height, unsigned int width){//✅
    Area * area = (Area*)malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**) malloc(height*sizeof(BOOL*));
    for (int i = 0; i < height; i++){
        area->mat[i] = (BOOL*)malloc(width*sizeof(BOOL));
    }
    area->shapes=NULL;
    area->nb_shape = 0;

    return area;  //returns a pointer to area
}

void add_shape_to_area(Area* area, Shape* shape){ //✅ insert the shape given in parameter into the array of shapes and increment nb_shape
    area->shapes=add_to_list(area->shapes, shape); //replace the previous list NODES* shapes
    area->nb_shape+=1;
}

void clear_area(Area* area){ //✅
    int i,j;
    for (i=0; i<area->height; i++){
        for (j=0; j<area->width; j++){
            area->mat[i][j]=0;
        }
    }
}

void erase_area(Area* area){ // ⚠️delete all the shapes in the drawing area and the list of shapes
    clear_area(area);
    free(area->shapes); ///Il faut free les nodes 1 par 1
}

void delete_area(Area* area){ //delete the area
    erase_area(area);
    free(area);
}

void draw_area(Area* area){ //⚠️
    ////check if there is enough space in the area to store the shape ???
    NODE* tmp = area->shapes;
    while (tmp != NULL){
        int nb_pix = 0;
        Pixel**List_Pixels=create_shape_to_pixel(tmp->value, &nb_pix);
        for (int j=0; j<nb_pix; j++){
            area->mat[List_Pixels[j]->px][List_Pixels[j]->py]=1;
        }
        delete_pixel_shape(&List_Pixels, nb_pix);
        tmp = tmp->succ;
    }
}

void print_area(Area* area){ //draw the 2D matrix with the shapes in the console ✅
    printf("\n");
    for (int i = 0; i < area->height; i++){
        for (int j = 0; j < area->width; j++){
            if (area->mat[i][j] == 0){
                printf(". ");
            }
            if(area->mat[i][j] == 1){
                printf("# ");
            }
        }
        printf("\n");
    }
}
