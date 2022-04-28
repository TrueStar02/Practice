#include<cmath>
#include<iostream>
using namespace std;
const double PI=acos(-1.0);
class point
{   private:
        double x;
        double y;
    protected:
        virtual void Data();
    public:
        point(double x0=0,double y0=0):x(x0),y(y0)
        {   cout.setf(ios_base::fixed,ios_base::floatfield);
            cout.precision(2);
        }
        virtual ~point(){}
        virtual void print();
};
class vector1:virtual public point
{   private:
        double dx;
        double dy;
    protected:
        virtual void Data();
        double length(){return sqrt(dx*dx+dy*dy);}
    public:
        vector1(double x0=0,double y0=0,double dx0=0,double dy0=0):point(x0,y0),dx(dx0),dy(dy0){}
        virtual void print();
};
class circle:virtual public point
{   private:
        double r;
    protected:
        virtual void Data();
        double area(){return PI*r*r;}
        double getr(){return r;}
    public:
        circle(double x0=0,double y0=0,double r0=0):point(x0,y0),r(r0){}
        virtual void print();
};
class todo:public circle,public vector1
{    protected:
        virtual void Data();
    public:
        todo(double x0=0,double y0=0,double dx0=0,double dy0=0,double r0=0):point(x0,y0),circle(x0,y0,r0),vector1(x0,y0,dx0,dy0){}
        virtual void print();
};