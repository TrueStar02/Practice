#include<iostream>
#include<cmath>
const double PI=acos(-1);
class Land
{   private:
        double price;
    protected:
        double getpri(){return price;}
    public:
        Land(double p):price(p){}
        virtual double total()=0;
};
class Circle:public Land
{   private:
        double r;
    public:
        Circle(double r0,double p):r(r0),Land(p){}
        virtual double total(){return r*r*getpri()*PI;}
};
class Square:public Land
{   private:
        double r;
    public:
        Square(double r0,double p):r(r0),Land(p){}
        virtual double total(){return r*r*getpri();}
};
class Accountant
{   private:
        double tot;
    public:
        Accountant(){tot=0;}
        void DevelopEstate(Land * l){tot+=l->total();}
        double CheckMoney(){return tot;}
};