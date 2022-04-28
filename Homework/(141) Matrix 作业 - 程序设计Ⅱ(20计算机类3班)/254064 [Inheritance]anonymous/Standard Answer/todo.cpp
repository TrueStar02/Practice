#include "todo.h"
using namespace std;
point::point() : x(0), y(0) {}
point::point(double x, double y) : x(x), y(y) {}
double point::getx() const {
    return x;
}
double point::gety() const {
    return y;
}
void point::print() {
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "point : " << x << " " << y << "\n";
}
 
vector1::vector1() : dx(0), dy(0) {}
vector1::vector1(double x, double y, double dx, double dy)
    : point(x, y), dx(dx), dy(dy) {}
double vector1::length() {
    return sqrt(dx * dx + dy * dy);
}
double vector1::getdx() const {
    return dx;
}
double vector1::getdy() const {
    return dy;
}
void vector1::print() {
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "length : " << length() << "\n";
    cout << "point : " << getx() << " " << gety() << "\n";
}
 
circle::circle() : r(0) {}
circle::circle(double x, double y, double r) : point(x, y), r(r) {}
double circle::area() {
    return pi * r * r;
}
double circle::getr() const {
    return r;
}
void circle::print() {
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "area : " << area() << "\n";
    cout << "point : " << getx() << " " << gety() << "\n";
}
 
todo::todo() {}
todo::todo(double x, double y, double dx, double dy, double r)
    : point(x, y) , vector1(x, y, dx, dy) , circle(x, y, r) {}
void todo::print() {
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "volume : " << area() + length() * 2 * getr() << "\n";
    cout << "length : " << length() << "\n";
    cout << "point : " << getx() << " " << gety() << "\n";
    cout << "area : " << area() << "\n";
    cout << "point : " << getx() << " " << gety() << "\n";
}
 
