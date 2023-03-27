#ifndef POINT_H //avoid error of multiples definitions of file
#define POINT_H

//Structure Point
typedef struct{
    int pos_x;
    int pos_y;
}Point;

//Definitions of the functions associated to the structure Point
Point* create_point(int px, int py); //Allocate
void delete_point(Point * point);
void print_point(Point * p);

//Structure Line

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

//Definitions of the functions associated to the structure Line
Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

//Structure Square

typedef struct square {
    Point *p1;
    Point *p2;
}Square;

#endif
