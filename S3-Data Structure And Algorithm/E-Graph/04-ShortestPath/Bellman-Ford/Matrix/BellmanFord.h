#ifndef BELLMANFORD_H_
#define BELLMANFORD_H_
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf=1024*1024*1024;
template<int v>
class Graph
{   private:
        int edge[v][v];
        bool inQueue[v];
        int adjvex[v];
        int dist[v];
        queue<int> q;
        vector<pair<int,int>> mst;
        bool RelaxEdge(int a,int b);
        void RelaxVertex(int ver);
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        vector<pair<int,int>> BellmanFord(int start);
};
template<int v>
bool Graph<v>::RelaxEdge(int a,int b)
{   if(dist[b]>edge[a][b]+dist[a])
    {   dist[b]=edge[a][b]+dist[a];
        adjvex[b]=a;
        if(!inQueue[b])
        {   inQueue[b]=1;
            q.push(b);
        }
        return 1;
    }
    return 0;
}
template<int v>
void Graph<v>::RelaxVertex(int ver)
{   int x;
    for(x=0;x<v;x++)
        if(edge[ver][x]!=inf)
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
vector<pair<int,int>> Graph<v>::BellmanFord(int start)
{   int x,y,index;
    mst.clear();
    for(x=0;x<v;x++)
    {   dist[x]=inf;
        inQueue[x]=0;
        adjvex[x]=start; 
    }
    dist[start]=0;
    adjvex[start]=-1; 
    q.push(start); 
    inQueue[start]=1;
    while(q.size())
    {   index=q.front();
        q.pop();
        inQueue[index]=0;
        RelaxVertex(index);
    }
    for(x=0;x<v;x++)
        mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    return mst;
}
#endif
