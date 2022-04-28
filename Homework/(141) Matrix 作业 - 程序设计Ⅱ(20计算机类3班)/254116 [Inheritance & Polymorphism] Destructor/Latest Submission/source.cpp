#include<iostream>
using namespace std;
class A
{
public:
    A(int x){}
virtual void Prin()
    {
        cout<<"Prin come form class A"<<endl;
    }
    virtual ~A(){cout<<"A::~A()called"<<endl;}
};
class B:public A
{
char *buf;
public:
    B(int x):A(x){}
    virtual void Prin()
    {
        cout<<"Prin come from class B"<<endl;
    }
    virtual ~B(){cout<<"B::~B()called"<<endl;}
};
void fun(A *a)
{
    delete a;
}
int main()
{   A *a = new B(10);
    a->Prin();
    fun(a);
    B *b =  new B(20);
    fun(b);
    return 0;
}