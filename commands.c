#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "area.h"
#include "Structure_shape.h"

/*Command* create_commande(){ //create a variable of type command
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->int_size = 0;
    cmd->str_size = 0;
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
    else if (strcmp(cmd->name, "help")==0)
    {
        printf("The list of commands are :\n");
    }
    else
    {
        return -1; //no existing command
    }
}*/

void read_from_stdin(Command* cmd){
    printf("\n» Enter your command : ");
    char word[100];
    fgets(word,100, stdin);
    char** sentence= split_strings(word); //array of strings

    //check if the type of command is correct
    if (strcmp(sentence[0],"line")==0 || strcmp(sentence[0],"point")==0 || strcmp(sentence[0],"cirlce")==0 || strcmp(sentence[0],"square")==0 || strcmp(sentence[0],"rectangle")==0 || strcmp(sentence[0],"polygon")==0) {
        printf("\n GOOD NAME \n");
        int len=strlen(sentence[0]);
        for (int i=0; i<len; i++)
        {
            cmd->name[i]=sentence[0][i]; //add the command to the command's name
        }
    }
    else
    {
        printf("\nThe type of shape is invalid ❌ \n Please enter again another command :");
        read_from_stdin(cmd); //enter again another command
    }

    for (int i=0; i<strlen(sentence); i++) ///run through the array of strings
    {
        for (int k=0; k<strlen(sentence[i]); k++) ///run through the string to compare each character
        {
            if ((sentence[i][k])>=48 && (sentence[i][k])<=57){  //check if this is an integer with ascii code
                add_int_param(cmd, sentence[i][k]);
            }
        }
    }
    free(sentence);
}

char** split_strings(char* str){ //✅function to split a sentence
    char delim[] = " ";
    char** sentence= (char**) malloc(50*sizeof(char*));
    int index = 0;
    char *ptr = strtok(str, delim); ///return a pointer to the character of the next string
    sentence[index++]=ptr;
    while(ptr != NULL){
        ptr = strtok(NULL, delim); //return NULL when whole string is split
        sentence[index++]=ptr;
    }
    /*printf("\nArray of strings :\n");
    for (int i=0; i<index; i++){
        if (sentence[i]!=NULL){
            printf("%s\n", sentence[i]);
        }
    }*/
    return sentence;
}
