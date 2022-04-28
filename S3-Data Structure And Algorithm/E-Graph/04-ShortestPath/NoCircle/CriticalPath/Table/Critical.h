#ifndef CRITICAL_H_
#define CRITICAL_H_
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int inf=1024*1024*256;
class EdgeNode
{   public:
        int adjvex;
        int weight;
        EdgeNode * next;
        EdgeNode(int adj,int w=1,EdgeNode * n=NULL):adjvex(adj),weight(w),next(n){}
};
class Graph
{   private:    
        EdgeNode ** vertex;
        bool *label;
        int *adjvex;
        int *dist;
        bool *onStack;
        int v;
        stack<int> rev_post_order;
        vector<int> topo_order;
        vector<pair<int,int>> mst;
        bool cyclefunc(int ver);
        void orderfunc(int ver);
        bool RelaxEdge(int a,int b,int w);
        void RelaxVertex(int ver);
    public:
        Graph(int ver);
        Graph(const Graph & g);
        Graph(Graph && g);
        Graph & operator=(const Graph & g);
        Graph & operator=(Graph && g);
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void PrintList(void);
        bool hasCycle(void);
        vector<pair<int,int>> Critical();
};
bool Graph::cyclefunc(int ver)
{   onStack[ver]=1;
    label[ver]=1;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(onStack[ptr->adjvex]||!label[ptr->adjvex]&&cyclefunc(ptr->adjvex))
            return 1;
        ptr=ptr->next;
    }
    onStack[ver]=0;
    return 0;
}
void Graph::orderfunc(int ver)
{   label[ver]=1;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            orderfunc(ptr->adjvex);
        ptr=ptr->next;
    }
    rev_post_order.push(ver);
}
bool Graph::RelaxEdge(int a,int b,int w)
{   if(dist[b]<dist[a]+w)
    {   dist[b]=dist[a]+w;
        adjvex[b]=a;
        return 1;
    }
    return 0;
}
void Graph::RelaxVertex(int ver)
{   EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   RelaxEdge(ver,ptr->adjvex,ptr->weight);
        ptr=ptr->next;
    }

}
Graph::Graph(int ver):v(ver)
{   vertex=new EdgeNode*[v];
    adjvex=new int[v];
    dist=new int[v];
    label=new bool[v];
    onStack=new bool[v];
    int x;
    for(x=0;x<v;x++)
        vertex[x]=NULL;
}
Graph::~Graph()
{   int x;
    EdgeNode * ptr,* temp;
    for(x=0;x<v;x++)
    {   ptr=temp=vertex[x];
        while(ptr!=NULL)
        {   ptr=ptr->next;
            delete temp;
            temp=ptr;
        }
    }
    delete [] vertex;
    delete [] adjvex;
    delete [] dist;
    delete [] label;
    delete [] onStack;
}
bool Graph::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b)
        return 0;
    EdgeNode * ptr=new EdgeNode(b,weight,vertex[a]);
    vertex[a]=ptr;
    return 1;
}
void Graph::PrintList(void)
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
bool Graph::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
    {   label[x]=0;
        onStack[x]=0;
    }
    for(x=0;x<v;x++)
        if(!label[x]&&cyclefunc(x))
            return 1;
    return 0;
}
vector<pair<int,int>> Graph::Critical()
{   mst.clear();
    topo_order.clear();
    int tasks=v/2-1;
    rev_post_order=stack<int>();
    int x;
    for(x=0;x<v;x++)
    {   label[x]=0;
        dist[x]=-inf;
        adjvex[x]=2*tasks;
    }
    for(x=0;x<v;x++)
        if(!label[x])
            orderfunc(x);
    if(!hasCycle())
    {   while(rev_post_order.size())
        {   topo_order.push_back(rev_post_order.top());
            rev_post_order.pop();
        }
        dist[tasks*2]=0;
        adjvex[tasks*2]=-1;
        for(x=0;x<v;x++)
            RelaxVertex(topo_order[x]);
        for(x=0;x<v;x++)
            mst.push_back(pair<int,int>(adjvex[x],dist[x]));
    }
    return mst;
}
#endif