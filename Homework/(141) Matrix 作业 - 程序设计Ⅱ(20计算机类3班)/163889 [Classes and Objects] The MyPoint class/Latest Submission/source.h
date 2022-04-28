#include<cmath>
class MyPoint
{
  private:
    double x, y;
  public:
    MyPoint():x(0),y(0){}
    MyPoint(double x1, double y1):x(x1),y(y1){}
    double getX() const{return x;}
    double getY() const{return y;}
    double distance(const MyPoint &point)
        {return sqrt((x-point.x)*(x-point.x)+(y-point.y)*(y-point.y));}
};