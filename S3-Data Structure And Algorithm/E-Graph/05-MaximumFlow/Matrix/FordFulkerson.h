#ifndef FORDFULKERSON_H_
#define FORDFULKERSON_H_
#include<iostream>
#include<queue>
using namespace std;
const int inf=256*1024*1024;
class FlowNet
{   private:
        int ** capacity;
        int ** flow;
        bool * label;
        int * prior;
        int ver;
        int maxium;
        int remain(int a,int b);
        bool hasAugmentingPath(void);
        void addFlow(int a,int b,int w);
    public:
        FlowNet(int v);
        FlowNet(const FlowNet & f)=delete;
        FlowNet(FlowNet && f)=delete;
        FlowNet & operator=(const FlowNet & f)=delete;
        FlowNet & operator=(FlowNet & f)=delete;
        ~FlowNet();
        bool AddEdge(int a,int b,int c);
        void PrintMatrix(int model=0);
        void MaxFlow(void);
};
int FlowNet::remain(int a,int b)
{   if(capacity[a][b]>flow[a][b])
        return capacity[a][b]-flow[a][b];
    else if(flow[b][a]>0)
        return flow[b][a];
    else
        return 0;
}
bool FlowNet::hasAugmentingPath(void)
{   int x,y,temp;
    queue<int> q;
    for(x=0;x<ver;x++)
    {   label[x]=0;
        prior[x]=-1;
    }
    q.push(0);
    label[0]=1;
    while(!q.empty())
    {   temp=q.front();
        q.pop();
        for(x=0;x<ver;x++)
            if(!label[x]&&remain(temp,x))
            {   q.push(x);
                label[x]=1;
                prior[x]=temp;
            }
    }
    return label[ver-1];
}
void FlowNet::addFlow(int a,int b,int w)
{   if(capacity[a][b]>0)
        flow[a][b]+=w;
    else
        flow[b][a]-=w;

}
FlowNet::FlowNet(int v):ver(v)
{   int x,y;
    capacity=new int*[ver];
    flow=new int*[ver];
    for(x=0;x<ver;x++)
    {   capacity[x]=new int[v];
        flow[x]=new int[v];
        for(y=0;y<v;y++)
        {   capacity[x][y]=0;
            flow[x][y]=0;
        }
    }
}
FlowNet::~FlowNet()
{   int x;
    for(x=0;x<ver;x++)
    {   delete [] flow[x];
        delete [] capacity[x];
    }
    delete [] label;
    delete [] prior;
    delete [] flow;
    delete [] capacity;
}
bool FlowNet::AddEdge(int a,int b,int c)
{   if(a<0||a>=ver||b<0||b>=ver||a==b)
        return 0;
    capacity[a][b]=c;
    return 1;
}
void FlowNet::PrintMatrix(int model)
{   int x,y;
    if(model==0||model==1)
        for(x=0;x<ver;x++)
        {   for(y=0;y<ver;y++)
                cout<<capacity[x][y]<<" ";
            cout<<endl;
        }
    if(model==0||model==2)
        for(x=0;x<ver;x++)
        {   for(y=0;y<ver;y++)
                cout<<flow[x][y]<<" ";
            cout<<endl;
        }
}
void FlowNet::MaxFlow(void)
{   maxium=0;
    int bottle,x,y;
    while(hasAugmentingPath())
    {   bottle=inf;
        for(x=ver-1;x!=0;x=prior[x])
            if(bottle>remain(prior[x],x))
                bottle=remain(prior[x],x);
        for(x=ver-1;x!=0;x=prior[x])
            addFlow(prior[x],x,bottle);
        maxium+=bottle;
    }
    for(x=0;x<ver;x++)
    for(y=0;y<ver;y++)
        if(capacity[x][y])
            cout<<x<<"->"<<y<<":"<<flow[x][y]<<"/"<<capacity[x][y]<<endl;
    cout<<"Maximum Flow:"<<maxium<<endl;
}
#endif