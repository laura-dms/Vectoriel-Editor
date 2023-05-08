#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Command* create_commande(){
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->int_size = 0;
    cmd->str_size = 0;
}

void add_str_param(Command* cmd, char* p){
    //je crois que cette fct est inutile puisqu'on aura pas de str en paramètre
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
    //je sens que ça va être chiant
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