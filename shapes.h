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

typedef struct square { //square is represented by a point (corner superior left) and a length
    Point * point1;
    int length;
}Square;

//Definitions of the functions associated to the structure Square
Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

//Structure Rectangle
typedef struct rectangle { //square is represented by a point (corner superior left),a length and a width
    Point * initialpoint; //1st point
    int length; //dimensions of the rectangle
    int width;
}Rectangle;

//Definitions of the functions associated to the structure Rectangle
Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

//Structure Circle
typedef struct circle {
    Point * center;
    int radius;
}Circle;

//Definitions of the functions associated to the structure Circle
Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

//Structure Polygon
typedef struct polygon {
    int n;
    Point ** points; // dynamic 1D list of Point*
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif
