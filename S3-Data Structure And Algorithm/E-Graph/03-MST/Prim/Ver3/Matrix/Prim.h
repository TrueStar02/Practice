#ifndef PRIM_H_
#define PRIM_H_
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
        int cost[v];
        IPQ idx_pri_q;
        vector<pair<int,int>> mst;
        void ccfunc(int ver);
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        bool isConnected(void);
        vector<pair<int,int>> MST(void);
};
template<int v>
void Graph<v>::ccfunc(int ver)
{   label[ver]=1;
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            ccfunc(x);
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
    edge[a][b]=edge[b][a]=weight;
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
bool Graph<v>::isConnected(void)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    ccfunc(0);
    for(x=0;x<v;x++)
        if(!label[x])
            return 0;
    return 1;
}
template<int v>
vector<pair<int,int>> Graph<v>::MST(void)
{   int x,y,index;
    mst.clear();
    for(x=0;x<v;x++)
    {   adjvex[x]=0;
        cost[x]=edge[0][x];
        if(edge[0][x]!=inf)
            idx_pri_q.push(edge[0][x],x);
        label[x]=0;
    }
    label[0]=1;
    while(idx_pri_q.size())
    {   idx_pri_q.pop(index);
        mst.push_back(pair<int,int>(index,adjvex[index]));
        label[index]=1;
        for(x=0;x<v;x++)
            if(!label[x]&&edge[index][x]<cost[x])
            {   cost[x]=edge[index][x];
                adjvex[x]=index;
                if(idx_pri_q.contains(x))
                    idx_pri_q.change(edge[index][x],x);
                else
                    idx_pri_q.push(edge[index][x],x);
            }
    }
    return mst;
}
#endif
