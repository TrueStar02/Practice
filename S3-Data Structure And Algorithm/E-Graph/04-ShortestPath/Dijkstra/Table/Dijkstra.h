#ifndef DIJKSTRA_H_
#define DIJKSTRA_H
#include<iostream>
#include<vector>
#include "IPQ.h"
using namespace std;
class EdgeNode
{   public:
        int adjvex;
        int weight;
        EdgeNode * next;
        EdgeNode(int adj,int w=1,EdgeNode * n=NULL):adjvex(adj),weight(w),next(n){}
};
template<int v>
class Graph
{   private:    
        EdgeNode * vertex[v];
        bool label[v];
        int adjvex[v];
        int dist[v];
        IPQ idx_pri_q;
        vector<pair<int,int>> mst;
        bool RelaxEdge(int a,int b,int w);
        void RelaxVertex(int ver);
    public:
        Graph();
        Graph(const Graph & g);
        Graph(Graph && g);
        Graph & operator=(const Graph & g);
        Graph & operator=(Graph && g);
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintList(void);
        vector<pair<int,int>> Dijkstra(int start);
};
template<int v>
bool Graph<v>::RelaxEdge(int a,int b,int w)
{   if(dist[b]>dist[a]+w)
    {   dist[b]=dist[a]+w;
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
{   EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            RelaxEdge(ver,ptr->adjvex,ptr->weight);
        ptr=ptr->next;
    }
}
template<int v>
Graph<v>::Graph()
{   int x;
    for(x=0;x<v;x++)
        vertex[x]=NULL;
}
template<int v>
Graph<v>::Graph(const Graph & g)
{   EdgeNode * ptr,* nptr;
    int x;
    for(x=0;x<v;x++)
    {   if(g.vertex[x]==NULL)
            vertex[x]=NULL;
        else
        {   vertex[x]=new EdgeNode(g.vertex[x]->adjvex,g.vertex[x]->weight,NULL);
            ptr=g.vertex[x];
            nptr=vertex[x];
            while(ptr->next!=NULL)
            {   nptr->next=new EdgeNode(ptr->next->adjvex,ptr->next->weight,NULL);
                ptr=ptr->next;
                nptr=nptr->next;
            }
        }
    }
}
template<int v>
Graph<v>::Graph(Graph && g)
{   int x;
    for(x=0;x<v;x++)
    {   vertex[x]=g.vertex[x];
        g.vertex[x]=NULL;
    }
}
template<int v>
Graph<v> & Graph<v>::operator=(const Graph & g)
{   if(this==&g)
        return *this;
    else
    {   EdgeNode * ptr,* nptr;
        int x;
        for(x=0;x<v;x++)
        {   ptr=vertex[x];
            while(ptr!=NULL)
            {   vertex[x]=vertex[x]->next;
                delete ptr;
                ptr=vertex[x];
            }
            if(g.vertex[x]==NULL)
                vertex[x]=NULL;
            else
            {   vertex[x]=new EdgeNode(g.vertex[x]->adjvex,g.vertex[x]->weight,NULL);
                ptr=g.vertex[x];
                nptr=vertex[x];
                while(ptr->next!=NULL)
                {   nptr->next=new EdgeNode(ptr->next->adjvex,ptr->next->weight,NULL);
                    ptr=ptr->next;
                    nptr=nptr->next;
                }
            }
        }
        return *this;
    }
}
template<int v>
Graph<v> & Graph<v>::operator=(Graph && g)
{   EdgeNode * ptr;
    int x;
    for(x=0;x<v;x++)
    {   ptr=vertex[x];
        while(ptr!=NULL);
        {   vertex[x]=vertex[x]->next;
            delete ptr;
            ptr=vertex[x];
        }
        vertex[x]=g.vertex[x];
        g.vertex[x]=NULL;
    }
    return *this;
}
template<int v>
Graph<v>::~Graph()
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
}
template<int v>
bool Graph<v>::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b)
        return 0;
    EdgeNode * n1=new EdgeNode(b,weight,vertex[a]);
    vertex[a]=n1;
    return 1;
}
template<int v>
void Graph<v>::PrintList(void)
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
template<int v>
vector<pair<int,int>> Graph<v>::Dijkstra(int start)
{   EdgeNode * ptr=vertex[start];
    int x,index;
    for(x=0;x<v;x++)
    {   label[x]=0;
        dist[x]=inf;
        adjvex[x]=start;
    }
    label[start]=1;
    dist[start]=0;
    adjvex[start]=-1;
    while(ptr!=NULL)
    {   dist[ptr->adjvex]=ptr->weight;
        idx_pri_q.push(ptr->weight,ptr->adjvex);
        ptr=ptr->next;
    }
    while(idx_pri_q.size())
    {   idx_pri_q.pop(index);
        label[index]=1;
        RelaxVertex(index);
    }
    mst.clear();
    for(x=0;x<v;x++)
        mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    return mst;
}
#endif