#ifndef ACYCLIC_H_
#define ACYCLIC_H_
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int inf=1024*1024*256;
template<int v>
class Graph
{   private:
        int edge[v][v];
        int adjvex[v];
        int dist[v];
        bool label[v];
        bool onStack[v];
        stack<int> rev_post_order;
        vector<int> topo_order;
        vector<pair<int,int>> mst;
        bool cyclefunc(int ver);
        void orderfunc(int ver);
        bool RelaxEdge(int a,int b);
        void RelaxVertex(int ver);
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        bool hasCycle(void);
        vector<pair<int,int>> Acyclic(int start);
};
template<int v>
bool Graph<v>::cyclefunc(int ver)
{   onStack[ver]=1;
    label[ver]=1;
    int x;
    for(x=0;x<v;x++)
        if(x!=ver&&edge[ver][x]!=inf)
            if(onStack[x]||!label[x]&&cyclefunc(x))
                return 1;
    onStack[ver]=0;
    return 0;
}
template<int v>
void Graph<v>::orderfunc(int ver)
{   int x;
    label[ver]=1;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            orderfunc(x);
    rev_post_order.push(ver);
}
template<int v>
bool Graph<v>::RelaxEdge(int a,int b)
{   if(dist[b]>edge[a][b]+dist[a])
    {   dist[b]=edge[a][b]+dist[a];
        adjvex[b]=a;
        return 1;
    }
    return 0;
}
template<int v>
void Graph<v>::RelaxVertex(int ver)
{   int x;
    for(x=0;x<v;x++)
        if(ver!=x&&edge[ver][x]!=inf)
            RelaxEdge(ver,x);
}
template<int v>
Graph<v>::Graph()
{   int x,y;
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
    {   if(x==y)
            edge[x][y]=0;
        else
            edge[x][y]=inf;
    }
}
template<int v>
bool Graph<v>::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b||edge[a][b]!=inf)
        return 0;
    edge[a][b]=weight;
    return 1;
}
template<int v>
void Graph<v>::PrintMatrix(void)
{   int x,y;
    for(x=0;x<v;x++)
    {   for(y=0;y<v;y++)
        {   if(edge[x][y]==inf)
                cout<<"X ";
            else
                cout<<edge[x][y]<<" ";
        }
        cout<<endl;
    }
}
template<int v>
bool Graph<v>::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
    {   label[x]=0;
        onStack[x]=0;
    }
    for(x=0;x<v;x++)
        if(!label[x]&&cyclefunc(x))
            return 1;
    return 0;
}
template<int v>
vector<pair<int,int>> Graph<v>::Acyclic(int start)
{   int x;
    rev_post_order=stack<int>();
    topo_order.clear();
    mst.clear();
    for(x=0;x<v;x++)
    {   label[x]=0;
        dist[x]=inf;
        adjvex[x]=start;
    }
    for(x=0;x<v;x++)
            if(!label[x])
                orderfunc(x);
    if(!hasCycle())
    {   while(rev_post_order.size())
        {   topo_order.push_back(rev_post_order.top());
            rev_post_order.pop();
        }
        dist[start]=0;
        adjvex[start]=-1;
        for(x=0;x<v;x++)
            if(topo_order[x]==start)
                break;
        for(;x<v;x++)
            RelaxVertex(topo_order[x]);
        for(x=0;x<v;x++)
            mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    }
    return mst;
}
#endif
