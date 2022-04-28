#ifndef PRIM_H_
#define PRIM_H
#include<iostream>
#include<vector>
using namespace std;
const int inf=1024*1024*1024;
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
        int cost[v];
        void ccfunc(int ver);
        vector<pair<int,int>> mst;
    public:
        Graph();
        Graph(const Graph & g);
        Graph(Graph && g);
        Graph & operator=(const Graph & g);
        Graph & operator=(Graph && g);
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintList(void);
        bool isConnected(void);
        vector<pair<int,int>> MST(void);
};
template<int v>
void Graph<v>::ccfunc(int ver)
{   label[ver]=1;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            ccfunc(ptr->adjvex);
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
    EdgeNode * n2=new EdgeNode(a,weight,vertex[b]);
    vertex[b]=n2;
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
bool Graph<v>::isConnected(void)
{   int x,y;
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
{   int x,y;
    EdgeNode * ptr=vertex[0];
    mst.clear();
    for(x=0;x<v;x++)
    {   label[x]=0;
        cost[x]=inf;
        adjvex[x]=0;
    }
    label[0]=1;
    while(ptr!=NULL)
    {   cost[ptr->adjvex]=ptr->weight;
        ptr=ptr->next;
    }
    int adj,min;
    for(x=1;x<v;x++)
    {   min=inf;
        for(y=1;y<v;y++)
            if(!label[y]&&cost[y]<min)
            {   min=cost[y];
                adj=y;
            }
        cost[adj]=0;
        label[adj]=1;
        mst.push_back(pair<int,int>(adjvex[adj],adj));
        ptr=vertex[adj];
        while(ptr!=NULL)
        {   if(!label[ptr->adjvex]&&ptr->weight<cost[ptr->adjvex])
            {   cost[ptr->adjvex]=ptr->weight;
                adjvex[ptr->adjvex]=adj;
            }
            ptr=ptr->next;
        }
    }
    return mst;
}
#endif