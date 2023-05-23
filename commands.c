#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "area.h"
//#include "Structure_shape.h"

Command* create_command(){ //create a variable of type command
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->int_size = 0;
    cmd->str_size = 0;
    //int* list_int
    cmd->int_params = (int*)malloc(10*sizeof(int));
    cmd->str_params = (char**) malloc(15*sizeof(char*));
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

void read_exec_command(Command* cmd){
    Area* draw_zone = create_area(30,30);
    /*Code error :
     * 1111 => exit the program
     * -1 => no existing command*/

    if (strcmp(cmd->name, "clear")==0)
    {
        clear_area(draw_zone);
    }
    else if (strcmp(cmd->name, "exit")==0)
    {
        exit(1111);//exit the program in execution (0 : returning_value)
    }
    else if (strcmp(cmd->name, "point")==0) //add a point
    {
        Shape* shape1 = create_point_shape(5, 5);
        add_shape_to_area(draw_zone, shape1);
    }
    else if (strcmp(cmd->name, "line")==0) //add a line
    {
        Shape* line1 = create_line_shape(10,5,8,12);
        add_shape_to_area(draw_zone, line1);
    }
    else if (strcmp(cmd->name, "circle")==0)  //add a circle
    {
        Shape* circle1 = create_circle_shape(3, 3, 5);
        add_shape_to_area(draw_zone, circle1);
    }
    else if (strcmp(cmd->name, "square")==0) //add a square
    {
        Shape* square1 = create_square_shape(3,27,4);
        add_shape_to_area(draw_zone, square1);
    }
    else if (strcmp(cmd->name, "rectangle")==0) //add a rectangle
    {
        Shape* rectangle1 = create_rectangle_shape(16,9,10,4);
        add_shape_to_area(draw_zone, rectangle1);
    }
    else if (strcmp(cmd->name, "polygon")==0)
    {
        Shape* polygon1 = create_polygon_shape(4);
        add_shape_to_area(draw_zone, polygon1);
    }
    else if (strcmp(cmd->name, "plot")==0) ///refresh the screen to display all geometric shapes in the image
    {
        clear_area(draw_zone);
        draw_area(draw_zone);
        print_area(draw_zone);
    }
    else if (strcmp(cmd->name, "list")==0)
    {
        print_list(draw_zone->shapes);
    }
    else if (strcmp(cmd->name, "delete")==0)
    {
        delete_area(draw_zone);
        delete_cmd(cmd);
        //free()//delete a shape (id) from the list of shapes
        //connect the node to the next node with gets_next_id()
    }
    else if (strcmp(cmd->name, "erase")==0)
    {
        erase_area(draw_zone);
    }
    else if (strcmp(cmd->name, "help")==0)
    {
        printf("The list of commands are :\n"
               "Each command must be of the form : <command name> [parameters]. The presence of parameters\n"
               "is optional as it depends on the type of command to be given.\n"
               "In this project, the list of commands that the program must interpret is as follows:\n"
               "• clear : clear the screen\n"
               "• exit : exit the program\n"
               "• point x y : add a point\n"
               "• line x1 y1 x2 y2 : add a segment connecting two points (x1, y1) and (x2, y2)\n"
               "• circle x y radius : add a circle of centre (x, y) and a radius radius\n"
               "• square x y length : add a square whose upper left corner is (x, y) and whose side is length.\n"
               "• rectangle x y width height : add a rectangle whose upper left corner is (x, y), whose width\n"
               "is width and whose height is height\n"
               "• polygon x1 y1 x2 y2 x3 y3 : add a polygon with the list of given points\n"
               "• plot : refresh the screen to display all the geometric shapes in the image (depending on the\n"
               "display rules)\n"
               "• list : display a list of all the geometric shapes that make up the image and all their information\n"
               "• delete id : delete a shape from its identifier id.\n"
               "• erase : remove all shapes from an image.\n"
               "• help : display the list");
    }
    else
    {
        exit(-1); //no existing command
    }
}

void read_from_stdin(Command* cmd){
    printf("\n>> ");
    char word[100];
    fgets(word,100, stdin);
    char** sentence= split_strings(word); //array of strings

    //check if the type of command is correct
    if (strcmp(sentence[0],"line")==0 || strcmp(sentence[0],"point")==0 || strcmp(sentence[0],"circle")==0 || strcmp(sentence[0],"square")==0 || strcmp(sentence[0],"rectangle")==0 || strcmp(sentence[0],"polygon")==0 || strcmp(sentence[0],"delete")==0)  {
        //printf("\nGOOD NAME \n");
        int len=strlen(sentence[0]);
        for (int i=0; i<len; i++)
        {
            if (sentence[0][i]>=97 && sentence[0][i]<=122)
            {
                cmd->name[i]=sentence[0][i]; //add the command to the command's name
            }
        }
        //printf("\nName command : %s of size %d", cmd->name, len);
        ///Calculate the length of the array of strings
        int size_sentence = -1;
        while (sentence[++size_sentence]!=NULL)
        {
            ///do nothing
        }
        //printf("\nSize of sentence : %d", size_sentence);

        ///Add integers to the array of integers of command

        for (int i=0; i<size_sentence; i++) ///run through the array of strings
        {
            if ((sentence[i][0])>=48 && (sentence[i][0])<=57 && sentence[i][0]!='\0'){  //check if this is an integer [0,9] with ascii code
                int num = atoi(sentence [i]); //transform a string into a integer
                add_int_param(cmd, num);
            }
        }
        /*printf("\n\nArray of integers of size %d: ", cmd->int_size);
        for (int r=0; r<cmd->int_size; r++)
        {
            printf("\n%d", cmd->int_params[r]);
        }*/
    }
    else if ((strcmp(sentence[0],"clear")==0 || strcmp(sentence[0],"exit")==0 || strcmp(sentence[0],"plot")==0 || strcmp(sentence[0],"list")==0 || strcmp(sentence[0],"erase")==0 || strcmp(sentence[0],"help")==0)) {
        printf("\nGOOD NAME \n");
        int len = strlen(sentence[0]);
        for (int i = 0; i < len; i++) {
            if (sentence[0][i] >= 97 && sentence[0][i] <= 122) {
                cmd->name[i] = sentence[0][i]; //add the command to the command's name
            }
        }
    }
    else
    {
        printf("\nThe type of shape is invalid.\nPlease enter again another command.\n");
        read_from_stdin(cmd); //enter again another command
    }
    free(sentence);
}

char** split_strings(char* str) { ///function to split a sentence ✅
    char delim[] = " ";
    char **sentence = (char **) malloc(50 * sizeof(char *));
    int index = 0;
    char *ptr = strtok(str, delim); ///return a pointer to the character of the next string
    sentence[index++] = ptr;
    while (ptr != NULL) {
        ptr = strtok(NULL, delim); //return NULL when whole string is split
        sentence[index++] = ptr;
    }
    /*printf("\nArray of strings :\n");
    for (int i=0; i<index; i++){
        if (sentence[i]!=NULL){
            printf("%s\n", sentence[i]);
        }
    }*/
    return sentence;
}

void delete_cmd(Command* cmd){ ///✅
    for (int i=0; i<cmd->str_size; i++)
    {
        free(cmd->str_params[i]); //free the memory of the arrays of strings
    }
    free(cmd->int_params);
    free(cmd);
}