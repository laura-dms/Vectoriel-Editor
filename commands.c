#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "area.h"
#include "list.h"


Command* create_command(){ //create a variable of type command
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->name = (char*)malloc(10*sizeof(char));
    cmd->int_params = (int*)malloc(30*sizeof(int));
    cmd->int_size = 0;
    cmd->str_params = (char**)malloc(5*sizeof(char*));
    cmd->str_size = 0;
    return cmd;
}

void add_str_param(Command* cmd, char* p){
    cmd->str_params[cmd->str_size] = p;
    cmd->str_size++;
}

void add_int_param(Command* cmd, int p){
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command* cmd){
    free(cmd->str_params);
    free(cmd);
}

int read_exec_command(Command** cmd, Area** draw_zone){

    if (!strcmp((*cmd)->name, "clear")){
        clear_area(*draw_zone);
        printf("The area has been cleared !\n");
    }

    else if (!strcmp((*cmd)->name, "exit")){
        printf("\nBye !");
        return 0;
    }

    else if (!strcmp((*cmd)->name, "point")){
        Shape* shape1 = create_point_shape(((*cmd)->int_params)[0], ((*cmd)->int_params)[1]);
        add_shape_to_area(*draw_zone, shape1);
        printf("The shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "line")){
        Shape* line1 = create_line_shape(((*cmd)->int_params)[0],((*cmd)->int_params)[1],((*cmd)->int_params)[2],((*cmd)->int_params)[3]);
        add_shape_to_area(*draw_zone, line1);
        printf("The shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "circle")){
        Shape* circle1 = create_circle_shape(((*cmd)->int_params)[0], ((*cmd)->int_params)[1], ((*cmd)->int_params)[2]);
        add_shape_to_area(*draw_zone, circle1);
        printf("The shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "square")){
        Shape* square1 = create_square_shape(((*cmd)->int_params)[0],((*cmd)->int_params)[1],((*cmd)->int_params)[2]);
        add_shape_to_area(*draw_zone, square1);
        printf("The shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "rectangle")){
        Shape* rectangle1 = create_rectangle_shape(((*cmd)->int_params)[0],((*cmd)->int_params)[1],((*cmd)->int_params)[2],((*cmd)->int_params)[3]);
        add_shape_to_area(*draw_zone, rectangle1);
        printf("\nThe shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "polygon")){ 
        Shape* polygon1 = create_polygon_shape(4);
        add_shape_to_area(*draw_zone, polygon1);
        printf("\nThe shape has been correctly added !\n");
    }

    else if (!strcmp((*cmd)->name, "plot")){
        draw_area(*draw_zone);
        print_area(*draw_zone);
    }

    else if (!strcmp((*cmd)->name, "list")){
        printf("\nHere is the list of shapes: \n");
        print_list((*draw_zone)->shapes);
    }

    else if (!strcmp((*cmd)->name, "delete")){
        delete_shape_in_area(*draw_zone, ((*cmd)->int_params)[0]);
    }

    else if (!strcmp((*cmd)->name, "erase")){
        erase_area(*draw_zone);
        printf("The area has been erased\n");
    }

    else if (!strcmp((*cmd)->name, "help")){
        printf("\n----------------------------------------------------------------------------------\n"
               "\nEach command must be of the form : <command name> [parameters]."
               "\nThe presence of parameters is optional as it depends on the type of command to be given.\n\n"
               "In this project, the list of commands that the program can interpret is as follows:\n\n"
               "~ point x y : add a point\n"
               "~ line x1 y1 x2 y2 : add a segment connecting two points (x1, y1) and (x2, y2)\n"
               "~ circle x y radius : add a circle of centre (x, y) and a radius radius\n"
               "~ square x y length : add a square whose upper left corner is (x, y) and whose size is length.\n"
               "~ rectangle x y width height : add a rectangle whose upper left corner is (x, y), whose width\n"
               "is width and whose height is height\n"
               "~ polygon x1 y1 x2 y2 x3 y3 : add a polygon with the list of given points\n\n"
               "~ plot : refresh the screen to display all the geometric shapes in the image (depending on the\n"
               "display rules)\n"
               "~ list : display a list of all the geometric shapes that make up the image and all their information\n"
               "~ delete id : delete a shape from its identifier id.\n"
               "~ clear : clear the screen\n"
               "~ erase : delete the list of shapes\n"
               "~ help : display the list\n"
               "~ exit : exit the program\n");
    }

    else{
        printf("\nNo corresponding command found (try to add a space at the end of your command)\n");
    }

    return 1;
}

void read_from_stdin(Command** cmd){ //Fill the structure command
    printf("\n>> ");
    char* word = (char*)malloc(10*sizeof(char));
    fgets(word,50, stdin);
    char** sentence= split_strings(word);

    unsigned int len=strlen(sentence[0]);
    for (int i=0; i<len; i++){
        ((*cmd)->name)[i]=sentence[0][i];
    }
    ((*cmd)->name)[len] = '\0';

    //If it is a command that requires int parameters, we fill them
    if (strcmp(sentence[0],"line")==0 || strcmp(sentence[0],"point")==0 || strcmp(sentence[0],"circle")==0 || strcmp(sentence[0],"square")==0 || strcmp(sentence[0],"rectangle")==0 || strcmp(sentence[0],"polygon")==0 || strcmp(sentence[0],"delete")==0){

        int size_sentence = -1;
        while (sentence[++size_sentence]!=NULL){ //Compute the size of the command
        }

        for (int i=0; i<size_sentence; i++){
            if ((sentence[i][0])>=48 && (sentence[i][0])<=57 && sentence[i][0]!='\0'){
                int num = atoi(sentence [i]); //transform a string into a integer
                add_int_param(*cmd, num);
            }
        }
    }

    free(sentence);
    free(word);
}

char** split_strings(char* str){ //function to split a sentence
    char** sentence = (char**) malloc(100*sizeof(char*));
    char* copy = strdup(str);
    char* word = strtok(copy, " ");
    int cptw = 0;

    while (word != NULL && cptw < 10){
        sentence[cptw] = (char*)malloc(10*sizeof(char));
        strcpy(sentence[cptw], word);
        word = strtok(NULL, " ");
        cptw++;
    }
    free(copy);
    sentence[cptw] = NULL;

    return sentence;
}
