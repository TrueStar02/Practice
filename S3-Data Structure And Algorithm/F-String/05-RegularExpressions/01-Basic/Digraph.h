#ifndef DIJKSTRA_H_
#define DIJKSTRA_H
#include<iostream>
#include<vector>
using namespace std;
class EdgeNode
{   public:
        int adjvex;
        int weight;
        EdgeNode * next;
        EdgeNode(int adj,int w=1,EdgeNode * n=NULL):adjvex(adj),weight(w),next(n){}
};
class Graph
{   private:    
        int v;
        EdgeNode ** vertex;
        bool * label;
        void dfs(int ver);
    public:
        Graph(int ver);
        Graph(const Graph & g)=delete;
        Graph(Graph && g)=delete;
        Graph & operator=(const Graph & g)=delete;
        Graph & operator=(Graph && g)=delete;
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintList(void);
        bool * Reachable(int ver);
};
void Graph::dfs(int ver)
{   label[ver]=1;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=nullptr)
    {   if(!label[ptr->adjvex])
            dfs(ptr->adjvex);
        ptr=ptr->next;
    }
}
Graph::Graph(int ver):v(ver)
{   int x;
    vertex=new EdgeNode*[v];
    label=new bool[v];
    for(x=0;x<v;x++)
        vertex[x]=NULL;
}
Graph::~Graph()
{   EdgeNode * ptr;
    int x;
    for(x=0;x<v;x++)
    {   ptr=vertex[x];
        while(ptr!=NULL)
        {   vertex[x]=vertex[x]->next;
            delete ptr;
            ptr=vertex[x];
        }
    }
    delete [] vertex;
    delete [] label;
}
bool Graph::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b)
        return 0;
    EdgeNode * n1=new EdgeNode(b,weight,vertex[a]);
    vertex[a]=n1;
    return 1;
}
void Graph::PrintList(void)
{   int x;
    EdgeNode * ptr;
    for(x=0;x<v;x++)
    {   cout<<"Ver:"<<x<<" Adj:";
        ptr=vertex[x];
        while(ptr!=NULL)
        {   cout<<ptr->adjvex<<","<<ptr->weight<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
bool * Graph::Reachable(int ver)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    dfs(ver);
    return label;
}
#endif