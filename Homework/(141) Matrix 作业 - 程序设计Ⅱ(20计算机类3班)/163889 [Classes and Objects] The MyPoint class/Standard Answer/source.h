// Problem#: 17658
// Submission#: 4657223
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <math.h> 

class MyPoint
{
  private:
    double x, y;
  public:
    MyPoint() {
        x = 0;
        y = 0;
    }
    MyPoint(double a, double b) {
        x = a;
        y = b;
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double distance(const MyPoint &point) {
        return sqrt((x-point.x)*(x-point.x) + (y-point.y)*(y-point.y));
    }
};                                 
