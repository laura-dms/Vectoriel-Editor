#ifndef COMMANDS_H
#define COMMANDS_H
#include "area.h"

struct command {
    char* name;
    int int_size;
    int* int_params;
    int str_size;
    char** str_params;
};
typedef struct command Command;

Command* create_command();
//void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command** cmd, Area** draw_zone);
void read_from_stdin(Command** cmd);
char** split_strings(char* str);

#endif
