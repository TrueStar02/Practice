#ifndef FLOYD_H_
#define FLOYD_H_
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int inf=256*1024*1024;
template<int v>
class Graph
{   private:
        int edge[v][v];
        int adjvex[v][v];
        int dist[v][v];
    public:
        Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintMatrix(void);
        void Floyd(void);
};
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
void Graph<v>::Floyd(void)
{   int x,y,k;
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
    {   adjvex[x][y]=x;
        dist[x][y]=edge[x][y];
    }
    for(x=0;x<v;x++)
        adjvex[x][x]=-1;
    for(k=0;k<v;k++)
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
        if(dist[x][y]>dist[x][k]+dist[k][y])
        {   adjvex[x][y]=adjvex[k][y];
            dist[x][y]=dist[x][k]+dist[k][y];
        }
    stack<int> st;
    for(k=0;k<v;k++)
    for(x=0;x<v;x++)
    {   cout<<k<<"-"<<x<<":";
        for(y=x;y!=-1;y=adjvex[k][y])
            st.push(y);
        while(st.size()!=1)
        {   cout<<st.top()<<"-";
            st.pop();
        }
        cout<<st.top()<<" Weight:"<<dist[k][x]<<endl;
        st.pop();   
    }
}
#endif
