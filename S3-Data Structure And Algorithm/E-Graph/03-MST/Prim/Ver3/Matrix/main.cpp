#include<iostream>
#include<fstream>
#include "Prim.h"
using namespace std;
int main()
{   Graph<8> g;
    ifstream fin("test.txt");
    int x,v,e,a,b,w;
    fin>>v>>e;
    for(x=0;x<e;x++)
    {   fin>>a>>b>>w;
        g.AddEdge(a,b,w);
    }
    g.PrintMatrix();
    vector<pair<int,int>> mst=g.MST();
    for(x=1;x<mst.size();x++)
        cout<<mst[x].first<<" "<<mst[x].second<<endl;
}
