#include<iostream>
using namespace std;
void f1(int);
void f2(int);
void f3(int);
void f1(int x)
{   try
    {
        f2(x);
    }
    catch(int y)
    {
        cout<<"An int exception occurred!--from f1\n";
    }
    catch(float y)
    {
        cout<<"A float exception occurred!--from f1\n";
    }
    catch(double y)
    {
        cout<<"A double exception occurred!--from f1\n";
    }
    cout<<"End of f1\n";
}
void f2(int x)
{   try
    {
        f3(x);
    }
    catch(int y)
    {
        cout<<"An int exception occurred!--from f2\n";
        
    }
    catch(float y)
    {
        cout<<"A float exception occurred!--from f2\n";
        
    }
    cout<<"End of f2\n";
}


void f3(int x)                        //EX9_2.cpp
{
    switch (x)
    {
    case 1:
        throw 3.4;        // 抛出double型异常
    case 2:
        throw 2.5f;           // 抛出float型异常
    case 3:
        throw 1;          // 抛出int型异常
    }
    cout << "End of f3" << endl;
}