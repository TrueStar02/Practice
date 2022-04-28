#include<iostream>
#include<fstream>
#include "Strassen.h"
using namespace std;
int main()
{   ifstream fin("test.in");
    ofstream fout("test.out");
    int x,y,n;
    fin>>n;
    int ** a=createMatrix(n),** b=createMatrix(n);
    for(x=0;x<n;x++)
    for(y=0;y<n;y++)
        fin>>a[x][y];
    for(x=0;x<n;x++)
    for(y=0;y<n;y++)
        fin>>b[x][y];
    double start=double(clock())/CLOCKS_PER_SEC;
    int ** c=Strassen(a,b,n);
    double end=double(clock())/CLOCKS_PER_SEC;
    cout<<"Time:"<<end-start<<"s\n";
    for(x=0;x<n;x++)
    {   for(y=0;y<n;y++)
            fout<<c[x][y]<<" ";
        fout<<endl;
    }
    freeMatrix(a,n);
    freeMatrix(b,n);
    freeMatrix(c,n);
    return 0;
}