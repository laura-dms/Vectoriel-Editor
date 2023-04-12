#include <stdio.h>
#include "shapes.h"
#include "menu.h"
#include "Structure_shape.h"

int main() {
    /*Structure Point
    Point * p = create_point (10, 15);

    print_point(p);
    delete_point(p);

    //Structure Line
    Point * p1 = create_point (10, 15);
    Point * p2 = create_point (21, 25);

    Line * l = create_line (p1 ,p2);
    print_line (l);
    delete_line(l);//free the dynamic allocation of the structure line
    delete_point(p1);//free the dynamic allocation of the structure point 1
    delete_point(p2);//free the dynamic allocation of the structure point 2

    //Structure Square
    Point * pp = create_point (4, 11);

    Square * s = create_square(pp, 5); //create the square
    print_square(s); //display the coordinates of the 4th points of the square
    delete_square(s); //free the dynamic allocation of the structure square
    delete_point(pp);  //free the dynamic allocation of the structure point 3

    //Structure Rectangle
    Point * p4 = create_point (6, 13);

    Rectangle * r = create_rectangle(p4, 10, 15); //create the square
    print_rectangle(r); //display the coordinates of the 4th points of the square
    delete_rectangle(r); //free the dynamic allocation of the structure square
    delete_point(p4);  //free the dynamic allocation of the structure point 3

    //Structure Circle
    Point * pp1 = create_point(10,9);

    Circle * c = create_circle(pp1,5);
    print_circle(c);
    delete_circle(c);
    delete_point(pp1);

    //Structure Polygon ❌does not work yet
    Polygon * polygon = create_polygon(3);
    print_polygon(polygon);*/

    //menu();

    //Shape
    Shape * f1 = create_line_shape (10, 15, 21, 25);
    print_shape (f1);
    delete_shape (f1);
    
    return 0;
}
