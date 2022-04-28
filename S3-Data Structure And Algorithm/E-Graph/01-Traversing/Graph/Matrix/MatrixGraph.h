#ifndef MATRIXGRAPH_H_
#define MATRIXGRAPH_H_
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int inf=1024*1024*1024;
class Graph
{   private:
        int **edge;
        bool *label;
        int *prior;
        int *ccid;
        int *color;
        int v;
        int count;
        void dfsfunc(int ver);
        bool findpath(int cur,int src);
        void ccfunc(int ver);
        bool cyclefunc(int pri,int ver);
        bool binfunc(int pri,int ver);
    public:
        Graph(int v);
        Graph(const Graph & g);
        Graph(Graph && g);
        Graph & operator=(const Graph & g);
        Graph & operator=(Graph && g);
        ~Graph();
        bool AddEdge(int a,int b,int weight=1);
        void DFS(int start);
        void BFS(int start);
        void PrintMatrix(void);
        void HasPath(int src,int des);
        void LeastNodes(int start);
        void ConnectedComponent(void);
        bool hasCycle(void);
        bool isBinary(void);
};
void Graph::dfsfunc(int ver)
{   int x;
    label[ver]=1;
    cout<<ver<<" ";
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            dfsfunc(x);
}
bool Graph::findpath(int cur,int src)
{   int x;
    label[cur]=1;
    if(cur==src)
    {   cout<<cur<<" ";
        return 1;
    }
    for(x=0;x<v;x++)
        if(!label[x]&&edge[cur][x]!=inf)
            if(findpath(x,src))
            {   cout<<cur<<" ";
                return 1;                
            }  
    return 0; 
}
void Graph::ccfunc(int ver)
{   label[ver]=1;
    ccid[ver]=count;
    int x;
    for(x=0;x<v;x++)
        if(!label[x]&&edge[ver][x]!=inf)
            ccfunc(x);
}
bool Graph::cyclefunc(int pri,int ver)
{   int x;
    label[ver]=1;
    for(x=0;x<v;x++)
        if(x!=pri&&x!=ver&&edge[ver][x]!=inf)
            if(label[x]||!label[x]&&cyclefunc(ver,x))
                return 1;
    return 0;
}
bool Graph::binfunc(int pri,int ver)
{   int x;
    if(pri!=-1)
        color[ver]=(color[pri]+1)%2;
    label[ver]=1;
    for(x=0;x<v;x++)
        if(x!=pri&&x!=ver&&edge[ver][x]!=inf)
            if(label[x]&&color[x]==color[ver]||!label[x]&&!binfunc(ver,x))
                return 0;
    return 1;
}
Graph::Graph(int ver):v(ver)
{   int x,y;
    label=new bool[v];
    edge=new int*[v];
    prior=new int[v];
    ccid=new int[v];
    color=new int[v];
    for(x=0;x<v;x++)
        edge[x]=new int[v];
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
    {   if(x==y)
            edge[x][y]=0;
        else
            edge[x][y]=inf;
    }
}
Graph::Graph(const Graph & g):v(g.v)
{   int x,y;
    label=new bool[v];
    edge=new int*[v];
    prior=new int[v];
    ccid=new int[v];
    color=new int[v];
    for(x=0;x<v;x++)
        edge[x]=new int[v];
    for(x=0;x<v;x++)
    {   label[x]=g.label[x];
        for(y=0;y<v;y++)
            edge[x][y]=g.edge[x][y];
        prior[x]=g.prior[x];
        ccid[x]=g.ccid[x];
        color[x]=g.color[x];
    }
}
Graph::Graph(Graph && g):v(g.v)
{   label=g.label;
    edge=g.edge;
    prior=g.prior;
    ccid=g.ccid;
    color=g.color;
    g.label=NULL;
    g.edge=NULL;
    g.prior=NULL;
    g.ccid=NULL;
    g.color=NULL;
}
Graph & Graph::operator=(const Graph & g)
{   if(this==&g)
        return *this;
    int x,y;
    delete [] label;
    for(x=0;x<v;x++)
        delete [] edge[x];
    delete [] edge;
    delete [] prior;
    delete [] ccid;
    delete [] color;
    v=g.v;
    label=new bool[v];
    edge=new int*[v];
    prior=new int[v];
    ccid=new int[v];
    color=new int[v];
    for(x=0;x<v;x++)
        edge[x]=new int[v];
    for(x=0;x<v;x++)
    {   label[x]=g.label[x];
        for(y=0;y<v;y++)
            edge[x][y]=g.edge[x][y];
        prior[x]=g.prior[x];
        ccid[x]=g.ccid[x];
        color[x]=g.color[x];
    }
    return *this;
}
Graph & Graph::operator=(Graph && g)
{   int x,y;
    delete [] label;
    for(x=0;x<v;x++)
        delete [] edge[x];
    delete [] edge;
    delete [] prior;
    delete [] ccid;
    delete [] color;
    v=g.v;
    label=g.label;
    edge=g.edge;
    prior=g.prior;
    ccid=g.ccid;
    color=g.color;
    g.label=NULL;
    g.edge=NULL;
    g.prior=NULL;
    g.ccid=NULL;
    g.color=NULL;
    return *this;
}
Graph::~Graph()
{   delete [] label;
    int x;
    for(x=0;x<v;x++)
        delete [] edge[x];
    delete [] edge;
    delete [] prior;
    delete [] ccid;
    delete [] color;
}
bool Graph::AddEdge(int a,int b,int weight)
{   if(a<0||a>=v||b<0||b>=v||a==b||edge[a][b]!=inf)
        return 0;
    edge[a][b]=edge[b][a]=weight;
    return 1;
}
void Graph::DFS(int start)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Vertex:";
    dfsfunc(start);
    cout<<endl;
}
void Graph::BFS(int start)
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
void Graph::PrintMatrix(void)
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
void Graph::HasPath(int src,int des)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    cout<<"Path:";
    if(!findpath(des,src))
        cout<<"None.";
    cout<<endl;
}
void Graph::LeastNodes(int start)
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
void Graph::ConnectedComponent(void)
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
bool Graph::hasCycle(void)
{   int x;
    for(x=0;x<v;x++)
        label[x]=0;
    for(x=0;x<v;x++)
        if(!label[x]&&cyclefunc(-1,x))
            return 1;
    return 0;
}
bool Graph::isBinary(void)
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