#include<iostream>
#include<fstream>
#include "MatrixDigraph.h"
using namespace std;
int main()
{   ifstream fin("test.txt");
    int vertex,edge,x,a,b;
    fin>>vertex>>edge;
    Digraph<13> g;
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g.AddEdge(a,b);
    }
    g.PrintMatrix();
    for(x=0;x<13;x++)
    {   cout<<"Start:"<<x<<" ";
        g.DFS(x);
    }
     for(x=0;x<13;x++)
    {   cout<<"Start:"<<x<<" ";
        g.BFS(x);
    }
    g.HasPath(0,2);
    g.HasPath(1,4);
    g.HasPath(8,1);
    for(x=0;x<13;x++)
        g.LeastNodes(x); 
    cout<<g.hasCycle()<<endl;
    cout<<g.Topological().size()<<endl;
    g.StrongConnectedComponent();
    Digraph<13> g1;
    fin>>vertex>>edge;
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g1.AddEdge(a,b);
    }
    g1.PrintMatrix();
    cout<<g1.hasCycle()<<endl;
    vector<int> topo1=g1.Topological();
    for(x=0;x<topo1.size();x++)
        cout<<topo1[x]<<" ";
    cout<<endl;
    return 0;
}