#ifndef POINT_H
#define POINT_H

typedef struct{
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py); //Allocate
void delete_point(Point * point);
void print_point(Point * p);

#endif
