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
    else
    {
        return -1; //no existing command
    }
}
*/
void read_from_stdin(Command* cmd){
    printf("\n» Enter your command : ");
    char word[100];
    fgets(word,100, stdin);
    char sentence[30] = split_strings(word); //array of strings

    //check if the type of command is correct
    if (sentence[0]=="line" || sentence[0]=="point" || sentence[0]=="cirlce" || sentence[0]=="square" || sentence[0]=="rectangle" || sentence[0]=="polygon")
    {
        cmd->name = sentence[0]; //char name[50] and not pointer to strings
    }
    else
    {
        printf("\nThe type of shape is invalid ❌ \n Please enter again another command :");
        read_from_stdin(cmd); //enter again another command
    }

    for (int i=0; i<30; i++)
    {
        if (sizeof(sentence[i])==sizeof(int)){  //if it's an integer
            add_int_param(cmd, sentence[i]); //prends la valeur du pointer❌
        }
        else if (sizeof(sentence[i])==sizeof(char))
        {
            add_str_param(cmd, &sentence[i]);
        }
    }
}

char* split_strings(char str[]) ///function to split a sentence
{
    /*PROBLEM : strtok returns a pointer so we need a dynamic array of strings char*
    * but in the structure command, cmd->name is char name[50] ❌
     * the function works but problem of return type ✅❌*/
    int init_size = strlen(str);
    char delim[] = " ";
    char* sentence[30];
    int index = 0;
    char *ptr = strtok(str, delim); ///return a pointer to the character of the next string
    sentence[index++]=ptr;
    printf("With strtok function :\n");
    while(ptr != NULL)
    {
        printf("'%s'\n", ptr);
        ptr = strtok(NULL, delim); //return NULL when whole string is split
        sentence[index++]=ptr;
    }
    printf("\nArray of strings :\n");
    for (int i=0; i<index; i++)
    {
        if (sentence[i]!=NULL) {
            printf("%s\n", sentence[i]);
        }
    }
    return sentence;
}

/*void menu_commands()
{
    printf("\n»");
    char word[100];
    fgets(word,100, stdin);
    split_strings(word);
}*/
