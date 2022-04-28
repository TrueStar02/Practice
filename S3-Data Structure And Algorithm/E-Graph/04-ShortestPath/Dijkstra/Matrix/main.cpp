#include<iostream>
#include<fstream>
#include<stack>
#include "Dijkstra.h"
using namespace std;
int main()
{   Graph<11> g;
    stack<int> st;
    ifstream fin("test.txt");
    int x,y,v,e,a,b,w;
    fin>>v>>e;
    for(x=0;x<e;x++)
    {   fin>>a>>b>>w;
        g.AddEdge(a,b,w);
    }
    g.PrintMatrix();
    vector<pair<int,int>> mst=g.Dijkstra(0);
    for(x=0;x<mst.size();x++)
    {   for(y=x;y!=-1;y=mst[y].first)
            st.push(y);
        while(st.size()!=1)
        {   cout<<st.top()<<"-";
            st.pop();
        }
        cout<<st.top()<<" Weight:"<<mst[x].second<<endl;
        st.pop();   
    }
    return 0;
}
