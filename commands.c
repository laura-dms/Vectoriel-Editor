#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "area.h"

Command* create_commande(){ //create a variable of type command
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->int_size = 0;
    cmd->str_size = 0;
}

void add_str_param(Command* cmd, char* p){
    //je crois que cette fct est inutile puisqu'on aura pas de str en paramètre
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

int read_exec_command(Command* cmd){
    Area* draw_zone = create_area(10,5);
    if (strcmp(cmd, "clear")==0)
    {

    }
    else if (strcmp(cmd, "exit")==0)
    {
        //exit the program
    }
    else if (strcmp(cmd, "point")==0)
    {
        Shape* shape2 = create_point_shape(5, 5);
        add_shape_to_area(shape2, draw_zone);
        //add a point
    }
    else if (strcmp(cmd, "line")==0)
    {
        Shape* shape3 = create_point_shape(5, 5);
        add_shape_to_area(shape3, draw_zone);
        //add a line
    }
    else if (strcmp(cmd, "circle")==0)
    {
        //add a circle
    }
    else if (strcmp(cmd, "square")==0)
    {
        //add a square
    }
    else if (strcmp(cmd, "rectangle")==0)
    {
        //add a rectangle
    }
    else if (strcmp(cmd, "polygon")==0)
    {

    }
    else if (strcmp(cmd, "plot")==0)
    {

    }
    else if (strcmp(cmd, "list")==0)
    {

    }
    else if (strcmp(cmd, "delete")==0)
    {
        //free()//delete a shape (id) from the list of shapes
        //connect the node to the next node with gets_next_id()
    }
    else if (strcmp(cmd, "erase")==0)
    {
        erase_area(draw_zone);
    }
    else if (strcmp(cmd, "help")==0)
    {
        printf("The list of commands are :\n");
    }
}

void read_from_stdin(Command* cmd){
    char* str = NULL;
    int i = 0, nb_word = 1;
    printf("\n>> ");
    gets(str);
    while(str[i] != '\0'){
        if (str[i] == ' '){
            nb_word++;
        }
        if(nb_word == 1){
            cmd->name[i] = str[i];
        }
        i++;
    }
    //c'est là où on call les fct pour remplir je crois
}
