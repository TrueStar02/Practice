#ifndef TABLEDIGRAPH_H_
#define TABLEDIGRAPH_H
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
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
class Digraph
{   private:    
        EdgeNode * vertex[v];
        EdgeNode * rev_vertex[v];
        bool label[v];
        int prior[v];
        int id[v];
        int count;
        bool ordered;
        queue<int> pre_order;
        queue<int> post_order;
        stack<int> rev_post_order;
        stack<int> rr_order;
        vector<int> topo_order;
        set<int> cur_rec;
        void dfsfunc(int ver);
        bool findpath(int cur,int src);
        void sccfunc(int ver);
        bool cyclefunc(int ver);
        void orderfunc(int ver);
        void revorderfunc(int ver);
    public:
        Digraph();
        Digraph(const Digraph & g);
        Digraph(Digraph && g);
        Digraph & operator=(const Digraph & g);
        Digraph & operator=(Digraph && g);
        ~Digraph();
        bool AddEdge(int a,int b,int weight=1);
        void DFS(int start);
        void BFS(int start);
        void PrintList(void);
        void PrintRevList(void);
        void HasPath(int src,int des);
        void LeastNodes(int start);
        void StrongConnectedComponent(void);
        bool hasCycle(void);
        void Order(void);
        queue<int> Pre(void);
        queue<int> Post(void);
        stack<int> ReversePost(void);
        vector<int> Topological(void);
};
template<int v>
void Digraph<v>::dfsfunc(int ver)
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
bool Digraph<v>::findpath(int cur,int src)
{   EdgeNode * ptr=rev_vertex[cur];
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
void Digraph<v>::sccfunc(int ver)
{   label[ver]=1;
    id[ver]=count;
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            sccfunc(ptr->adjvex);
        ptr=ptr->next;
    }
}
template<int v>
bool Digraph<v>::cyclefunc(int ver)
{   EdgeNode * ptr=vertex[ver];
    label[ver]=1;
    cur_rec.insert(ver);
    while(ptr!=NULL)
    {   if(cur_rec.find(ptr->adjvex)!=cur_rec.end()||!label[ptr->adjvex]&&cyclefunc(ptr->adjvex))
            return 1;
        ptr=ptr->next;
    }
    cur_rec.erase(ver);
    return 0;
}
template<int v>
void Digraph<v>::orderfunc(int ver)
{   label[ver]=1;
    pre_order.push(ver);
    EdgeNode * ptr=vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            orderfunc(ptr->adjvex);
        ptr=ptr->next;
    }
    post_order.push(ver);
    rev_post_order.push(ver);
}
template<int v>
void Digraph<v>::revorderfunc(int ver)
{   label[ver]=1;
    EdgeNode * ptr=rev_vertex[ver];
    while(ptr!=NULL)
    {   if(!label[ptr->adjvex])
            revorderfunc(ptr->adjvex);
        ptr=ptr->next;
    }
    rr_order.push(ver);
}
template<int v>
Digraph<v>::Digraph():ordered(0)
{   int x;
    for(x=0;x<v;x++)
    {   vertex[x]=NULL;
        rev_vertex[x]=NULL;
    }
}
template<int v>
Digraph<v>::Digraph(const Digraph & g):ordered(g.ordered),pre_order(g.pre_order),post_order(g.post_order),rev_post_order(g.rev_post_order),topo_order(g.topo_order)
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
    for(x=0;x<v;x++)
    {   if(g.rev_vertex[x]==NULL)
            rev_vertex[x]=NULL;
        else
        {   rev_vertex[x]=new EdgeNode(g.rev_vertex[x]->adjvex,g.rev_vertex[x]->weight,NULL);
            ptr=g.rev_vertex[x];
            nptr=rev_vertex[x];
            while(ptr->next!=NULL)
            {   nptr->next=new EdgeNode(ptr->next->adjvex,ptr->next->weight,NULL);
                ptr=ptr->next;
                nptr=nptr->next;
            }
        }
    }
}
template<int v>
Digraph<v>::Digraph(Digraph && g):ordered(g.ordered),pre_order(g.pre_order),post_order(g.post_order),rev_post_order(g.rev_post_order),topo_order(g.topo_order)
{   int x;
    for(x=0;x<v;x++)
    {   vertex[x]=g.vertex[x];
        g.vertex[x]=NULL;
        rev_vertex[x]=g.rev_vertex[x];
        g.rev_vertex[x]=NULL;
    }
}
template<int v>
Digraph<v> & Digraph<v>::operator=(const Digraph & g)
{   if(this==&g)
        return *this;
    else
    {   ordered=g.ordered;
        pre_order=g.pre_order;
        post_order=g.post_order;
        rev_post_order=g.rev_post_order;
        topo_order=g.topo_order;
        EdgeNode * ptr,* nptr;
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
        for(x=0;x<v;x++)
        {   ptr=rev_vertex[x];
            while(ptr!=NULL)
            {   rev_vertex[x]=rev_vertex[x]->next;
                delete ptr;
                ptr=rev_vertex[x];
            }
            if(g.rev_vertex[x]==NULL)
                rev_vertex[x]=NULL;
            else
            {   rev_vertex[x]=new EdgeNode(g.rev_vertex[x]->adjvex,g.rev_vertex[x]->weight,NULL);
                ptr=g.rev_vertex[x];
                nptr=rev_vertex[x];
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
Digraph<v> & Digraph<v>::operator=(Digraph && g)
{   EdgeNode * ptr;
    int x;
    ordered=g.ordered;
    pre_order=g.pre_order;
    post_order=g.post_order;
    rev_post_order=g.rev_post_order;
    topo_order=g.topo_order;
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
    for(x=0;x<v;x++)
    {   ptr=rev_vertex[x];
        while(ptr!=NULL);
        {   rev_vertex[x]=rev_vertex[x]->next;
            delete ptr;
            ptr=rev_vertex[x];
        }
        rev_vertex[x]=g.rev_vertex[x];
        g.rev_vertex[x]=NULL;
    }
    return *this;
}
template<int v>
Digraph<v>::~Digraph()
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
    for(x=0;x<v;x++)
    {   ptr=rev_vertex[x];
        while(ptr!=NULL)
        {   rev_vertex[x]=rev_vertex[x]->next;
            delete ptr;
            ptr=rev_vertex[x];
        }
    }
}
template<int v>
bool Digraph<v>::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b)
        return 0;
    EdgeNode * n1=new EdgeNode(b,weight,vertex[a]);
    vertex[a]=n1;
    EdgeNode * n2=new EdgeNode(a,weight,rev_vertex[b]);
    rev_vertex[b]=n2;
    ordered=0;
    return 1;
}
template<int v>
void Digraph<v>::DFS(int start)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Vertex:";
    dfsfunc(start);
    cout<<endl;
}
template<int v>
void Digraph<v>::BFS(int start)
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
void Digraph<v>::PrintList(void)
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
void Digraph<v>::PrintRevList(void)
{   int x;
    EdgeNode * ptr;
    for(x=0;x<v;x++)
    {   cout<<"Ver:"<<x<<" Adj:";
        ptr=rev_vertex[x];
        while(ptr!=NULL)
        {   cout<<ptr->adjvex<<","<<ptr->weight<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
template<int v>
void Digraph<v>::HasPath(int src,int des)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Path:";
    if(!findpath(des,src))
        cout<<"None.";
    cout<<endl;  
}
template<int v>
void Digraph<v>::LeastNodes(int start)
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
void Digraph<v>::StrongConnectedComponent(void)
{   int x,y;
    for(x=0;x<v;x++)
        label[x]=0;
    rr_order=stack<int>();
    for(x=0;x<v;x++)
        if(!label[x])
            revorderfunc(x);
    for(x=0;x<v;x++)
        label[x]=0;
    count=0;
    while(rr_order.size())
    {   if(!label[rr_order.top()])    
        {   sccfunc(rr_order.top());
            count++;
        }
        rr_order.pop();
    }
    for(y=0;y<count;y++)
    {   cout<<"Strong Connected Component "<<y<<":";
        for(x=0;x<v;x++)
        {   if(id[x]==y)
                cout<<x<<" ";
        }
        cout<<endl;
    }
}
template<int v>
bool Digraph<v>::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    for(x=0;x<v;x++)
        if(!label[x])
        {   cur_rec.clear();
            if(cyclefunc(x)) 
                return 1;
        }
    return 0;
}
template<int v>
void Digraph<v>::Order(void)
{   if(!ordered)   
    {   pre_order=queue<int>();
        post_order=queue<int>();
        rev_post_order=stack<int>();
        topo_order.clear();
        int x;
        for(x=0;x<v;x++)
            label[x]=0;
        for(x=0;x<v;x++)
            if(!label[x])
                orderfunc(x);
        ordered=1;
        if(!hasCycle())
        {   stack<int> temp=ReversePost();
            while(temp.size())
            {   topo_order.push_back(temp.top());
                temp.pop();
            }        
        }
    }
}
template<int v>
queue<int> Digraph<v>::Pre(void)
{   if(!ordered)
        Order();
    return pre_order;
}
template<int v>
queue<int> Digraph<v>::Post(void)
{   if(!ordered)
        Order();
    return post_order;
}
template<int v>
stack<int> Digraph<v>::ReversePost(void)
{   if(!ordered)
        Order();
    return rev_post_order;
}
template<int v>
vector<int> Digraph<v>::Topological(void)
{   if(!ordered)
        Order();
    return topo_order;
}
#endif