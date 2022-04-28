#ifndef KRUSKAL_H_
#define KRUSKAL_H_
#include<iostream>
#include<vector>
#include<queue>
#include "unionfind.h"
using namespace std;
const int inf=1024*1024*1024;
struct Edge
{   int a;
    int b;
    int weight;
    Edge(int x,int y,int w=1):a(x),b(y),weight(w){}
    friend bool operator<(const Edge & a,const Edge & b){return a.weight>b.weight;}
};
template<int v>
class Graph
{   private:
        vector<Edge> edges;
        priority_queue<Edge> pri_q;
        UnionFind * uf;
        vector<pair<int,int>> mst;
    public:
        Graph(){uf=new UnionFind(v);}
        ~Graph(){delete uf;}
        bool AddEdge(int a,int b,int weight=1);
        void PrintList(void);
        vector<pair<int,int>> MST(void);
};
template<int v>
bool Graph<v>::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b)
        return 0;
    edges.push_back(Edge(a,b,weight));
    return 1;
}
template<int v>
void Graph<v>::PrintList(void)
{   int x;
    for(x=0;x<edges.size();x++)  
        cout<<edges[x].a<<" "<<edges[x].b<<" "<<edges[x].weight<<endl;
}
template<int v>
vector<pair<int,int>> Graph<v>::MST(void)
{   int x;
    Edge temp(0,0,0);
    mst.clear();
    for(x=0;x<edges.size();x++)
        pri_q.push(edges[x]);
    int count=0;
    while(pri_q.size())
    {   temp=pri_q.top();
        pri_q.pop();
        if(!uf->isConnected(temp.a,temp.b)) 
        {   uf->Union(temp.a,temp.b);
            mst.push_back(pair<int,int>(temp.a,temp.b));
            count++;
        }
    }
    if(count!=v-1)
        return vector<pair<int,int>>();
    else
        return mst;    
}
#endif