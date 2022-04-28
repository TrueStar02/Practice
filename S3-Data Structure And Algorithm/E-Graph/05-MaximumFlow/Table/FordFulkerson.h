#ifndef FORDFULKERSON_H_
#define FORDFULKERSON_H_
#include<iostream>
#include<queue>
using namespace std;
const int inf=256*1024*1024;
class Edge
{   public:
        int a;
        int b;
        int capacity;
        int flow;
        Edge * next;
        Edge(int a0,int b0,int c,Edge * n):a{a0},b(b0),capacity(c),flow(0),next(n){}
        int other(int v){return v==a?b:a;}
};
class EdgeNode
{   public:   
        Edge * ptr;
        EdgeNode * next;
        EdgeNode(Edge * p,EdgeNode * n):ptr(p),next(n){}
};
class FlowNet
{   private:
        Edge * edges;
        EdgeNode ** vertex;
        bool * label;
        Edge ** prior;
        int ver;
        int maxium;
        int remain(Edge * ptr,int v);
        bool hasAugmentingPath(void);
        void addFlow(Edge * ptr,int v,int w);
    public:
        FlowNet(int v);
        FlowNet(const FlowNet & f)=delete;
        FlowNet(FlowNet && f)=delete;
        FlowNet & operator=(const FlowNet & f)=delete;
        FlowNet & operator=(FlowNet & f)=delete;
        ~FlowNet();
        bool AddEdge(int a,int b,int c);
        void PrintList();
        void MaxFlow(void);
};
int FlowNet::remain(Edge * ptr,int v)
{   if(ptr->a==v)
        return ptr->capacity-ptr->flow;
    else
        return ptr->flow;
}
bool FlowNet::hasAugmentingPath(void)
{   int x,y,temp,other;
    for(x=0;x<ver;x++)
    {   label[x]=0;
        prior[x]=NULL;
    }
    EdgeNode * ptr;
    queue<int> q;
    q.push(0);
    label[0]=1;
    while(q.size())
    {   temp=q.front();
        q.pop();
        ptr=vertex[temp];
        while(ptr!=NULL)
        {   other=ptr->ptr->other(temp);
            if(!label[other]&&remain(ptr->ptr,temp))
            {   q.push(other);
                prior[other]=ptr->ptr;
                label[other]=1;
            }
            ptr=ptr->next;
        }
    }
    return label[ver-1];
}
void FlowNet::addFlow(Edge * ptr,int v,int w)
{   if(v==ptr->a)
        ptr->flow+=w;
    else
        ptr->flow-=w;
}
FlowNet::FlowNet(int v):ver(v)
{   vertex=new EdgeNode*[ver];
    edges=NULL;
    label=new bool[v];
    prior=new Edge*[v];
    int x;
    for(x<0;x<v;x++)
        vertex[x]=NULL;
}
FlowNet::~FlowNet()
{   delete [] label;
    delete [] prior;
    int x;
    for(x=0;x<ver;x++)
    {   EdgeNode * ptr=vertex[x];
        while(ptr!=NULL)
        {   vertex[x]=vertex[x]->next;
            delete ptr;
            ptr=vertex[x]; 
        }
    }
    delete vertex;
}
bool FlowNet::AddEdge(int a,int b,int c)
{   if(a<0||a>=ver||b<0||b>=ver||a==b)
        return 0;
    Edge * ptr=new Edge(a,b,c,edges);
    edges=ptr;
    EdgeNode * nptr=new EdgeNode(ptr,vertex[a]);
    vertex[a]=nptr;
    nptr=new EdgeNode(ptr,vertex[b]);
    vertex[b]=nptr;
    return 1;
}
void FlowNet::PrintList()
{   int x;
    EdgeNode * ptr;
    for(x=0;x<ver;x++)
    {   ptr=vertex[x];
        cout<<"Vertex "<<x<<": ";
        while(ptr!=NULL)
        {   cout<<ptr->ptr->a<<"->"<<ptr->ptr->b<<":"<<ptr->ptr->flow<<"/"<<ptr->ptr->capacity<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
void FlowNet::MaxFlow(void)
{   int x,y,bottle,max;
    max=0;
    while(hasAugmentingPath())
    {   bottle=inf;
        for(x=ver-1;x!=0;x=prior[x]->other(x))
            if(remain(prior[x],prior[x]->other(x))<bottle)
                bottle=remain(prior[x],prior[x]->other(x));
        for(x=ver-1;x!=0;x=prior[x]->other(x))
            addFlow(prior[x],prior[x]->other(x),bottle);
        max+=bottle;
    }
    Edge * ptr=edges;
    while(ptr!=NULL)
    {   cout<<ptr->a<<"->"<<ptr->b<<":"<<ptr->flow<<"/"<<ptr->capacity<<endl;
        ptr=ptr->next;
    }
    cout<<"Maximum Flow:"<<max<<endl;
}
#endif
