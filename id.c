//Management of unique identifiers
unsigned int global_id = 0; //unsigned int : type of data that can take 0 or positive integers as values

unsigned int get_next_id()
{
    global_id+=1;
    return global_id;
}