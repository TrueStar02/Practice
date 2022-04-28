#include<iostream>
using namespace std;
void addxy(int x,int y,int  total)
{   total=x+y;
    cout<<"Total from inside addxy: "<<total<<"\n";
}
void subxy(int x,int y,int & total)
{   total=x-y;
    cout<<"Total from inside subxy: "<<total<<"\n";
}