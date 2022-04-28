#ifndef TABLEGRAPH_H_
#define TABLEGRAPH_H
#include<iostream>
#include<queue>
#include<stack>
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
        int prior[v];
        int ccid[v];
        int color[v];
        int count;
        void dfsfunc(int ver);
        bool findpath(int cur,int src);
        void ccfunc(int ver);
        bool cyclefunc(int pri,int ver);
        bool binfunc(int pri,int ver);
    public:
        Graph();
        Graph(const Graph & g);
        Graph(Graph && g);
        Graph & operator=(const Graph & g);
        Graph & operator=(Graph && g);
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void DFS(int start);
        void BFS(int start);
        void PrintList(void);
        void HasPath(int src,int des);
        void LeastNodes(int start);
        void ConnectedComponent(void);
        bool hasCycle(void);
        bool isBinary(void);
};
template<int v>
void Graph<v>::dfsfunc(int ver)
{   EdgeNode * ptr=vertex[ver];
    label[ver]=1;
    cout<<ver<<" ";
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            dfsfunc(ptr->adjvex);
        ptr=ptr->next;
    }
}
template<int v>
bool Graph<v>::findpath(int cur,int src)
{   EdgeNode * ptr=vertex[cur];
    label[cur]=1;
    if(cur==src)
    {   cout<<cur<<" ";
        return 1;
    }
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            if(findpath(ptr->adjvex,src))
            {   cout<<cur<<" ";
                return 1;
            }
        ptr=ptr->next;
    }
    return 0;
}
template<int v>
void Graph<v>::ccfunc(int ver)
{   label[ver]=1;
    ccid[ver]=count;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            ccfunc(ptr->adjvex);
        ptr=ptr->next;
    }
}
template<int v>
bool Graph<v>::cyclefunc(int pri,int ver)
{   EdgeNode * ptr=vertex[ver];
    label[ver]=1;
    while(ptr!=NULL)
    {   if(ptr->adjvex!=pri)
            if(label[ptr->adjvex]||cyclefunc(ver,ptr->adjvex))
                return 1;
        ptr=ptr->next;
    }
    return 0;
}
template<int v>
bool Graph<v>::binfunc(int pri,int ver)
{   EdgeNode * ptr=vertex[ver];
    label[ver]=1;
    if(pri!=-1)
        color[ver]=(color[pri]+1)%2;
    while(ptr!=NULL)
    {   if(ptr->adjvex!=pri)
            if(label[ptr->adjvex]&&color[ptr->adjvex]==color[ver]||!label[ptr->adjvex]&&!binfunc(ver,ptr->adjvex))
                return 0;
        ptr=ptr->next;
    }
    return 1;
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
void Graph<v>::DFS(int start)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Vertex:";
    dfsfunc(start);
    cout<<endl;
}
template<int v>
void Graph<v>::BFS(int start)
{   int x;
    EdgeNode * ptr;
    for(x=0;x<v;x++)
        label[x]=0;
    queue<int> q;
    q.push(start);
    label[start]=1;
    cout<<"Vertex:";
    while(q.size())
    {   ptr=vertex[q.front()];
        while(ptr!=NULL)
        {   if(!label[ptr->adjvex])
            {   q.push(ptr->adjvex);
                label[ptr->adjvex]=1;
            }
            ptr=ptr->next;
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
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
void Graph<v>::HasPath(int src,int des)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Path:";
    if(!findpath(des,src))
        cout<<"None.";
    cout<<endl;  
}
template<int v>
void Graph<v>::LeastNodes(int start)
{   int x;
    EdgeNode * ptr;
    for(x=0;x<v;x++)
    {   label[x]=0;
        prior[x]=-2;
    }
    prior[start]=-1;
    queue<int> q;
    q.push(start);
    label[start]=1;
    while(q.size())
    {   ptr=vertex[q.front()];
        while(ptr!=NULL)
        {   if(!label[ptr->adjvex])
            {   label[ptr->adjvex]=1;
                prior[ptr->adjvex]=q.front();
                q.push(ptr->adjvex);
            }
            ptr=ptr->next;
        }
        q.pop();
    }
    int index;
    stack<int> st;
    for(x=0;x<v;x++)
    {   cout<<"From "<<start<<" To "<<x<<":";
        if(prior[x]!=-2)
        {   for(index=x;index!=-1;index=prior[index])
                st.push(index);
            while(st.size())
            {   cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
        }
        else
            cout<<"None\n";
    }
}
template<int v>
void Graph<v>::ConnectedComponent(void)
{   int x,y;
    for(x=0;x<v;x++)
        label[x]=0;
    count=0;
    for(x=0;x<v;x++)
        if(!label[x])
        {   ccfunc(x);
            count++;
        }
    for(y=0;y<count;y++)
    {   cout<<"Connected Component "<<y<<":";
        for(x=0;x<v;x++)
        {   if(ccid[x]==y)
                cout<<x<<" ";
        }
        cout<<endl;
    }
}
template<int v>
bool Graph<v>::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    for(x=0;x<v;x++)
        if(!label[x]&&cyclefunc(-1,x))
            return 1;
    return 0;
}
template<int v>
bool Graph<v>::isBinary(void)
{   int x;
    for(x=0;x<v;x++)
    {   label[x]=0;
        color[x]=-1;
    }
    for(x=0;x<v;x++)
        if(!label[x])
        {   color[x]=0;
            if(!binfunc(-1,x))
                return 0;
        }
    return 1;
}
#endif