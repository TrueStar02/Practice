#include<iostream>
#include<fstream>
#include "FordFulkerson.h"
using namespace std;
int main()
{   int x,y,v,e,a,b,c;
    ifstream fin("test.txt");
    fin>>v>>e;
    FlowNet fn(v);
    for(x=0;x<e;x++)
    {   fin>>a>>b>>c;
        fn.AddEdge(a,b,c);
    }
    fn.PrintMatrix(1);
    fn.MaxFlow();
    fn.PrintMatrix(2);
    return 0;
}