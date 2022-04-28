#ifndef PRIM_H_
#define PRIM_H_
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf=1024*1024*1024;
struct Edge
{   int first;
    int second;
    int weight;
    Edge(int f,int s,int w):first(f),second(s),weight(w){}
    friend bool operator<(Edge a,Edge b){return a.weight>b.weight;}
};
template<int v>
class Graph
{   private:
        int edge[v][v];
        bool label[v];
        void ccfunc(int ver);
        vector<pair<int,int>> mst;
        priority_queue<Edge> pri_q;
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        bool isConnected(void);
        vector<pair<int,int>> MST(void);
        bool isValid(const Edge & e){return !(label[e.first]&label[e.second]);}
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
{   int x;
    mst.clear();
    Edge temp(0,0,0);
    for(x=0;x<v;x++)
        label[x]=0;
    label[0]=1;
    for(x=1;x<v;x++)
        if(edge[0][x]!=inf)
            pri_q.push(Edge(0,x,edge[0][x]));
    while(pri_q.size())
    {   temp=pri_q.top();
        pri_q.pop();
        if(isValid(temp))
        {   mst.push_back(pair<int,int>(temp.first,temp.second));
            if(!label[temp.first])
            {   label[temp.first]=1;
                for(x=0;x<v;x++)
                    if(!label[x]&&edge[temp.first][x]!=inf)
                        pri_q.push(Edge(temp.first,x,edge[temp.first][x]));      
            }
            else
            {   label[temp.second]=1;
                for(x=0;x<v;x++)
                    if(!label[x]&&edge[temp.second][x]!=inf)
                        pri_q.push(Edge(temp.second,x,edge[temp.second][x]));        
            }
        }       
    }  
    return mst;
}
#endif