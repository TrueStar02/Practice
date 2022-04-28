#include<iostream>
#include "f.hpp"
#include "f3.hpp"
using namespace std;

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