#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include<iostream>
#include<vector>
#include "IPQ.h"
using namespace std;
template<int v>
class Graph
{   private:
        int edge[v][v];
        bool label[v];
        int adjvex[v];
        int dist[v];
        IPQ idx_pri_q;
        vector<pair<int,int>> mst;
        bool RelaxEdge(int a,int b);
        void RelaxVertex(int ver);
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        vector<pair<int,int>> Dijkstra(int start);
};
template<int v>
bool Graph<v>::RelaxEdge(int a,int b)
{   if(dist[b]>edge[a][b]+dist[a])
    {   dist[b]=edge[a][b]+dist[a];
        adjvex[b]=a;
        if(idx_pri_q.contains(b))
            idx_pri_q.change(dist[b],b);
        else
            idx_pri_q.push(dist[b],b);
        return 1;
    }
    return 0;
}
template<int v>
void Graph<v>::RelaxVertex(int ver)
{   int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
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
vector<pair<int,int>> Graph<v>::Dijkstra(int start)
{   int x,y,index;
    mst.clear();
    for(x=0;x<v;x++)
    {   dist[x]=edge[start][x];
        label[x]=0;
        adjvex[x]=start;   
        if(x!=start&&edge[start][x]!=inf)
            idx_pri_q.push(edge[start][x],x);
    }
    label[start]=1;
    adjvex[start]=-1;       
    while(idx_pri_q.size())
    {   idx_pri_q.pop(index);
        label[index]=1;
        RelaxVertex(index);
    }
    for(x=0;x<v;x++)
        mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    return mst;
}
#endif
