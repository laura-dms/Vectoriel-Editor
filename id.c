#include "id.h"
unsigned int global_id = 0;

unsigned int get_next_id()
{
    global_id+=1;
    return global_id;
}
