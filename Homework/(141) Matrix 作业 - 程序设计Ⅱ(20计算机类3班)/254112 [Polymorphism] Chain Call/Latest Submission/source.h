#include<iostream>
class Number
{   private:
        int num;
    public:
        Number(int n):num(n){}
        Number & add(int x){num+=x;return *this;}
        Number & sub(int x){num-=x;return *this;}
        void print(){std::cout<<num<<std::endl;}
};