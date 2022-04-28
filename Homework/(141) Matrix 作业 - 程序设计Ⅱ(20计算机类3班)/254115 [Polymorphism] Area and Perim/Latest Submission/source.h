class Shape
{   public:
        Shape(){}
        virtual double GetArea()=0;
        virtual double GetPerim()=0;
        virtual ~Shape(){}
};
class Rectangle:public Shape
{   private:
        double a;
        double b;
    public:
        Rectangle(double a0,double b0):a(a0),b(b0){}
        virtual double GetArea(){return a*b;}
        virtual double GetPerim(){return 2*a+2*b;}
};
class Circle:public Shape
{   private:
        double r;
    public:
        Circle(double r0):r(r0){}
        virtual double GetArea(){return r*r*PI;}
        virtual double GetPerim(){return 2*r*PI;}
};