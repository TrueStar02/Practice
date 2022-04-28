#include<iostream>
#include<fstream>
#include "MatrixGraph.h"
using namespace std;
int main()
{   ifstream fin("test.txt");
    int vertex,edge,x,a,b;
    fin>>vertex>>edge;
    Graph g(10);
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g.AddEdge(a,b);
    }
    g.PrintMatrix();
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
    Graph g1(13);
    for(x=0;x<edge;x++)
    {   fin>>a>>b;
        g1.AddEdge(a,b);
    }
    g1.PrintMatrix();
    g1.ConnectedComponent();
    cout<<g1.hasCycle()<<endl;
    cout<<g1.isBinary()<<endl;
    Graph g2(4);
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