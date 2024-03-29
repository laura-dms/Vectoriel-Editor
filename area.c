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

int delete_shape_in_area(Area* area, int id){
    NODE* tmp = area->shapes;
    NODE* ptmp;
    if(tmp != NULL && tmp->value->id == id){
        area->shapes = tmp->succ;
        delete_shape(tmp->value);
        return 1;
    }
    while(tmp != NULL && tmp->value->id != id){
        ptmp = tmp;
        tmp = tmp->succ;
    }
    if(tmp == NULL){
        printf("\nThe shape with the given id doesn't exist !");
        return 0;
    }
    ptmp->succ = tmp->succ;
    tmp->succ = NULL;
    delete_shape(tmp->value);
    return 1;
}

void clear_area(Area* area){ //✅
    int i,j;
    for (i=0; i<area->height; i++){
        for (j=0; j<area->width; j++){
            area->mat[i][j]=0;
        }
    }
}

void erase_area(Area* area){ // ️delete all the shapes in the drawing area and the list of shapes
    clear_area(area);
    delete_list(&(area->shapes));
}

void delete_area(Area* area){ //delete the area
    erase_area(area);
    free(area);
}

void draw_area(Area* area){
    ////check if there is enough space in the area to store the shape ???
    NODE* tmp = area->shapes;
    while (tmp != NULL){
        int nb_pix = 0;
        Pixel**List_Pixels=create_shape_to_pixel(tmp->value, &nb_pix);
        for (int j=0; j<nb_pix; j++){
            if ((List_Pixels[j]->px >= 0) && (List_Pixels[j]->px <= area->height) && (List_Pixels[j]->py) >= 0 && (List_Pixels[j]->py <= area->width)){
                area->mat[List_Pixels[j]->px-1][List_Pixels[j]->py-1]=1;
            }
            else{
                continue;}
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
