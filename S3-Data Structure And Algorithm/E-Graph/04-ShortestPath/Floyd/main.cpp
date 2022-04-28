#include<iostream>
#include<fstream>
#include<stack>
#include "Floyd.h"
using namespace std;
int main()
{   Graph<8> g;
    stack<int> st;
    ifstream fin("test.txt");
    int x,y,v,e,a,b,w;
    fin>>v>>e;
    for(x=0;x<e;x++)
    {   fin>>a>>b>>w;
        g.AddEdge(a,b,w);
    }
    g.PrintMatrix();
    g.Floyd();
    return 0;
}