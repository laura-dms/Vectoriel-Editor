#include <stdio.h>
#include "shapes.h"

int main() {
    //Structure Point
    Point * p = create_point (10, 15);
    print_point(p);
    delete_point(p);

    //Structure Line
    Point * p1 = create_point (10, 15);
    Point * p2 = create_point (21, 25);
    Line * l = create_line (p1 ,p2);
    print_line (l);
    delete_line(l);
    delete_point(p1);
    delete_point(p2);
    return 0;
}
