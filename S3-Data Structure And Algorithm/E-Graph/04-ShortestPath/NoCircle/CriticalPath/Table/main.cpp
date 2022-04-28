#include<vector>
#include<iostream>
#include<fstream>
#include<stack>
#include "Critical.h"
using namespace std;
int main()
{   int v,x,y,l,w,next;
    ifstream fin("test.txt");
    fin>>v;
    Graph g(2*v+2);
    for(x=0;x<v;x++)
    {   g.AddEdge(2*v,x,0);
        g.AddEdge(x+v,2*v+1,0);
        fin>>w>>l;
        g.AddEdge(x,x+v,w);
        for(y=0;y<l;y++)
        {   fin>>next;
            g.AddEdge(x+v,next,0);
        }
    }
    g.PrintList();
    vector<pair<int,int>> cpm=g.Critical();
    stack<int> st;
    for(x=0;x<v;x++)
    {   for(y=x;y!=2*v;y=cpm[y].first)
            st.push(y);
        cout<<"Start-";
        while(st.size()!=1)
        {   if(st.top()<v)
                cout<<st.top()<<"-";
            st.pop();
        }
        cout<<st.top()<<" Weight:"<<cpm[x].second<<endl;
        st.pop();  
    }
    for(y=2*v+1;y!=2*v;y=cpm[y].first)
        st.push(y);
    cout<<"Start-";
    while(st.size()!=1)
    {   if(st.top()<v)
            cout<<st.top()<<"-";
        st.pop();
    }
    cout<<"Finish Weight:"<<cpm[2*v+1].second<<endl;
    st.pop();  
    return 0;
}