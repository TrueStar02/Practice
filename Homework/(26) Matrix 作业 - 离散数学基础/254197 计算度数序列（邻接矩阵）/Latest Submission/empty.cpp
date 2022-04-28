#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=1024*1024*1024;
struct AMGraph
{   int v;
    int ** e;
};
AMGraph mkGraph();
vector<int> degreeSequence(const AMGraph &g);
int main()
{   int tasks,x,y;
    cin>>tasks;
    for(x=0;x<tasks;x++)
    {   AMGraph g=mkGraph();
        vector<int> a=degreeSequence(g);
        for(y=0;y<a.size();y++)
            cout<<a[y]<<" ";
        cout<<endl;
    }
}
AMGraph mkGraph()
{   int v,e,x,y,p,q;
    cin>>v>>e;
    AMGraph g;
    g.v=v;
    g.e=new int* [v];
    for(x=0;x<v;x++)
        g.e[x]=new int[v];
    for(x=0;x<v;x++)
    for(y=0;y<v;y++)
    {   if(x==y)
            g.e[x][y]=0;
        else
            g.e[x][y]=inf;
    }
    for(x=0;x<e;x++)
    {   cin>>p>>q;
        g.e[p][q]=g.e[q][p]=1;
    }
    return g;
}
vector<int> degreeSequence(const AMGraph &g)
{   vector<int> list;
    int x,y,s;
    for(x=0;x<g.v;x++)
    {   s=0;
        for(y=0;y<g.v;y++)
            if(g.e[x][y]==1)
                s++;
        list.push_back(s);
    }
    sort(list.rbegin(),list.rend());
	return list;
}