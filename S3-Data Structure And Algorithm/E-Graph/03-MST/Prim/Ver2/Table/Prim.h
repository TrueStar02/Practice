#ifndef PRIM_H_
#define PRIM_H
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
        void ccfunc(int ver);
        vector<pair<int,int>> mst;
        priority_queue<Edge> pri_q;
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
        bool isValid(const Edge & e){return !(label[e.first]&label[e.second]);}
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
{   int x;
    mst.clear();
    Edge temp(0,0,0);
    for(x=1;x<v;x++)
        label[x]=0;
    label[0]=1;
    EdgeNode * ptr=vertex[0];
    while(ptr!=NULL)
    {   pri_q.push(Edge(0,ptr->adjvex,ptr->weight));
        ptr=ptr->next;
    }
    while(pri_q.size())
    {   temp=pri_q.top();
        pri_q.pop();
        if(isValid(temp))
        {   mst.push_back(pair<int,int>(temp.first,temp.second));
            if(!label[temp.first])
            {   label[temp.first]=1;
                ptr=vertex[temp.first];
                while(ptr!=NULL)
                {   if(!label[ptr->adjvex])
                        pri_q.push(Edge(temp.first,ptr->adjvex,ptr->weight));
                    ptr=ptr->next;
                }
            }
            else
            {   label[temp.second]=1;
                ptr=vertex[temp.second];
                while(ptr!=NULL)
                {   if(!label[ptr->adjvex])
                        pri_q.push(Edge(temp.second,ptr->adjvex,ptr->weight));
                    ptr=ptr->next;
                }                
            }
        }
    }
    return mst;
}
#endif