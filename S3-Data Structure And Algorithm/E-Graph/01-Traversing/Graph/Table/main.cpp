#include<iostream>
#include<fstream>
#include "TableGraph.h"
using namespace std;
int main()
{   ifstream fin("test.txt");
    int vertex,edge,x,a,b;
    fin>>vertex>>edge;
    Graph<10> g0,g;
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g0.AddEdge(a,b);
    }
    g=g0;
    g0.PrintList();
    g.PrintList();
    for(x=0;x<9;x++)
    {   cout<<"Start:"<<x<<" ";
        g.DFS(x);
    }
    for(x=0;x<9;x++)
    {   cout<<"Start:"<<x<<" ";
        g.BFS(x);
    }
    g.HasPath(0,3);
    g.HasPath(1,4);
    g.HasPath(3,9);
    for(x=0;x<10;x++)
        g.LeastNodes(x);
    fin>>vertex>>edge;
    Graph<13> g1;
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g1.AddEdge(a,b);
    }
    g1.PrintList();
    g1.ConnectedComponent();   
    cout<<g1.hasCycle()<<endl;
    cout<<g1.isBinary()<<endl;
    Graph<4> g2;
    g2.AddEdge(0,1);
    g2.AddEdge(1,2);
    g2.AddEdge(2,3);
    cout<<g2.hasCycle()<<endl;
    cout<<g2.isBinary()<<endl;
    g2.AddEdge(0,3);
    cout<<g2.hasCycle()<<endl;
    cout<<g2.isBinary()<<endl;
    return 0;
}