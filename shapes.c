#ifndef POINT_H //avoid error of multiples definitions of file
#define POINT_H

//Functions on Structure Point

Point *create_point(int px, int py) //Allocate dynamically a variable of type structure Point
{
    Point *point=(Point*)malloc(sizeof(int));
}
void delete_point(Point * point)
{
    free(Point*point); //Free the allocated memory the point
}
void print_point(Point * p) //Display on the screen
{
    printf("Point %d %d", );
}

#endif
