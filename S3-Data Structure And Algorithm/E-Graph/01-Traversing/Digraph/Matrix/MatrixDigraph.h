#ifndef MATRIXDIGRAPH_H_
#define MATRIXDIGRAPH_H_
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
using namespace std;
const int inf=1024*1024*1024;
template<int v>
class Digraph
{   private:
        int edge[v][v];
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
        bool AddEdge(int a,int b,int weight=1);
        void DFS(int start);
        void BFS(int start);
        void PrintMatrix(void);
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
{   int x;
    label[ver]=1;
    cout<<ver<<" ";
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            dfsfunc(x);
}
template<int v>
bool Digraph<v>::findpath(int cur,int src)
{   int x;
    label[cur]=1;
    if(cur==src)
    {   cout<<cur<<" ";
        return 1;
    }
    for(x=0;x<v;x++)
        if(!label[x]&&edge[x][cur]!=inf)
            if(findpath(x,src))
            {   cout<<cur<<" ";
                return 1;                
            }  
    return 0; 
}
template<int v>
void Digraph<v>::sccfunc(int ver)
{   label[ver]=1;
    id[ver]=count;
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            sccfunc(x);
}
template<int v>
bool Digraph<v>::cyclefunc(int ver)
{   int x;
    label[ver]=1;
    cur_rec.insert(ver);
    for(x=0;x<v;x++)
        if(x!=ver&&edge[ver][x]!=inf)
            if(cur_rec.find(x)!=cur_rec.end()||!label[x]&&cyclefunc(x))
                return 1;
    cur_rec.erase(ver);
    return 0;
}
template<int v>
void Digraph<v>::orderfunc(int ver)
{   label[ver]=1;
    pre_order.push(ver);
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            orderfunc(x);
    post_order.push(ver);
    rev_post_order.push(ver);
}
template<int v>
void Digraph<v>::revorderfunc(int ver)
{   label[ver]=1;
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[x][ver]!=inf)
            revorderfunc(x);
    rr_order.push(ver);
}
template<int v>
Digraph<v>::Digraph():ordered(0)
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
bool Digraph<v>::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b||edge[a][b]!=inf)
        return 0;
    edge[a][b]=weight;
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
    for(x=0;x<v;x++)
        label[x]=0;
    queue<int> q;
    q.push(start);
    label[start]=1;
    cout<<"Vertex:";
    while(q.size())
    {   for(x=0;x<v;x++)
            if(!label[x]&&edge[q.front()][x]!=inf)
            {   q.push(x);
                label[x]=1;
            }
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
template<int v>
void Digraph<v>::PrintMatrix(void)
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
    for(x=0;x<v;x++)
    {   label[x]=0;
        prior[x]=-2;
    }
    prior[start]=-1;
    queue<int> q;
    q.push(start);
    label[start]=1;
    while(q.size())
    {   for(x=0;x<v;x++)
            if(!label[x]&&edge[q.front()][x]!=inf)
            {   label[x]=1;
                prior[x]=q.front();
                q.push(x);
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
    {   int x;
        pre_order=queue<int>();
        post_order=queue<int>();
        rev_post_order=stack<int>();
        topo_order.clear();
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