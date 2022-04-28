#ifndef PRIM_H_
#define PRIM_H_
#include<iostream>
#include<vector>
using namespace std;
const int inf=1024*1024*1024;
template<int v>
class Graph
{   private:
        int edge[v][v];
        bool label[v];
        int adjvex[v];
        int cost[v];
        void ccfunc(int ver);
        vector<pair<int,int>> mst;
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
{   int x,y,z;
    mst.clear();
    for(x=0;x<v;x++)
    {   cost[x]=edge[0][x];
        adjvex[x]=0;
        label[x]=0;
    }
    label[0]=1;
    int min,adj;
    for(x=1;x<v;x++)
    {   min=inf;
        for(y=1;y<v;y++) 
        {   if(!label[y]&&cost[y]<min)
            {   adj=y;
                min=cost[y];
            }
        }
        mst.push_back(pair<int,int>(adjvex[adj],adj));
        cost[adj]=0;
        label[adj]=1;
        for(y=1;y<v;y++)
            if(!label[y]&&edge[adj][y]<cost[y])
            {   cost[y]=edge[adj][y];
                adjvex[y]=adj;
            }
    }
    return mst;
}
#endif