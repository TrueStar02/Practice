#include<iostream>
#include<ctime>
#include<cstdlib>
#include "closure.h"
using namespace std;
int main()
{   srand((unsigned int)(time(0)));
    int n,x,y;
    cin>>n;
    bool **mat1=new bool*[n],**mat2=new bool*[n];
    for(x=0;x<n;x++)
    {   mat1[x]=new bool[n];
        mat2[x]=new bool[n];
    }
    for(x=0;x<n;x++)
    for(y=0;y<n;y++)
        mat1[x][y]=mat2[x][y]=rand()%2;
    clock_t beg,end;
    beg=clock();
    Walshall a(n,mat1);
    a(x);
    end=clock();
    cout<<"Time Used(Warshall):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
    beg=clock();
    DFS b(n,mat2);
    b(x);
    end=clock();
    cout<<"Time Used(DFS)     :"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
    return 0;

}